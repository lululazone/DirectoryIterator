#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "inputmanager.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    InputManager inputManager;

private slots:
    void on_pushButton_clicked();

    void on_textBrowser_textChanged();

    void on_textEdit_textChanged();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
