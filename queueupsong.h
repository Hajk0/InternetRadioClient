#ifndef QUEUEUPSONG_H
#define QUEUEUPSONG_H

#include <QDialog>
#include <vector>

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

private:
    Ui::queueUpSong *ui;
    queueUpSong *queueUpSongWindow;
    std::vector<std::string> availableSongsVector;

};

#endif // QUEUEUPSONG_H
