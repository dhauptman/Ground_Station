#include "datadisplay.h"
#include "ui_datadisplay.h"

//Need to test these
#include "MultiVehicleManager.h"
#include "QGC.h"
#include "UAS.h"
#include "QGCApplication.h"
datadisplay::datadisplay(const QString &title, QAction *action, QWidget *parent) :
    QGCDockWidget(title, action, parent),
    ui(new Ui::datadisplay),
    _activeUAS(NULL),
    _uas(NULL)
{
    ui->setupUi(this);
    connect(qgcApp()->toolbox()->multiVehicleManager(), &MultiVehicleManager::activeVehicleChanged, this, &datadisplay::_activeVehicleChanged);
    _activeVehicleChanged(qgcApp()->toolbox()->multiVehicleManager()->activeVehicle());
    connect(_uas, &UAS::MESSAGEChanged, this, &datadisplay::messageChanged);


    //Testing Dynamic Label
    QLabel* data_label_test = new QLabel("Connect a plane with customMessage to see data");
    QVBoxLayout* vbl = new QVBoxLayout();
    vbl->addWidget(data_label_test);
    this->setLayout(vbl);

}

datadisplay::~datadisplay()
{
    delete ui;
}

void datadisplay::_activeVehicleChanged(Vehicle* vehicle)
{
    if(_activeUAS)
    {
        _activeUAS = NULL;
    }
    if (vehicle)
    {
        _activeUAS = vehicle->uas();

    }
}

