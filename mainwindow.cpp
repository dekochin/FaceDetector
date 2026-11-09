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

    setupMenu();

    return;
}

void MainWindow::addView(std::shared_ptr<IFaceView> v)
{
    stackedwidget->addWidget(dynamic_cast<QWidget*>(v.get()));

    return;
}

void MainWindow::setupMenu()
{
    QActionGroup* tools = new QActionGroup(this);
    tools->setExclusive(true);

    tools->addAction(ui->actionMock);
    tools->addAction(ui->actionOpenCV_YuNet);
    ui->actionOpenCV_YuNet->setChecked(true);

    connect(tools, &QActionGroup::triggered, this, [this](QAction* action){
        emit changeDetector(action->text());
    });

    return;
}

MainWindow::~MainWindow()
{
    delete ui;

    return;
}
