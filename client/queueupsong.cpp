#include "queueupsong.h"
#include "ui_queueupsong.h"
#include "mainwindow.h"

queueUpSong::queueUpSong(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::queueUpSong)
{
    qDebug() << "Queue Up Song Window opened";
    ui->setupUi(this);
    this->show();

    tableWidget = new QTableWidget(this);

    QStringList header = {"Song"};
    //QStringList songNames= {"1", "2", "3", "4", "5", "6", "7", "8"};
    availableSongsVector = {"1", "2", "3", "4", "5", "6", "7", "8"};
    int numRows = availableSongsVector.size();
    int numCols = 1;

    ui -> tableWidget -> setRowCount(numRows);
    ui -> tableWidget -> setColumnCount(numCols);
    ui -> tableWidget -> setHorizontalHeaderLabels(header);

    for (int row = 0; row < numRows; row++){
        QTableWidgetItem *item = new QTableWidgetItem();
        item -> setText(availableSongsVector[row]);
        ui -> tableWidget -> setItem(row, 0, item);
    }
    int columnWidth = 300;
    ui -> tableWidget -> setColumnWidth(0, columnWidth);
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

void queueUpSong::reject ()
{
    emit closed();
}
