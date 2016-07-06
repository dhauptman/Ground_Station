#ifndef DATADISPLAY_H
#define DATADISPLAY_H

#include "QGCDockWidget.h"
#include "UASInterface.h"
#include "Vehicle.h"
#include "ui_datadisplay.h"



class UAS;

namespace Ui {
class datadisplay;
}

class datadisplay : public QGCDockWidget
{
    Q_OBJECT

public:
    explicit datadisplay(const QString& title, QAction* action, QWidget *parent = 0);
    ~datadisplay();
public slots:
    void _activeVehicleChanged(Vehicle* vehicle);
    void messageChanged(mavlink_message_t message);

private:
    Ui::datadisplay *ui;
    UASInterface*   _activeUAS;
    UAS* _uas;
};

#endif // DATADISPLAY_H
