#include "foronepoi.h"
#include "ui_foronepoi.h"
#include "workerforonepoi.h"
#include <QDebug>
#include <QThread>
#include <QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QString>

QT_CHARTS_USE_NAMESPACE

ForOnePOI::ForOnePOI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ForOnePOI)
{
    ui->setupUi(this);

    //获取参数
    connect(ui->ok, &QPushButton::clicked, this, [=](){

        onepoi = ui->poiid->value();
        sday = ui->startday->date();
        //qDebug() << starttime <<"刚从ui得到";
        eday = ui->endday->date();
    });

    //创建线图
    QChart * linechart = new QChart();

    //多线程实现底层数据分析
    QThread * onepoithread = new QThread;
    Workerforonepoi * workerforonepoi = new Workerforonepoi;

    connect(ui->show, &QPushButton::clicked, this, [=](){

        qDebug() << sday <<"赋值前";
        workerforonepoi->onepoi = onepoi;
        workerforonepoi->sday = sday;
        workerforonepoi->eday = eday;
        workerforonepoi->moveToThread(onepoithread);
        onepoithread->start();
    });
    connect(onepoithread, &QThread::started, workerforonepoi, &Workerforonepoi::dowkforonepoi);
    connect(workerforonepoi, &Workerforonepoi::wkforonepoiover, onepoithread, &QThread::quit);
    connect(onepoithread, &QThread::finished, workerforonepoi, &Workerforonepoi::deleteLater);
    connect(workerforonepoi, &Workerforonepoi::onepoiinfo, this, [=](QMap<QDate, int> DAU){

        //清空
        linechart->removeAllSeries();

        //绘制曲线
        QSplineSeries *  spseries = new QSplineSeries();
        QLineSeries *  series = new QLineSeries();

        //获取纵坐标数据
        //线图无法显示文字横坐标，尝试过在条形图上方显示，失败
        QMap<QDate, int>::const_iterator i;
        //double xaxis; //将日期转换成小数显示，不行，图很怪
        int j = 1; //第几天
        int total = 0; //总人次
        int max = 0;   //最大日活
        for(i = DAU.constBegin(); i != DAU.constEnd(); ++i)
        {
            //xaxis = i.key().month() + i.key().day()*0.01;
            series->append(j,i.value());
            spseries->append(j,i.value());
            qDebug() << i.key().toString("yyyy/MM/dd");
            //qDebug() << xaxis;
            qDebug() << i.value();
            total += i.value();
            if(i.value() > max)
            {
                max = i.value();
            }
            j++;
        }

        //添加序列到图上
        if(DAU.size()<10)
        {
            //如果数据点过少，则绘制插值平滑后的曲线
            linechart->addSeries(spseries);
            spseries->setName("DAU");
        }
        else
        {
            linechart->addSeries(series);
            series->setName("DAU");
        }
        //设置坐标轴
        linechart->createDefaultAxes();


        //显示图和一些数据
        ui->total->setText("Total:" + QString::number(total));
        ui->max->setText("Max:" + QString::number(max));
        ui->linechartView->setChart(linechart);
        ui->linechartView->setRenderHint(QPainter::Antialiasing);
    });
}

ForOnePOI::~ForOnePOI()
{
    delete ui;
}
