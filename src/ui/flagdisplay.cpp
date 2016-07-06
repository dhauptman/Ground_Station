#include "flagdisplay.h"
#include "ui_flagdisplay.h"
#include "QPalette"

//Need to test these
#include "MultiVehicleManager.h"
#include "QGC.h"
#include "UAS.h"
#include "QGCApplication.h"


FlagDisplay::FlagDisplay(const QString& title, QAction* action, QWidget *parent) :
    QGCDockWidget(title, action, parent),
    ui(new Ui::FlagDisplay),
    _activeUAS(NULL),
    _uas(NULL)

{
    ui->setupUi(this);
    connect(qgcApp()->toolbox()->multiVehicleManager(), &MultiVehicleManager::activeVehicleChanged, this, &FlagDisplay::_activeVehicleChanged);
    _activeVehicleChanged(qgcApp()->toolbox()->multiVehicleManager()->activeVehicle());
    connect(_uas, &UAS::ARDUINOFlagChanged, this, &FlagDisplay::arduinoFlagChange);
    connect(_uas, &UAS::GPSFlagChanged, this, &FlagDisplay::gpsFlagChange);
    ui->gps_flag->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->arduino_flag->setStyleSheet("QLabel { background-color : red; color : black; }");

}

FlagDisplay::~FlagDisplay()
{
    delete ui;
}

void FlagDisplay::gpsFlagChange(quint8 val)
{
    switch(val)
    {
    case 0:
        ui->gps_flag->setStyleSheet("QLabel { background-color : red; color : black; }");
        break;
    case 1:
        ui->gps_flag->setStyleSheet("QLabel { background-color : green; color : black; }");
        break;
    default:
        break;
    }

}

void FlagDisplay::arduinoFlagChange(quint8 val)
{
    switch(val)
    {
    case 0:
        ui->arduino_flag->setStyleSheet("QLabel { background-color : red; color : black; }");
        break;
    case 1:
        ui->arduino_flag->setStyleSheet("QLabel { background-color : green; color : black; }");
        break;
    default:
        break;
    }
}
void FlagDisplay::_activeVehicleChanged(Vehicle* vehicle)
{
    if(_activeUAS)
    {
        disconnect(static_cast<UAS*>(_activeUAS), &UAS::ARDUINOFlagChanged, this, &FlagDisplay::arduinoFlagChange);
        disconnect(static_cast<UAS*>(_activeUAS), &UAS::GPSFlagChanged, this, &FlagDisplay::gpsFlagChange);
        _activeUAS = NULL;
    }
    if (vehicle)
    {
        _activeUAS = vehicle->uas();
        connect(static_cast<UAS*>(_activeUAS), &UAS::ARDUINOFlagChanged, this, &FlagDisplay::arduinoFlagChange);
        connect(static_cast<UAS*>(_activeUAS), &UAS::GPSFlagChanged, this, &FlagDisplay::gpsFlagChange);

    }
}
