#include "basefaceview.h"

BaseFaceView::BaseFaceView(std::shared_ptr<FaceController> ctrl, QWidget *parent)
    : QWidget{parent}
    , controller(ctrl)
{
    setAcceptDrops(true);
    if (parent) {
        resize(parent->size());
    }
    return;
}

void BaseFaceView::dragEnterEvent(QDragEnterEvent *ev)
{
    qDebug() << "startEnterEvent";
    if (ev->mimeData()->hasUrls()){
        qDebug() << "EnterEventOK";
        ev->acceptProposedAction();
        return;
    }

    ev->ignore();
    return;
}

void BaseFaceView::dragMoveEvent(QDragMoveEvent *ev)
{
    qDebug() << "startMoveEvent";
    if (ev->mimeData()->hasUrls()){
        qDebug() << "MoveEventOK";
        ev->acceptProposedAction();
        return;
    }
    return;
}

void BaseFaceView::dropEvent(QDropEvent *ev)
{
    qDebug() << "startDropEvent";
    ev->acceptProposedAction();
    QList<QUrl> urls = ev->mimeData()->urls();
    if (!urls.isEmpty())
    {
        qDebug() << "DropEventOK";
        onFileDropped(urls);
    }

    return;
}

void BaseFaceView::resizeEvent(QResizeEvent *ev)
{
    updateView();
    return;
}
