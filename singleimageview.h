#ifndef SINGLEIMAGEVIEW_H
#define SINGLEIMAGEVIEW_H

#include <QWidget>
#include <QFileInfo>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QPainter>
#include <QPen>
#include "basefaceview.h"
#include "facecontroller.h"

namespace Ui {
class SingleImageView;
}

class SingleImageView : public BaseFaceView
{
    Q_OBJECT

public:
    explicit SingleImageView(std::shared_ptr<FaceController> ctrl, QWidget *parent = nullptr);
    ~SingleImageView();

public slots:
    void onImageUpdate();

protected:
    void onFileDropped(const QList<QUrl>& urls) override;
    void updateView() override;

private:
    Ui::SingleImageView *ui;

};

#endif // SINGLEIMAGEVIEW_H
