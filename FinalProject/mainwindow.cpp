#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QStatusBar>
#include <QStyle>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->actionOpen->setIcon(style()->standardIcon(QStyle::SP_DialogOpenButton));
    ui->actionSave->setIcon(style()->standardIcon(QStyle::SP_DialogSaveButton));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(
        this, tr("Open Image"), QString(),
        tr("Images (*.png *.jpg *.jpeg *.bmp)"));
    if (fileName.isEmpty())
        return;
    statusBar()->showMessage(tr("Open: %1").arg(fileName));
}

void MainWindow::on_actionSave_triggered()
{
    statusBar()->showMessage(tr("Save triggered"), 3000);
}