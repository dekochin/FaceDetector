#include "facecontroller.h"

FaceController::FaceController(std::shared_ptr<IFaceDetector> det, QObject *parent)
    : QObject{parent}
    , detector(det)
{
    return;
}

void FaceController::handleFileDropped(const QString& path)
{
    QImage image = QImage(path);

    if (!image.isNull())
    {
        FaceImageEntity imgent;
        imgent.setImage(path, image);
        if (detector){
            QList<FaceInfo> result = detector->detectFaces(imgent);
            for (int i = 0; i < result.length(); i++)
            {
                FaceInfo info = result[i];
                imgent.addDetectResult(info.rect, info.cofidence);
            }
        }

        entity.push_back(imgent);

    }
    emit imageUpdate();

    return;
}

const FaceImageEntity* FaceController::getCurrentEntity() const
{
    if (!entity.isEmpty()){
        return &(entity.last());
    }

    return nullptr;
}