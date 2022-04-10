#include "widget.h"
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStringList>
#include <QTextStream>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

QT_CHARTS_USE_NAMESPACE

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //窗口
    resize(800, 600);
    setWindowTitle("csv_GUI");

    //几个Label
    QLabel * pathname = new QLabel("path:",this);
    pathname->move(50, 20);
    pathname->resize(72,15);

    QLabel * startname = new QLabel("start:",this);
    startname->move(50, 84);
    startname->resize(71,21);

    QLabel * endname = new QLabel("end:",this);
    endname->move(240, 84);
    endname->resize(71,21);

    QLabel * tablename = new QLabel("table:",this);
    tablename->move(50, 130);
    tablename->resize(72,15);

    QLabel * graphname = new QLabel("graph:",this);
    graphname->move(240, 130);
    graphname->resize(72,15);


    //显示文件路径的控件
    QLineEdit * showpath = new QLineEdit(this);
    showpath->move(40, 50);
    showpath->resize(601, 21);

    //选择文件按钮
    QPushButton * choosefile = new QPushButton("choose file", this);
    choosefile->move(650, 50);
    choosefile->resize(101, 20);

    //读入起始行的控件
    QSpinBox * startline = new QSpinBox(this);
    startline->move(180, 80);
    startline->resize(41, 31);
    startline->setRange(1,52);

    //读入结束行的控件
    QSpinBox * endline = new QSpinBox(this);
    endline->move(370, 80);
    endline->resize(41, 31);
    endline->setRange(1,52);

    //更新按钮
    QPushButton * renew = new QPushButton("renew", this);
    renew->move(650, 80);
    renew->resize(101, 31);

    //显示表格的控件
    QTableWidget * table = new QTableWidget(53, 2, this);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->move(30, 150);
    table->resize(191,431);
    table->setLineWidth(50);
    //table->setItem(0, 0, new QTableWidgetItem("week"));
    //table->setItem(0, 1, new QTableWidgetItem("num"));
    table->setColumnWidth(0,70);
    table->setColumnWidth(1,70);

    //显示折线图的控件
    QChartView *chartView = new QChartView(this);
    chartView->move(240,150);
    chartView->resize(511,411);
    QChart *chart = new QChart();

    //坐标轴
    QValueAxis *axisX = new QValueAxis();
    axisX->setRange(0, 53);//设置坐标轴范围
    axisX->setTitleText("week");
    axisX->setTickCount(53);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 200);//设置坐标轴范围
    axisY->setTitleText("num");
    axisY->setTickCount(200);

    //导入文件，存下数据
    bool * flag = new bool;
    *flag = false; //没有选中任何文件

    connect(choosefile, &QPushButton::clicked,[=](){

        QString path = QFileDialog::getOpenFileName(this,"open file","C:\\");
        showpath->setText(path);

        QFile file(path);
        file.open(QIODevice::ReadOnly);
        QStringList eachline;
        eachline.clear();

        QTextStream in(&file);

        int r = 0;
        while(!in.atEnd())
        {
            QString fileLine = in.readLine();
            eachline = fileLine.split(",", QString::SkipEmptyParts);
            alldata.append(eachline[1]);
            r++;
        }

        file.close();

        *flag = true;

    });

    //读入起始行和结束行,更新表格显示和折线图显示
    connect(renew, &QPushButton::clicked,[=](){

        if(!*flag)
        {
            qDebug() << "No legal file path!" << endl;
            return;
        }

        //清空表格与折线图
        table->clear();
        chart->removeAllSeries();
        QLineSeries * series = new QLineSeries();
        series->setName("week-num");
        series->setVisible(true);

        //更新表格，更新折现数据
        startlinenum = startline->value();
        endlinenum = endline->value();

        if(startlinenum > endlinenum)
        {
            qDebug()<<"Illegal range!";
            return;
        }

        table->setItem(0, 0, new QTableWidgetItem("week"));
        table->setItem(0, 1, new QTableWidgetItem("num"));

        int i, j;
        for(i = 1, j = startlinenum; j<=endlinenum; i++, j++)
        {
            table->setItem(i, 0, new QTableWidgetItem(QString::number(j)));
            table->setItem(i, 1, new QTableWidgetItem(alldata[j]));
            series->append(j, alldata[j].toInt());
        }

        //更新折线图
        chart->addSeries(series);//添加系列到QChart上
        chart->createDefaultAxes();
        chartView->setChart(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

    });
}

Widget::~Widget()
{
}

