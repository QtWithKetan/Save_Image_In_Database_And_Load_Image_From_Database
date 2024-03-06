/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_Browse_Image;
    QLabel *lbl_Image_Browse;
    QPushButton *pushButton_Display_From_Database;
    QTableWidget *tableWidget_Image_LIst_From_Database;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1003, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_Browse_Image = new QPushButton(centralwidget);
        pushButton_Browse_Image->setObjectName(QString::fromUtf8("pushButton_Browse_Image"));
        pushButton_Browse_Image->setGeometry(QRect(20, 20, 191, 61));
        lbl_Image_Browse = new QLabel(centralwidget);
        lbl_Image_Browse->setObjectName(QString::fromUtf8("lbl_Image_Browse"));
        lbl_Image_Browse->setGeometry(QRect(20, 100, 471, 441));
        lbl_Image_Browse->setFrameShape(QFrame::Panel);
        lbl_Image_Browse->setScaledContents(true);
        pushButton_Display_From_Database = new QPushButton(centralwidget);
        pushButton_Display_From_Database->setObjectName(QString::fromUtf8("pushButton_Display_From_Database"));
        pushButton_Display_From_Database->setGeometry(QRect(240, 20, 191, 61));
        tableWidget_Image_LIst_From_Database = new QTableWidget(centralwidget);
        if (tableWidget_Image_LIst_From_Database->columnCount() < 2)
            tableWidget_Image_LIst_From_Database->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_Image_LIst_From_Database->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_Image_LIst_From_Database->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_Image_LIst_From_Database->setObjectName(QString::fromUtf8("tableWidget_Image_LIst_From_Database"));
        tableWidget_Image_LIst_From_Database->setGeometry(QRect(500, 100, 491, 451));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        tableWidget_Image_LIst_From_Database->setFont(font);
        tableWidget_Image_LIst_From_Database->horizontalHeader()->setDefaultSectionSize(250);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1003, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_Browse_Image->setText(QCoreApplication::translate("MainWindow", "Browse Image", nullptr));
        lbl_Image_Browse->setText(QString());
        pushButton_Display_From_Database->setText(QCoreApplication::translate("MainWindow", "Display From Database", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Image_LIst_From_Database->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Image Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Image_LIst_From_Database->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
