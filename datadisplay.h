#ifndef DATADISPLAY_H
#define DATADISPLAY_H

#include "QGCDockWidget.h"
#include "UASInterface.h"
#include "Vehicle.h"
#include "ui_datadisplay.h"

//Need to test these
#include "QLabel"
#include "QVBoxLayout"



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

    void _setLayout(uint8_t messageId);
    bool firstLayout = true;


    //Strings
    QString title =                QString("Measurement                  units        Value");
    //Aarons orders
    QString altitude =             QString("altitude                     m           %1");
    QString air_velocity =         QString("air_velocity                 m/s         %1");
    QString gps_velocity =         QString("gps_velocity                 m/s         %1");
    QString alpha_est =            QString("alpha_est                    deg/s       %1");
    QString beta_est =             QString("beta_est                     deg/s       %1");
    QString autopilot_throttle =   QString("autopilot_throttle           %           %1");
    QString autopilot_aileron =    QString("autopilot_aileron            deg         %1");
    QString autopilot_elevator =   QString("autopilot_elevator           deg         %1");
    QString autopilot_rudder =     QString("autopilot_rudder             deg         %1");
    //
    QString gps_time  =            QString("gps_time                     sec         %1");
    QString time_usec =            QString("time_usec                    sec         %1");
    QString yaw =                  QString("yaw                          deg         %1");
    QString pitch =                QString("pitch                        deg         %1");
    QString roll =                 QString("roll                         deg         %1");
    QString p =                    QString("p                            deg/s       %1");
    QString q =                    QString("q                            deg/s       %1");
    QString r =                    QString("r                            deg/s       %1");
    QString longitude =            QString("longitude                    deg           %1");
    QString latitude =             QString("latitude                     deg           %1");
    QString rc_throttle =          QString("rc_throttle                  us          %1");
    QString rc_aileron =           QString("rc_aileron                   us          %1");
    QString rc_elevator =          QString("rc_elevator                  us          %1");
    QString rc_rudder =            QString("rc_rudder                    us          %1");
    QString distance_to_waypoint = QString("distance_to_waypoint         ft          %1");
    QString waypoint_index =       QString("waypoint_index               N/A         %1");
    QString battery_voltage =      QString("battery_voltage              V           %1");
    QString total_flight_time =    QString("total_flight_time            sec         %1");
    QString pressure_altitude =    QString("pressure_altitude            psf         %1");
    QString eph =                  QString("eph                          N/A         %1");
    QString epv =                  QString("epv                          N/A         %1");
    QString cog =                  QString("cog                          deg         %1");
    QString ann_status_flag =      QString("ann_status_flag              N/A         %1");

    //Labels
    QLabel* title_label = new QLabel();
    //Aarons orders
    QLabel* altitude_label = new QLabel();
    QLabel* air_velocity_label = new QLabel();
    QLabel* gps_velocity_label = new QLabel();
    QLabel* alpha_est_label = new QLabel();
    QLabel* beta_est_label = new QLabel();
    QLabel* autopilot_throttle_label = new QLabel();
    QLabel* autopilot_aileron_label = new QLabel();
    QLabel* autopilot_elevator_label = new QLabel();
    QLabel* autopilot_rudder_label = new QLabel();
    //
    QLabel* time_usec_label = new QLabel();
    QLabel* gps_time_label = new QLabel();
    QLabel* yaw_label = new QLabel();
    QLabel* pitch_label = new QLabel();
    QLabel* roll_label = new QLabel();
    QLabel* p_label = new QLabel();
    QLabel* q_label = new QLabel();
    QLabel* r_label = new QLabel();
    QLabel* longitude_label = new QLabel();
    QLabel* latitude_label = new QLabel();
    QLabel* rc_throttle_label = new QLabel();
    QLabel* rc_aileron_label = new QLabel();
    QLabel* rc_elevator_label = new QLabel();
    QLabel* rc_rudder_label = new QLabel();
    QLabel* distance_to_waypoint_label = new QLabel();
    QLabel* waypoint_index_label = new QLabel();
    QLabel* battery_voltage_label = new QLabel();
    QLabel* total_flight_time_label = new QLabel();
    QLabel* pressure_altitude_label = new QLabel();
    QLabel* eph_label = new QLabel();
    QLabel* epv_label = new QLabel();
    QLabel* cog_label = new QLabel();
    QLabel* ann_status_flag_label = new QLabel();

    //Layout
    QVBoxLayout* customLayout = new QVBoxLayout();
};

#endif // DATADISPLAY_H
