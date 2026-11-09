#include "mainwindow.h"
#include "facecontroller.h"
#include "singleimageview.h"
// #include "moc_facedetector.h"
#include "opencvfacedetector.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // auto detector = std::make_shared<MocFaceDetector>(); // 検出器のサービス．今はmoc
    auto detector = std::make_shared<OpenCVFaceDetector>(); // OpenCVのYuNet検出器
    auto controller = std::make_shared<FaceController>(detector); // コントローラーにサービスをDI
    auto view = std::make_shared<SingleImageView>(controller); // バウンダリにコントローラーをDI

    MainWindow w;
    w.addView(view);

    QObject::connect(controller.get(), &FaceController::imageUpdate, view.get(), &SingleImageView::onImageUpdate);
    QObject::connect(&w, &MainWindow::changeDetector, controller.get(), &FaceController::onChangeDetector);

    w.show();
    return QApplication::exec();
}
