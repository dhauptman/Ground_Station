#ifndef FLAGDISPLAY_H
#define FLAGDISPLAY_H

#include <QWidget>

namespace Ui {
class FlagDisplay;
}

class FlagDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit FlagDisplay(QWidget *parent = 0);
    ~FlagDisplay();

private:
    Ui::FlagDisplay *ui;
};

#endif // FLAGDISPLAY_H
