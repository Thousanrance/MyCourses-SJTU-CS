#include "fortwousers.h"
#include "ui_fortwousers.h"
#include "workerfortwousers.h"
#include <QDebug>
#include <QThread>
#include <QVector>
#include <QPoint>
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>

ForTwoUsers::ForTwoUsers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ForTwoUsers)
{
    ui->setupUi(this);
    //获取参数
    connect(ui->ok, &QPushButton::clicked, this, [=](){

        user1 = ui->user1->value();
        user2 = ui->user2->value();
        starttime = ui->starttime->dateTime();
        endtime = ui->endtime->dateTime();
    });


    //多线程实现底层数据分析
    QThread * twousersthread = new QThread;
    Workerfortwousers * workerfortwousers = new Workerfortwousers;

    connect(ui->show, &QPushButton::clicked, this, [=](){

        //qDebug() << starttime <<"赋值前";
        workerfortwousers->user1 = user1;
        workerfortwousers->user2 = user2;
        workerfortwousers->stime = starttime;
        workerfortwousers->etime = endtime;
        workerfortwousers->moveToThread(twousersthread);
        twousersthread->start();
    });
    connect(twousersthread, &QThread::started, workerfortwousers, &Workerfortwousers::dowkftwousrs);
    connect(workerfortwousers, &Workerfortwousers::wkftwousrsover, twousersthread, &QThread::quit);
    connect(twousersthread, &QThread::finished, workerfortwousers, &Workerfortwousers::deleteLater);
    connect(workerfortwousers, &Workerfortwousers::twousrsinfo, this, [=](QVector<QPoint> popular1, QVector<QPoint> popular2){

        ui->table->clear();
        ui->table->setItem(0, 0, new QTableWidgetItem("user_id"));
        ui->table->setItem(0, 1, new QTableWidgetItem(QString::number(user1)));
        ui->table->setItem(0, 3, new QTableWidgetItem(QString::number(user2)));
        ui->table->setItem(1, 1, new QTableWidgetItem("poi_id"));
        ui->table->setItem(1, 3, new QTableWidgetItem("poi_id"));
        ui->table->setItem(1, 2, new QTableWidgetItem("times"));
        ui->table->setItem(1, 4, new QTableWidgetItem("times"));

        int ten1 = popular1.size();
        int ten2 = popular2.size();

        for(int i = 0; i < 10; i++)
        {
            ui->table->setItem(i+2, 0, new QTableWidgetItem(QString::number(i+1)));
        }

        for(int i = 0; i < ten1; i++)
        {
            ui->table->setItem(i+2, 1, new QTableWidgetItem(QString::number(popular1[i].x())));
            ui->table->setItem(i+2, 2, new QTableWidgetItem(QString::number(popular1[i].y())));
        }

        for(int i = 0; i < ten2; i++)
        {
            ui->table->setItem(i+2, 3, new QTableWidgetItem(QString::number(popular2[i].x())));
            ui->table->setItem(i+2, 4, new QTableWidgetItem(QString::number(popular2[i].y())));
        }

    });
}

ForTwoUsers::~ForTwoUsers()
{
    delete ui;
}
