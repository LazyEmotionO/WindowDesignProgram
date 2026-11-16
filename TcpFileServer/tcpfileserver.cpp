#include "tcpfileserver.h"

TcpFileServer::TcpFileServer(QWidget *parent)
    : QDialog(parent)
{
    totalBytes=0;
    byteReceived=0;
    fileNameSize=0;
    serverProgressBar=new QProgressBar;
    serverStatusLabel=new QLabel(tr("Server Ready"));
    startButton=new QPushButton(tr("Received"));
    quitButton=new QPushButton(tr("Quit"));
    buttonBox=new QDialogButtonBox;
    buttonBox->addButton(startButton,QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton,QDialogButtonBox::RejectRole);

    QVBoxLayout *mainLayout=new QVBoxLayout;
    mainLayout->addWidget(serverProgressBar);
    mainLayout->addWidget(serverStatusLabel);
    mainLayout->addStretch();
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);
    setWindowTitle(tr("Recevive File"));

    connect(startButton,SIGNAL(clicked()),this,SLOT(start()));
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(&tcpserver,SIGNAL(newConnection()),this,SLOT(acceptConnection()));
    connect(&tcpserver,SIGNAL(acceptError(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));

}

TcpFileServer::~TcpFileServer() = default;
void TcpFileServer::start(){
    startButton->setEnabled(false);
    byteReceived=0;
    fileNameSize=0;
    while(!tcpserver.isListening()&&!tcpserver.listen(QHostAddress::AnyIPv4,16689)){
        QMessageBox::StandardButton ret = QMessageBox::critical(this,tr("Loop"),
                                                                tr("Cannot Start Server:%1.").arg(tcpserver.errorString()),
                                                                QMessageBox::Retry|QMessageBox::Cancel);
        if(ret==QMessageBox::Cancel)return;
    }
    serverStatusLabel->setText(tr("Listening..."));
}
void TcpFileServer::acceptConnection(){
    tcpServerConnection=tcpserver.nextPendingConnection();
    connect(tcpServerConnection,SIGNAL(readyRead()),this,SLOT(updateServerProgress()));
    connect(tcpServerConnection,SIGNAL(error(QAbstactSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
    serverStatusLabel->setText(tr("Connect Success"));
    tcpserver.close();
}
void TcpFileServer::updateServerProgress(){
    QDataStream in(tcpServerConnection);
    in.setVersion(QDataStream::Qt_4_6);
    if(byteReceived<=sizeof(qint64)*2){
        if(fileNameSize==0 && tcpServerConnection->bytesAvailable()>=sizeof(qint64)*2){
            in>>totalBytes>>fileNameSize;
            byteReceived+=sizeof(qint64)*2;
        }
        if(fileNameSize!=0 && tcpServerConnection->bytesAvailable()>=fileNameSize){
            in>>fileName;
            byteReceived+=fileNameSize;
            localFile=new QFile(fileName);
            if(!localFile->open(QFile::WriteOnly)){
                QMessageBox::warning(this,tr("Application"),tr("cannot read file: %1:\n%2.").arg(fileName)
                                                                  .arg(localFile->errorString()));
                return;
            }
        }
        else return;
    }
}
void TcpFileServer::displayError(QAbstractSocket::SocketError socketError){

}