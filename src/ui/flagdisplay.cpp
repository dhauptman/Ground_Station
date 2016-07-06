#include "flagdisplay.h"
#include "ui_flagdisplay.h"

FlagDisplay::FlagDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FlagDisplay)
{
    ui->setupUi(this);
}

FlagDisplay::~FlagDisplay()
{
    delete ui;
}
