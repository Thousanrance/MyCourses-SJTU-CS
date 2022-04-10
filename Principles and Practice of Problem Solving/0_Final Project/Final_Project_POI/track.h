#ifndef TRACK_H
#define TRACK_H

#include <QWidget>

namespace Ui {
class Track;
}

class Track : public QWidget
{
    Q_OBJECT

public:
    explicit Track(QWidget *parent = nullptr);
    ~Track();

private:
    Ui::Track *ui;
};

#endif // TRACK_H
