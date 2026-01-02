#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus); 
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() >= Qt::Key_A && event->key() <= Qt::Key_Z) {
        char letter = 'A' + (event->key() - Qt::Key_A);
        qDebug() << "Pressed:" << letter;
    }
}
