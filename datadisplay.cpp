#include "datadisplay.h"

//Need to test these
#include "MultiVehicleManager.h"
//#include "QGC.h"
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
    //connect(_uas, &UAS::MESSAGEChanged, this, &datadisplay::messageChanged);


    //Testing Dynamic Label
    //QLabel* data_label_test = new QLabel("Connect a plane with customMessage to see data");
    //QVBoxLayout* vbl = new QVBoxLayout();
    //vbl->addWidget(data_label_test);
    //this->setLayout(vbl);

}

datadisplay::~datadisplay()
{
    delete ui;
    //Delete Layout
    //qDeleteAll(customLayout->children());
    //delete customLayout;
}

void datadisplay::_activeVehicleChanged(Vehicle* vehicle)
{
    if(_activeUAS)
    {
        disconnect(static_cast<UAS*>(_activeUAS), &UAS::MESSAGEChanged, this, &datadisplay::messageChanged);
        _activeUAS = NULL;
    }
    if (vehicle)
    {
        _activeUAS = vehicle->uas();
        connect(static_cast<UAS*>(_activeUAS), &UAS::MESSAGEChanged, this, &datadisplay::messageChanged);

    }
}

void datadisplay::messageChanged(mavlink_message_t message)
{
    switch(message.msgid)
    {
    case MAVLINK_MSG_ID_customMessage:
    {
     _setLayout(message.msgid);
     firstLayout = 0;
     mavlink_custommessage_t custom;
     mavlink_msg_custommessage_decode(&message, &custom);
     //Setting the labels
     //Aarons Orders
     altitude_label->setText(altitude.arg(custom.altitude));
     air_velocity_label->setText(air_velocity.arg(custom.air_velocity));
     gps_velocity_label->setText(gps_velocity.arg(custom.gps_velocity));
     alpha_est_label->setText(alpha_est.arg(custom.alpha_est));
     beta_est_label->setText(beta_est.arg(custom.beta_est));
     autopilot_throttle_label->setText(autopilot_throttle.arg(custom.autopilot_throttle));
     autopilot_aileron_label->setText(autopilot_aileron.arg(custom.autopilot_aileron));
     autopilot_elevator_label->setText(autopilot_elevator.arg(custom.autopilot_elevator));
     autopilot_rudder_label->setText(autopilot_rudder.arg(custom.autopilot_rudder));
     //
     time_usec_label->setText(time_usec.arg(custom.time_usec));
     gps_time_label->setText(gps_time.arg(custom.gps_time));
     yaw_label->setText(yaw.arg(custom.yaw));
     pitch_label->setText(pitch.arg(custom.pitch));
     roll_label->setText(roll.arg(custom.roll));
     p_label->setText(p.arg(custom.p));
     q_label->setText(q.arg(custom.q));
     r_label->setText(r.arg(custom.r));
     longitude_label->setText(longitude.arg(custom.longitude));
     latitude_label->setText(latitude.arg(custom.latitude));
     rc_throttle_label->setText(rc_throttle.arg(custom.rc_throttle));
     rc_aileron_label->setText(rc_aileron.arg(custom.rc_aileron));
     rc_elevator_label->setText(rc_elevator.arg(custom.rc_elevator));
     rc_rudder_label->setText(rc_rudder.arg(custom.rc_rudder));
     distance_to_waypoint_label->setText(distance_to_waypoint.arg(custom.distance_to_waypoint));
     waypoint_index_label->setText(waypoint_index.arg(custom.waypoint_index));
     battery_voltage_label->setText(battery_voltage.arg(custom.battery_voltage));
     total_flight_time_label->setText(total_flight_time.arg(custom.total_flight_time));
     pressure_altitude_label->setText(pressure_altitude.arg(custom.pressure_altitude));
     eph_label->setText(eph.arg(custom.eph));
     epv_label->setText(epv.arg(custom.epv));
     cog_label->setText(cog.arg(custom.cog));
     ann_status_flag_label->setText(ann_status_flag.arg(custom.ann_status_flag));

    }
    break;
    case MAVLINK_MSG_ID_QUAD_MESSAGE:
    {
    }
    break;
    }
}

void datadisplay::_setLayout(uint8_t messageId)
{
    switch(messageId)
    {
    case MAVLINK_MSG_ID_customMessage:
    {
        if(firstLayout == 1)
        {
            //Set layout based on message
            customLayout->addWidget(title_label);
            //Aarons Orders
            customLayout->addWidget(altitude_label);
            customLayout->addWidget(air_velocity_label);
            customLayout->addWidget(gps_velocity_label);
            customLayout->addWidget(alpha_est_label);
            customLayout->addWidget(beta_est_label);
            customLayout->addWidget(autopilot_throttle_label);
            customLayout->addWidget(autopilot_aileron_label);
            customLayout->addWidget(autopilot_elevator_label);
            customLayout->addWidget(autopilot_rudder_label);
            //
            customLayout->addWidget(time_usec_label);
            customLayout->addWidget(gps_time_label);
            customLayout->addWidget(yaw_label);
            customLayout->addWidget(pitch_label);
            customLayout->addWidget(roll_label);
            customLayout->addWidget(p_label);
            customLayout->addWidget(q_label);
            customLayout->addWidget(r_label);
            customLayout->addWidget(longitude_label);
            customLayout->addWidget(latitude_label);
            customLayout->addWidget(rc_throttle_label);
            customLayout->addWidget(rc_aileron_label);
            customLayout->addWidget(rc_elevator_label);
            customLayout->addWidget(rc_rudder_label);
            customLayout->addWidget(distance_to_waypoint_label);
            customLayout->addWidget(waypoint_index_label);
            customLayout->addWidget(battery_voltage_label);
            customLayout->addWidget(total_flight_time_label);
            customLayout->addWidget(pressure_altitude_label);
            customLayout->addWidget(eph_label);
            customLayout->addWidget(epv_label);
            customLayout->addWidget(cog_label);
            customLayout->addWidget(ann_status_flag_label);
            //Set the layout
            this->setLayout(customLayout);

        }
    }
    }
}

//TODO:Make the display capable of switching layouts on the fly
//     Will probably only need to delete all the labels and reset
//     with the new ones
