/********************************************************************************
** Form generated from reading UI file 'queueupsong.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUEUEUPSONG_H
#define UI_QUEUEUPSONG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_queueUpSong
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *tableWidget;

    void setupUi(QDialog *queueUpSong)
    {
        if (queueUpSong->objectName().isEmpty())
            queueUpSong->setObjectName(QString::fromUtf8("queueUpSong"));
        queueUpSong->resize(400, 300);
        buttonBox = new QDialogButtonBox(queueUpSong);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 250, 300, 32));
        buttonBox->setLayoutDirection(Qt::LeftToRight);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);
        tableWidget = new QTableWidget(queueUpSong);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(50, 20, 300, 200));

        retranslateUi(queueUpSong);
        QObject::connect(buttonBox, SIGNAL(accepted()), queueUpSong, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), queueUpSong, SLOT(reject()));

        QMetaObject::connectSlotsByName(queueUpSong);
    } // setupUi

    void retranslateUi(QDialog *queueUpSong)
    {
        queueUpSong->setWindowTitle(QCoreApplication::translate("queueUpSong", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class queueUpSong: public Ui_queueUpSong {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUEUEUPSONG_H
