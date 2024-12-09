#include "mainwindow.h"
#include "inputmanager.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    inputManager = *new InputManager();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString input = this->ui->lineEdit->text();

    Outputexec return_code = inputManager.process(input);
    ui->textEdit->append(return_code.toString());
}






