#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "arcanoid.h"


namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

private slots:
    void restart();
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();

private:
    Ui::MainWindow* ui;
    Arcanoid* arcanoid;
};

#endif // MAINWINDOW_H
