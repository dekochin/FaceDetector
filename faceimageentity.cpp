#include "faceimageentity.h"

void FaceImageEntity::setImage(const QString& path, const QImage& img)
{
    image = img;
    filepath = path;

    return;
}

void FaceImageEntity::addDetectResult(const QRect& rect, float conf)
{
    FaceInfo inf;
    inf.rect = rect;
    inf.cofidence = conf;
    face.append(inf);

    return;
}


const QImage& FaceImageEntity::getImage() const
{
    return image;
}

const QString& FaceImageEntity::getFilepath() const
{
    return filepath;
}

const QList<FaceInfo>& FaceImageEntity::getDetectedFaces() const
{
    return face;
}