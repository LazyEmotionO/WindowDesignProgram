#include "mywidget.h"
#include "ui_mywidget.h"
#include <QFile>
#include <QDebug>

//QString mFileName = "C:/Users/user/Desktop/41243260_10_19/ContactBook/output/output.txt";
QString mFileName = "../../output/output.txt";

void Write(QString FileName,QString str){
    QFile mFile(FileName);
    if(!mFile.open(QFile::WriteOnly | QFile::Text)){
        qDebug()<<"cannot open this file\n";
        qDebug()<<QCoreApplication::applicationDirPath()<<"\n";
        return;
    }
    QTextStream out(&mFile);
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