void datadisplay::messageChanged(mavlink_message_t message)
{
    switch(message.msgid)
    {
    case MAVLINK_MSG_ID_customMessage:
    {
     mavlink_custommessage_t custom;
     mavlink_msg_custommessage_decode(&message, &custom);

     QString time_usec = QString("time_usec         sec         %1").arg(custom.time_usec);
     QString gps_time  = QString("gps_time         sec         %1").arg(custom.gps_time);
     QString air_velocity = QString("air_velocity         sec         %1").arg(custom.air_velocity);
     QString gps_velocity = QString("gps_velocity         sec         %1").arg(custom.gps_velocity);
     QString alpha_est = QString("alpha_est         sec         %1").arg(custom.alpha_est);
     QString beta_est = QString("beta_est         sec         %1").arg(custom.beta_est);
     QString yaw = QString("yaw         sec         %1").arg(custom.yaw);
     QString pitch = QString("pitch         sec         %1").arg(custom.pitch);
     QString roll = QString("roll         sec         %1").arg(custom.roll);
     QString p = QString("p         sec         %1").arg(custom.p);
     QString q = QString("q         sec         %1").arg(custom.q);
     QString r = QString("r         sec         %1").arg(custom.r);
     QString longitude = QString("longitude         sec         %1").arg(custom.longitude);
     QString latitude = QString("latitude         sec         %1").arg(custom.latitude);
     QString altitude = QString("altitude         sec         %1").arg(custom.altitude);
     QString rc_throttle = QString("rc_throttle         sec         %1").arg(custom.rc_throttle);
     QString rc_aileron = QString("rc_aileron         sec         %1").arg(custom.rc_aileron);
     QString rc_elevator = QString("rc_elevator         sec         %1").arg(custom.rc_elevator);
     QString rc_rudder = QString("rc_rudder         sec         %1").arg(custom.rc_rudder);
     QString autopilot_throttle = QString("autopilot_throttle         sec         %1").arg(custom.autopilot_throttle);
     QString autopilot_aileron = QString("autopilot_aileron         sec         %1").arg(custom.autopilot_aileron);
     QString autopilot_elevator = QString("autopilot_elevator         sec         %1").arg(custom.autopilot_elevator);
     QString autopilot_rudder = QString("autopilot_rudder         sec         %1").arg(custom.autopilot_rudder);
     QString distance_to_waypoint = QString("distance_to_waypoint         sec         %1").arg(custom.distance_to_waypoint);
     QString waypoint_index = QString("waypoint_index         sec         %1").arg(custom.waypoint_index);
     QString battery_voltage = QString("battery_voltage         sec         %1").arg(custom.battery_voltage);
     QString total_flight_time = QString("total_flight_time         sec         %1").arg(custom.total_flight_time);
     QString pressure_altitude = QString("pressure_altitude         sec         %1").arg(custom.pressure_altitude);
     QString eph = QString("eph         sec         %1").arg(custom.eph);
     QString epv = QString("epv         sec         %1").arg(custom.epv);
     QString cog = QString("cog         sec         %1").arg(custom.cog);
     QString ann_status_flag = QString("ann_status_flag         sec         %1").arg(custom.ann_status_flag);
     QLabel* time_usec_label = new QLabel(time_usec);
     QLabel* gps_time_label = new QLabel(gps_time);
     QLabel* air_velocity_label = new QLabel(air_velocity);
     QLabel* gps_velocity_label = new QLabel(gps_velocity);
     QLabel* alpha_est_label = new QLabel(alpha_est);
     QLabel* beta_est_label = new QLabel(beta_est);
     QLabel* yaw_label = new QLabel(yaw);
     QLabel* pitch_label = new QLabel(pitch);
     QLabel* roll_label = new QLabel(roll);
     QLabel* p_label = new QLabel(p);
     QLabel* q_label = new QLabel(q);
     QLabel* r_label = new QLabel(r);
     QLabel* longitude_label = new QLabel(longitude);
     QLabel* latitude_label = new QLabel(latitude);
     QLabel* altitude_label = new QLabel(altitude);
     QLabel* rc_throttle_label = new QLabel(rc_throttle);
     QLabel* rc_aileron_label = new QLabel(rc_aileron);
     QLabel* rc_elevator_label = new QLabel(rc_elevator);
     QLabel* rc_rudder_label = new QLabel(rc_rudder);
     QLabel* autopilot_throttle_label = new QLabel(autopilot_throttle);
     QLabel* autopilot_aileron_label = new QLabel(autopilot_aileron);
     QLabel* autopilot_elevator_label = new QLabel(autopilot_elevator);
     QLabel* autopilot_rudder_label = new QLabel(autopilot_rudder);
     QLabel* distance_to_waypoint_label = new QLabel(distance_to_waypoint);
     QLabel* waypoint_index_label = new QLabel(waypoint_index);
     QLabel* battery_voltage_label = new QLabel(battery_voltage);
     QLabel* total_flight_time_label = new QLabel(total_flight_time);
     QLabel* pressure_altitude_label = new QLabel(pressure_altitude);
     QLabel* eph_label = new QLabel(eph);
     QLabel* epv_label = new QLabel(epv);
     QLabel* cog_label = new QLabel(cog);
     QLabel* ann_status_flag_label = new QLabel(ann_status_flag);
     QVBoxLayout* customLayout = new QVBoxLayout();
     customLayout->addWidget(time_usec_label);
     customLayout->addWidget(gps_time_label);
     customLayout->addWidget(air_velocity_label);
     customLayout->addWidget(gps_velocity_label);
     customLayout->addWidget(alpha_est_label);
     customLayout->addWidget(beta_est_label);
     customLayout->addWidget(yaw_label);
     customLayout->addWidget(pitch_label);
     customLayout->addWidget(roll_label);
     customLayout->addWidget(p_label);
     customLayout->addWidget(q_label);
     customLayout->addWidget(r_label);
     customLayout->addWidget(longitude_label);
     customLayout->addWidget(latitude_label);
     customLayout->addWidget(altitude_label);
     customLayout->addWidget(rc_throttle_label);
     customLayout->addWidget(rc_aileron_label);
     customLayout->addWidget(rc_elevator_label);
     customLayout->addWidget(rc_rudder_label);
     customLayout->addWidget(autopilot_throttle_label);
     customLayout->addWidget(autopilot_aileron_label);
     customLayout->addWidget(autopilot_elevator_label);
     customLayout->addWidget(autopilot_rudder_label);
     customLayout->addWidget(distance_to_waypoint_label);
     customLayout->addWidget(waypoint_index_label);
     customLayout->addWidget(battery_voltage_label);
     customLayout->addWidget(total_flight_time_label);
     customLayout->addWidget(pressure_altitude_label);
     customLayout->addWidget(eph_label);
     customLayout->addWidget(epv_label);
     customLayout->addWidget(cog_label);
     customLayout->addWidget(ann_status_flag_label);
     this->setLayout(customLayout);

    }
    break;
    case MAVLINK_MSG_ID_QUAD_MESSAGE:
    {
    }
    break;
    }
}
