#include "fortwopoi.h"
#include "ui_fortwopoi.h"
#include "workerfortwopoi.h"
#include <QDebug>
#include <QThread>
#include <QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QString>

QT_CHARTS_USE_NAMESPACE

ForTwoPOI::ForTwoPOI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ForTwoPOI)
{
    ui->setupUi(this);
    //获取参数
    connect(ui->ok, &QPushButton::clicked, this, [=](){

        poi1 = ui->poi1->value();
        poi2 = ui->poi2->value();
        sday = ui->dayfrom->date();
        eday = ui->dayto->date();
    });

    //创建线图
    QChart * linechart = new QChart();

    //多线程实现底层数据分析
    QThread * twopoithread = new QThread;
    Workerfortwopoi * workerfortwopoi = new Workerfortwopoi;

    connect(ui->show, &QPushButton::clicked, this, [=](){

        //qDebug() << sday <<"赋值前";
        workerfortwopoi->poi1 = poi1;
        workerfortwopoi->poi2 = poi2;
        workerfortwopoi->sday = sday;
        workerfortwopoi->eday = eday;
        workerfortwopoi->moveToThread(twopoithread);
        twopoithread->start();
    });

    connect(twopoithread, &QThread::started, workerfortwopoi, &Workerfortwopoi::dowkfortwopoi);
    connect(workerfortwopoi, &Workerfortwopoi::wkfortwopoiover, twopoithread, &QThread::quit);
    connect(twopoithread, &QThread::finished, workerfortwopoi, &Workerfortwopoi::deleteLater);
    connect(workerfortwopoi, &Workerfortwopoi::twopoiinfo, this, [=](QMap<QDate, int> DAU1, QMap<QDate, int> DAU2){

        //清空
        linechart->removeAllSeries();

        //绘制折线
        QLineSeries *  series1 = new QLineSeries();
        QLineSeries *  series2 = new QLineSeries();
        QSplineSeries *  spseries1 = new QSplineSeries();
        QSplineSeries *  spseries2 = new QSplineSeries();
        series2->setColor(Qt::red);
        spseries2->setColor(Qt::red);


        //获取纵坐标数据
        //线图无法显示文字横坐标，尝试过在条形图上方显示，但是后果是横坐标没了，而且整不回来了
        QMap<QDate, int>::const_iterator i;
        int j1 = 1;
        int total1 = 0; //总人次
        int max1 = 0;   //最大日活
        for(i = DAU1.constBegin(); i != DAU1.constEnd(); ++i)
        {
            series1->append(j1,i.value());
            spseries1->append(j1,i.value());
            qDebug() << i.key().toString("yyyy/MM/dd");
            qDebug() << i.value();
            total1 += i.value();
            if(i.value() > max1)
            {
                max1 = i.value();
            }
            j1++;
        }

        int j2 = 1;
        int total2 = 0; //总人次
        int max2 = 0;   //最大日活
        for(i = DAU2.constBegin(); i != DAU2.constEnd(); ++i)
        {
            series2->append(j2,i.value());
            spseries2->append(j2,i.value());
            qDebug() << i.key().toString("yyyy/MM/dd");
            qDebug() << i.value();
            total2 += i.value();
            if(i.value() > max2)
            {
                max2 = i.value();
            }
            j2++;
        }

        //添加到表，并展示
        ui->total1->setText("Total 1:" + QString::number(total1));
        ui->max1->setText("Max 1:" + QString::number(max1));
        ui->total2->setText("Total 2:" + QString::number(total2));
        ui->max2->setText("Max 2:" + QString::number(max2));

        if(DAU1.size()<10)
        {
            linechart->addSeries(spseries1);
            spseries1->setName("DAU 1");
        }
        else
        {
            linechart->addSeries(series1);
            series1->setName("DAU 1");
        }
        if(DAU2.size()<10)
        {
            linechart->addSeries(spseries2);
            spseries2->setName("DAU 2");
        }
        else
        {
            linechart->addSeries(series2);
            series2->setName("DAU 2");
        }

        //设置坐标轴
        linechart->createDefaultAxes();
        ui->linechartView->setChart(linechart);
        ui->linechartView->setRenderHint(QPainter::Antialiasing);
    });
}

ForTwoPOI::~ForTwoPOI()
{
    delete ui;
}
