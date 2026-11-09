#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QActionGroup>
#include <QObject>
#include "ifaceview.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void addView(std::shared_ptr<IFaceView> v);

private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedwidget;

    void setupMenu();

signals:
    void changeDetector(const QString& name);
};
#endif // MAINWINDOW_H
