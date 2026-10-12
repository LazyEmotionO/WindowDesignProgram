#include "cbuttondig.h"

CButtonDIg::CButtonDIg(QWidget *parent)
    : QDialog(parent)
{
    QGridLayout *gridlayout = new QGridLayout;
    displayTextEdit = new QTextEdit(QStringLiteral("Qt standard talk box"));
    colorPushBtn = new QPushButton(QStringLiteral("Color talk box"));
    errorPushBtn = new QPushButton(QStringLiteral("Error Message talk box"));
    filePushBtn = new QPushButton(QStringLiteral("File talk box"));
    fontPushBtn = new QPushButton(QStringLiteral("Font talk box"));
    inputPushBtn = new QPushButton(QStringLiteral("Input talk box"));
    pagePushBtn = new QPushButton(QStringLiteral("PageSetting talk box"));
    progressPushBtn = new QPushButton(QStringLiteral("Progress talk box"));
    printPushBtn = new QPushButton(QStringLiteral("Print talk box"));
    ChangeTextCorlorPushBtn = new QPushButton(QStringLiteral("ChangeTextCorlor box"));

    gridlayout->addWidget(colorPushBtn,0,0,1,1);
    gridlayout->addWidget(errorPushBtn,0,1,1,1);
    gridlayout->addWidget(filePushBtn,0,2,1,1);
    gridlayout->addWidget(fontPushBtn,1,0,1,1);
    gridlayout->addWidget(inputPushBtn,1,1,1,1);
    gridlayout->addWidget(pagePushBtn,1,2,1,1);
    gridlayout->addWidget(progressPushBtn,2,0,1,1);
    gridlayout->addWidget(printPushBtn,2,1,1,1);
    gridlayout->addWidget(displayTextEdit,3,0,3,3);
    gridlayout->addWidget(ChangeTextCorlorPushBtn,2,2,1,1);


    setLayout(gridlayout);
    setWindowTitle("include window");
    resize(800,600);

    connect(colorPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(errorPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(filePushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(fontPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(inputPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(pagePushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(progressPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(printPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(displayTextEdit,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(ChangeTextCorlorPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
}

void CButtonDIg::doPushBtn(){
    QPushButton *btn=qobject_cast<QPushButton*>(sender());
    if(btn==colorPushBtn){
        //qDebug()<<"from color talk box";
        QPalette palette=displayTextEdit->palette();
        const QColor &Color=QColorDialog::getColor(palette.color(QPalette::Base),this,QStringLiteral("Set Background color"));
        if(Color.isValid()){
            palette.setColor(QPalette::Base,Color);
            //palette.setColor(QPalette::Text,Color);
            displayTextEdit->setPalette(palette);
        }
    }
    if(btn==ChangeTextCorlorPushBtn){
        QPalette palette=displayTextEdit->palette();
        const QColor &Color=QColorDialog::getColor(palette.color(QPalette::Base),this,QStringLiteral("Set Background color"));
        if(Color.isValid()){
            //palette.setColor(QPalette::Base,Color);
            palette.setColor(QPalette::Text,Color);
            displayTextEdit->setPalette(palette);
        }
    }
    if(btn==filePushBtn){
        //QString filename = QFileDialog::getOpenFileName(this,QStringLiteral("openfile"),".",QStringLiteral("any file(*.*);;txt(*.txt);;XML(*.txt"));
        QString filename = QFileDialog::getSaveFileName(this,QStringLiteral("openfile"),".",QStringLiteral("any file(*.*);;txt(*.txt);;XML(*.txt"));
        displayTextEdit->setText(filename);
    }
    //qDebug()<<"touch";
}

CButtonDIg::~CButtonDIg() = default;


