#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "client.h"
#include "stream.h"

#include <QDebug>
#include <thread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_connect_clicked()
{
    qDebug() << "Connect/Disconnect button clicked";
    if (this->connected == 0) {
        client = Client();
        stream = Stream();

        std::thread streamThread = std::thread(&Stream::connectToStream, std::ref(stream));
        streamThread.detach();
        client.connectToServer();
        //std::thread clientThread = std::thread(&Client::connectToServer, std::ref(client));
        //clientThread.detach();

        this->connected = true;
    } else {
        client.disconnectFromServer();
        this->connected = false;
    }
}



void MainWindow::on_btn_add_queue_clicked()
{
    qDebug() << "Add to queue button clicked";
    std::string songName = MainWindow::ui->fieldQueueSongName->text().toStdString();
    qDebug() << songName;
    client.addToQueue(songName);
}


void MainWindow::on_btn_skip_clicked()
{
    qDebug() << "Skip song button clicked";
    this->client.skipSong();
}
