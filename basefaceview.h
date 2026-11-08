#ifndef BASEFACEVIEW_H
#define BASEFACEVIEW_H

#include <QWidget>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QFileInfo>
#include <QDebug>
#include "facecontroller.h"
#include "ifaceview.h"

class BaseFaceView : public QWidget, public IFaceView
{
    Q_OBJECT
public:
    explicit BaseFaceView(std::shared_ptr<FaceController> ctrl, QWidget *parent = nullptr);

protected:
    std::shared_ptr<FaceController> controller;

    void dragEnterEvent(QDragEnterEvent *ev) override;
    void dropEvent(QDropEvent *ev) override;
    void dragMoveEvent(QDragMoveEvent *ev) override;
    void resizeEvent(QResizeEvent *ev) override;

    virtual void onFileDropped(const QList<QUrl>& urls) = 0;



signals:
};

#endif // BASEFACEVIEW_H
