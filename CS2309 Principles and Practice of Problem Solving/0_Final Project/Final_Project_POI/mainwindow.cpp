#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "globalvar.h"
#include "loadworker.h"
#include "foroneuser.h"
#include "foronepoi.h"
#include "fortwousers.h"
#include "fortwopoi.h"
#include "track.h"
#include <QDebug>
#include <QThread>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>
#include <QString>
#include <QFileDialog>
#include <QProgressBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //操作数据库
//    interest.setDatabaseName("selected_dataset.db");

//    if(!interest.open())
//    {
//        qDebug() << "Error failed to open" << interest.lastError();
//    }
//    else
//    {
//        qDebug() << "Successfully opened" << endl;
//    }

//    QSqlQuery * query = new QSqlQuery(interest);

//    query->exec("create table POI(user_id INTEGER primary key,"
//               "location_id INTEGER,"
//               "time INTEGER,"
//               "latitude REAL,"
//               "longitude REAL);");

    //选择文件
    QFile * csvfile = new QFile(this);
    connect(ui->actionOpen, &QAction::triggered, this,[=](){

        QString path = QFileDialog::getOpenFileName(this,"open file","C:\\");
        csvfile->setFileName(path);
        ui->pathview->setText(path);

    });

    //更新过滤器参数
    connect(ui->poi_id, &QRadioButton::clicked, this, [=](){
        poiorgps = true;
    });
    connect(ui->poi_gps, &QRadioButton::clicked, this, [=](){
        poiorgps = false;
    });

    connect(ui->ok, &QPushButton::clicked, this, [=](){

        v_recfrom = ui->recfrom->value();
        v_recto = ui->recto->value();
        v_userfrom = ui->userfrom->value();
        v_userto = ui->userto->value();
        if(poiorgps)
        {
            v_poifrom = ui->poifrom->value();
            v_poito = ui->poito->value();
        }
        else
        {
            v_xfrom = ui->xfrom->value();
            v_xto = ui->xto->value();
            v_yfrom = ui->yfrom->value();
            v_yto = ui->yto->value();
        }
        v_timefrom = ui->timefrom->dateTime();
        v_timeto = ui->timeto->dateTime();

    });

    //上传符合条件的数据，多线程实现
    QThread * loadthread = new QThread; //用于上传数据的线程

    LoadWorker * loadworker = new LoadWorker(nullptr, csvfile); //用于上传数据的工具类

    loadworker->moveToThread(loadthread);

    //点下load按钮开始上传数据
    connect(ui->load, &QPushButton::clicked, this, [=](){
        loadthread->start();
    });
    connect(loadthread, &QThread::started, loadworker, &LoadWorker::doloadwork);
    connect(loadworker, &LoadWorker::loadover, loadthread, &QThread::quit);
    connect(loadthread, &QThread::finished, loadworker, &LoadWorker::deleteLater);
    connect(loadworker, &LoadWorker::loadprogress, this, [=](int percent){

        ui->filterprogress->setValue(percent); //进度条进度同步

    });

    //一个用户的时空信息
    connect(ui->action_oneuser, &QAction::triggered, this, [=](){

        ForOneUser * foroneuser = new ForOneUser;
        foroneuser->show();
        //关闭时删除该窗口
        foroneuser->setAttribute(Qt::WA_DeleteOnClose);
    });

    //一个地点的时空信息
    connect(ui->action_onepoi, &QAction::triggered, this, [=](){

        ForOnePOI * foronepoi = new ForOnePOI;
        foronepoi->show();
        //关闭时删除该窗口
        foronepoi->setAttribute(Qt::WA_DeleteOnClose);
    });

    //两个用户的比较信息
    connect(ui->action_twousers, &QAction::triggered, this, [=](){

        ForTwoUsers * fortwousers = new ForTwoUsers;
        fortwousers->show();
        //关闭时删除该窗口
        fortwousers->setAttribute(Qt::WA_DeleteOnClose);
    });

    //两个地点的比较信息
    connect(ui->action_twopoi, &QAction::triggered, this, [=](){

        ForTwoPOI * fortwopoi = new ForTwoPOI;
        fortwopoi->show();
        //关闭时删除该窗口
        fortwopoi->setAttribute(Qt::WA_DeleteOnClose);
    });

    //两个用户的轨迹显示
    connect(ui->actionTrack, &QAction::triggered, this, [=](){

        Track * track = new Track;
        track->show();
        //关闭时删除该窗口
        track->setAttribute(Qt::WA_DeleteOnClose);
    });



}

MainWindow::~MainWindow()
{
    delete ui;
}

