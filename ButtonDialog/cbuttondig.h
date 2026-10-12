#ifndef CBUTTONDIG_H
#define CBUTTONDIG_H

#include <QDialog>
#include <QtWidgets>

class CButtonDIg : public QDialog
{
    Q_OBJECT

public:
    explicit CButtonDIg(QWidget *parent = nullptr);
    ~CButtonDIg() override;

private:
    QTextEdit *displayTextEdit;
    QPushButton *colorPushBtn;
    QPushButton *errorPushBtn;
    QPushButton *filePushBtn;
    QPushButton *fontPushBtn;
    QPushButton *inputPushBtn;
    QPushButton *pagePushBtn;
    QPushButton *progressPushBtn;
    QPushButton *printPushBtn;
    QPushButton *ChangeTextCorlorPushBtn;

private slots:
    void doPushBtn();
};
#endif // CBUTTONDIG_H
