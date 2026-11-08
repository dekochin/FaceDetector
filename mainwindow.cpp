#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , stackedwidget(new QStackedWidget(this))
{
    ui->setupUi(this);
    stackedwidget->resize(size());
    setCentralWidget(stackedwidget);
    setWindowTitle("FaceDetector");
}

void MainWindow::addView(std::shared_ptr<IFaceView> v)
{
    stackedwidget->addWidget(dynamic_cast<QWidget*>(v.get()));

    return;
}



MainWindow::~MainWindow()
{
    delete ui;
}
