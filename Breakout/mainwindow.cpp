#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}


MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::restart() {
    arcanoid->close();
    this->show();
}


void MainWindow::on_pushButton_3_clicked() {
    this->close();
}


void MainWindow::on_pushButton_clicked() {
    arcanoid = new Arcanoid();
    arcanoid->resize(300, 400);
    arcanoid->setWindowTitle("Arcanoid");
    arcanoid->show();
    this->hide();
    connect(arcanoid, &Arcanoid::finish, this, &MainWindow::restart);
}
