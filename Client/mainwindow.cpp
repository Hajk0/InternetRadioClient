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
    qDebug() << "Add to queue button pressed.\n";
    string message = this->client.getAvaiableSongs();
    qDebug() << "Avaiable songs: " << message;

    if(!queueUpSongWindow){
        this -> hide();
        queueUpSongWindow = new queueUpSong(nullptr, message);
        //queueUpSongWindow->setAvaibleSongs(message);
        queueUpSongWindow -> setWindowTitle("queue-up song window");
        connect(queueUpSongWindow, &queueUpSong::closed, this, &MainWindow::resumeMainWindowReject);
        connect(queueUpSongWindow, &queueUpSong::accepted, this, &MainWindow::resumeMainWindowAccept);
    }
}


void MainWindow::on_btn_skip_clicked()
{
    qDebug() << "Skip song button clicked";
    this->client.skipSong();
}


void MainWindow::resumeMainWindowReject(){
    qDebug() << "Resumed main window after reject";
    this -> show();
    delete queueUpSongWindow;
    queueUpSongWindow = nullptr;
}


void MainWindow::resumeMainWindowAccept(){
    qDebug() << "Resumed main window after accept";
    this -> show();
    string pom = queueUpSongWindow ->getSongName();
    client.addToQueue(pom);
    delete queueUpSongWindow;
    queueUpSongWindow = nullptr;
}
