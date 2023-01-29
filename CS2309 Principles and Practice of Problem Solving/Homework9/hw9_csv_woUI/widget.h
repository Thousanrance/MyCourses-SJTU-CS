#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    int startlinenum = 0;
    int endlinenum = 0;
    QStringList alldata;
};
#endif // WIDGET_H
