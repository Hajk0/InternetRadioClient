#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "client.h"
#include "stream.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_connect_clicked();

    void on_btn_add_queue_clicked();

    void on_btn_skip_clicked();

private:
    Ui::MainWindow *ui;
    bool connected = false;
    Client client;
    Stream stream;

};
#endif // MAINWINDOW_H
