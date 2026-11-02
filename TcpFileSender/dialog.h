#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtNetwork>
#include <QWidget>
#include <QtWidgets>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog() override;
public slots:
    void start();
    void startTransfer();
    void updateClientProgress(qint64 numBytes);
    void openFile();
private:
    QProgressBar *clientProgressBar;
    QLabel *clientStatusLabel;
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *openButton;
    QDialogButtonBox *buttonBox;
    QTcpSocket tcpClient;

    qint64 totalBytes;
    qint64 bytesWritten;
    qint64 bytesToWrite;
    qint64 loadSize;
    QString fileName;
    QFile *localFile;
    QByteArray outBlock;
};
#endif // DIALOG_H
