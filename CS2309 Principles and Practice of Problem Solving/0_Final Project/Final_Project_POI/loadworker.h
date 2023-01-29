#ifndef LOADWORKER_H
#define LOADWORKER_H

#include <QObject>
#include <QFile>

class LoadWorker : public QObject
{
    Q_OBJECT
public:
    explicit LoadWorker(QObject *parent = nullptr, QFile * originfile = nullptr);
    void doloadwork();

signals:
    void loadprogress(int percent); //用于同步进度条进度
    void loadover();

private:
    QFile * csvfile;

};

#endif // LOADWORKER_H
