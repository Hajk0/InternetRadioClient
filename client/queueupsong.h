#ifndef QUEUEUPSONG_H
#define QUEUEUPSONG_H

#include <QDialog>
#include <vector>
#include <QTableWidget>
#include <QTableWidgetItem>

namespace Ui {
class queueUpSong;
}

class queueUpSong : public QDialog
{
    Q_OBJECT

public:
    explicit queueUpSong(QWidget *parent = nullptr);
    ~queueUpSong();

signals:
    void closed();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void reject();

private:
    Ui::queueUpSong *ui;
    std::vector<QString> availableSongsVector;
    QTableWidget *tableWidget;


};

#endif // QUEUEUPSONG_H
