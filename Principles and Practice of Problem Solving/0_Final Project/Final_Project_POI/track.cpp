#include "track.h"
#include "ui_track.h"
#include "globalvar.h"
#include <QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QSplineSeries>

QT_CHARTS_USE_NAMESPACE

Track::Track(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Track)
{
    ui->setupUi(this);

    //建立表，添加到显示控件
    QChart * trackchart = new QChart;
    ui->trackView->setChart(trackchart);

    //散点序列和光滑曲线序列
    QScatterSeries * user1poi = new QScatterSeries();
    user1poi->setColor(Qt::blue);
    user1poi->setName("user 1");
    user1poi->setMarkerSize(10);
    QScatterSeries * user2poi = new QScatterSeries();
    user2poi->setColor(Qt::red);
    user2poi->setName("user 2");
    user2poi->setMarkerSize(10);

    QSplineSeries * user1track = new QSplineSeries();
    user1track->setColor(Qt::blue);
    user1track->setName("user 1");
    QSplineSeries * user2track = new QSplineSeries();
    user2track->setColor(Qt::red);
    user2track->setName("user 2");


    connect(ui->show, &QPushButton::clicked, this, [=](){

        //获取用户id
        int user1 = ui->user1->value();
        int user2 = ui->user2->value();

        //添加点到序列
        Record tmp;
        double x;
        double y;
        for(int i = v_recfrom; i <= v_recto; i++)
        {
            tmp = interest[i];
            if(user1 == tmp.user_id)
            {
                x = tmp.longitude;
                y = tmp.latitude;
                user1poi->append(x, y);
                user1track->append(x, y);
            }
            if(user2 == tmp.user_id)
            {
                x = tmp.longitude;
                y = tmp.latitude;
                user2poi->append(x, y);
                user2track->append(x, y);
            }
        }

        //添加序列到表
        trackchart->addSeries(user1poi);
        trackchart->addSeries(user1track);
        trackchart->addSeries(user2poi);
        trackchart->addSeries(user2track);
        ui->trackView->setRenderHint(QPainter::Antialiasing);

        trackchart->createDefaultAxes();

    });
}

Track::~Track()
{
    delete ui;
}
