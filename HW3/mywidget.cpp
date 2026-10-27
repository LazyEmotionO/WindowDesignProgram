#include "mywidget.h"
#include "ui_mywidget.h"
#include <QFile>
#include <QDebug>
#include <QFileDialog>
#include <QFileInfo>

//QString mFileName = "C:/Users/user/Desktop/41243260_10_19/ContactBook/output/output.txt";
//QString mFileName = "../../output/output.txt";
QString mFileName = "../../../output/output.csv";

void Write(QString FileName,QString str){
    QFile mFile(FileName);
    //QFileInfo info(FileName);
    //QDir().mkpath(info.absolutePath());

    if(!mFile.open(QFile::WriteOnly | QFile::Text)){
        qDebug()<<"cannot open this file\n";
        qDebug()<<QCoreApplication::applicationDirPath()<<"\n";
        return;
    }
    QTextStream out(&mFile);
    out.setEncoding(QStringConverter::System);
    out<<str;
    mFile.flush();
    mFile.close();
}

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    QStringList ColTotle;
    ui->tableWidget->setColumnCount(4);

    ColTotle<<QStringLiteral("Number")<<QStringLiteral("Class")<<QStringLiteral("Name")<<QStringLiteral("TelePhone");
    ui->tableWidget->setHorizontalHeaderLabels(ColTotle);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_clicked()
{
    QTableWidgetItem *inputRow1,*inputRow2,*inputRow3,*inputRow4;
    inputRow1 = new QTableWidgetItem(QString(ui->lineEdit_2->text()));
    inputRow2 = new QTableWidgetItem(QString(ui->lineEdit_3->text()));
    inputRow3 = new QTableWidgetItem(QString(ui->lineEdit_4->text()));
    inputRow4 = new QTableWidgetItem(QString(ui->lineEdit_5->text()));

    ui->tableWidget->insertRow((ui->tableWidget->rowCount()));

    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,inputRow1);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,inputRow2);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,inputRow3);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,inputRow4);
}


void MyWidget::on_pushButton_2_clicked()
{
    QString saveFile="";
    for(int i=0;i<ui->tableWidget->rowCount();i++){
        for(int j=0;j<ui->tableWidget->columnCount();j++){
            saveFile+=ui->tableWidget->item(i,j)->text()+",";
        }
        saveFile+="\n";
    }
    Write(mFileName,saveFile);
}


void MyWidget::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open CSV", "", "CSV (*.csv)");
    if (fileName.isEmpty()) return;
    QFile mFile(fileName);
    if (!mFile.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "cannot open this file";
        return;
    }
    QTextStream in(&mFile);
    in.setEncoding(QStringConverter::System);

    ui->tableWidget->setRowCount(0);

    while(!in.atEnd()){
        QString line = in.readLine();
        if(line.trimmed().isEmpty()) continue;

        QStringList fields = line.split(',');
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        for(int i=0;i<ui->tableWidget->columnCount();i++){
            ui->tableWidget->setItem(row,i,new QTableWidgetItem(fields.value(i)));
        }
    }
    mFile.close();
}

