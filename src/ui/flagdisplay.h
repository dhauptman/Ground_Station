#ifndef FLAGDISPLAY_H
#define FLAGDISPLAY_H

#include "QGCDockWidget.h"
#include "UASInterface.h"
#include "Vehicle.h"
#include "ui_flagdisplay.h"


class UAS;

namespace Ui {
class FlagDisplay;
}

class FlagDisplay : public QGCDockWidget
{
    Q_OBJECT

public:
     FlagDisplay(const QString& title, QAction* action, QWidget *parent = 0);
    ~FlagDisplay();

public slots:
    void gpsFlagChange(quint8 val);
    void arduinoFlagChange(quint8 val);
    void _activeVehicleChanged(Vehicle* vehicle);

private:
    Ui::FlagDisplay *ui;
    UASInterface*   _activeUAS;
    UAS* _uas;
};

#endif // FLAGDISPLAY_H
