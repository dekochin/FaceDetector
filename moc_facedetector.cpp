#include "moc_facedetector.h"

QList<FaceInfo> MocFaceDetector::detectFaces(const QImage& image)
{
    QList<FaceInfo> result;
    int w, h, x, y;
    w = image.width() / 4;
    h = image.height() / 4;
    x = (image.width() - w) / 2;
    y = (image.height() - h) / 2;

    result.append(FaceInfo{QRect(x, y, w, h), 0.9});

    return result;
}