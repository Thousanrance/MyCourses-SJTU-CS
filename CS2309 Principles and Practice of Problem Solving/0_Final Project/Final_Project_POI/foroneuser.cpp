#include "foroneuser.h"
#include "ui_foroneuser.h"
#include "workerforoneuser.h"
#include <QDebug>
#include <QThread>
#include <QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QVector>
#include <QPoint>
#include <QStringList>
#include <QString>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

QT_CHARTS_USE_NAMESPACE

ForOneUser::ForOneUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ForOneUser)
{
    ui->setupUi(this);

    //获取参数
    connect(ui->ok, &QPushButton::clicked, this, [=](){

        oneuser = ui->oneuserid->value();
        starttime = ui->stime->dateTime();
        qDebug() << starttime <<"刚从ui得到";
        endtime = ui->etime->dateTime();
    });

    //创建条形图
    QChart * barchart = new QChart();

    //多线程实现底层数据分析
    QThread * oneuserthread = new QThread;
    Workerforoneuser * workerforoneuser = new Workerforoneuser;

    connect(ui->show, &QPushButton::clicked, this, [=](){

        qDebug() << starttime <<"赋值前";
        workerforoneuser->oneuser = oneuser;
        workerforoneuser->stime = starttime;
        workerforoneuser->etime = endtime;
        workerforoneuser->moveToThread(oneuserthread);
        oneuserthread->start();
    });
    connect(oneuserthread, &QThread::started, workerforoneuser, &Workerforoneuser::dowkfoneusr);
    connect(workerforoneuser, &Workerforoneuser::wkfoneusrover, oneuserthread, &QThread::quit);
    connect(oneuserthread, &QThread::finished, workerforoneuser, &Workerforoneuser::deleteLater);
    connect(workerforoneuser, &Workerforoneuser::oneusrinfo, this, [=](QVector<QPoint> popular){

        //清空
        barchart->removeAllSeries();

        //创建数据集
        QBarSet * setpopular = new QBarSet("times");
        int ten = popular.size();
        //qDebug() << "传出来了：" << ten ;
        //qDebug() << "最大次数" << popular[0].y();
        QStringList tenpoi;

        //获取横坐标标签与纵坐标数据
        for(int i = 0; i < ten; i++)
        {
            setpopular->append(popular[i].y());
            tenpoi << QString::number(popular[i].x());
        }

        //设置坐标轴
        QBarCategoryAxis * axisX = new QBarCategoryAxis();
        axisX->append(tenpoi);
        QValueAxis * axisY = new QValueAxis;
        //barchart->createDefaultAxes();
        barchart->addAxis(axisX, Qt::AlignBottom);
        barchart->addAxis(axisY, Qt::AlignLeft);
        axisX->setTitleText("location_id");
        axisY->setTitleText("times");
        axisY->setRange(0, popular[0].y());

        //添加到表，并展示
        QBarSeries * series = new QBarSeries();
        series->append(setpopular);
        ui->histogramView->setChart(barchart);
        ui->histogramView->setRenderHint(QPainter::Antialiasing);
        barchart->addSeries(series);
        barchart->setVisible(true);

    });

}

ForOneUser::~ForOneUser()
{
    delete ui;
}
