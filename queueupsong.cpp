#include "queueupsong.h"
#include "ui_queueupsong.h"
#include "mainwindow.h"

queueUpSong::queueUpSong(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::queueUpSong)
{
    qDebug() << "Queue Up Song Window opened";
    ui->setupUi(this);

}

queueUpSong::~queueUpSong()
{
    delete ui;
}


void queueUpSong::on_buttonBox_accepted()
{

}


void queueUpSong::on_buttonBox_rejected()
{
    emit closed();
}

