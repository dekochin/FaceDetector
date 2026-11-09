#include "facecontroller.h"

FaceController::FaceController(std::shared_ptr<IFaceDetector> det, QObject *parent)
    : QObject{parent}
    , detector(det)
    , index(-1)
{
    return;
}

void FaceController::handleFileDropped(const QString& path)
{
    QImage image = QImage(path);

    if (!image.isNull())
    {
        QList<FaceInfo> result = detector->detectFaces(image);
        addEntity(result, path, image);
    }

    emit imageUpdate();
    return;
}

void FaceController::onChangeDetector(const QString& name)
{
    detector = DetectorFactory::makeDetector(name);
    if (!entity.isEmpty())
    {
        QList<FaceInfo> result = detector->detectFaces(entity[index].getImage());
        entity[index].resetDetectResult();

        writeEntity(result, entity[index]);

    }

    emit imageUpdate();
    return;
}

void FaceController::addEntity(const QList<FaceInfo> &inf, const QString &path, const QImage &image)
{
    FaceImageEntity ent;
    ent.setImage(path, image);

    writeEntity(inf, ent);

    entity.append(ent);
    index++;

    return;
}

void FaceController::writeEntity(const QList<FaceInfo> &inf, FaceImageEntity &ent)
{
    for (int i = 0; i < inf.size(); i++)
    {
        FaceInfo face = inf[i];
        ent.addDetectResult(face.rect, face.cofidence);
    }

    return;
}

const FaceImageEntity* FaceController::getCurrentEntity() const
{
    if (!entity.isEmpty()){
        return &(entity.at(index));
    }

    return nullptr;
}