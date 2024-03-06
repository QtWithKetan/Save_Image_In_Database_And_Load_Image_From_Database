#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DB_Connection = QSqlDatabase::addDatabase("QMYSQL");
    DB_Connection.setDatabaseName("qtwithketan");
    DB_Connection.setHostName("127.0.0.1");
    DB_Connection.setPort(3306);
    DB_Connection.setUserName("root");
    DB_Connection.setPassword("Admin@123");
    if (DB_Connection.open())
    {
        qDebug() << "Database is Connected";
    }
    else
    {
        qDebug() << "Database is not connected";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Browse_Image_clicked()
{
    QString ImagePath = QFileDialog::getOpenFileName(this,tr("Select Image"),QCoreApplication::applicationDirPath(),tr("JPG Files (*.jpg)"));
    QPixmap Image(ImagePath);
    QBuffer ImageBufferData;
    if (ImageBufferData.open(QIODevice::ReadWrite))
    {
        Image.save(&ImageBufferData, "JPG");
    }

    QByteArray FinalDataToSave = ImageBufferData.buffer().toBase64();

    QFileInfo FileInfo(ImagePath);
    QString ImageName = FileInfo.fileName();

    QSqlDatabase::database().transaction();
    DB_Connection.open();
    QSqlQuery QuerySaveImage(DB_Connection);
    QuerySaveImage.prepare("INSERT INTO image_list(Image_Name,Image_Data)VALUES(:Image_Name,:Image_Data)");
    QuerySaveImage.bindValue(":Image_Name",ImageName);
    QuerySaveImage.bindValue(":Image_Data",FinalDataToSave);
    QuerySaveImage.exec();
    DB_Connection.close();
    QSqlDatabase::database().commit();

    ui->lbl_Image_Browse->setPixmap(Image);
}


void MainWindow::on_pushButton_Display_From_Database_clicked()
{
    QByteArray ImageDataFromDatabase;
    QPixmap Image;
    QString ImageName;

    DB_Connection.open();
    QSqlQuery QueryGetImage(DB_Connection);
    QueryGetImage.prepare("SELECT * FROM image_list");// Query For Get Last Saved Image From Database.
    if (QueryGetImage.exec())
    {
        ui->tableWidget_Image_LIst_From_Database->setRowCount(QueryGetImage.size());
        int Row_Number = 0;
        while (QueryGetImage.next())
        {
            ImageName = QueryGetImage.value("Image_Name").toString();
            ImageDataFromDatabase = QByteArray::fromBase64(QueryGetImage.value("Image_Data").toByteArray());
            Image.loadFromData(ImageDataFromDatabase,"JPG");

            ui->tableWidget_Image_LIst_From_Database->setItem(Row_Number,0,new QTableWidgetItem(ImageName));

            // Now Let's Display Image properly
            // Now Let's Fit Image in Cell.
            QTableWidgetItem *Image_Item = new QTableWidgetItem();
            Image_Item->setData(Qt::DecorationRole, Image.scaled(100,100));
            ui->tableWidget_Image_LIst_From_Database->setItem(Row_Number,1,Image_Item);
            ui->tableWidget_Image_LIst_From_Database->verticalHeader()->setDefaultSectionSize(30);

            Row_Number = Row_Number + 1;
        }
    }
    DB_Connection.close();
    ui->tableWidget_Image_LIst_From_Database->resizeRowsToContents();

    Image.save(QCoreApplication::applicationDirPath() + "/Image_From_Database.jpg");
}

