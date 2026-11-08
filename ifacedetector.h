#ifndef IFACEDETECTOR_H
#define IFACEDETECTOR_H
#include <QRect>
#include <QImage>
#include "faceimageentity.h"

class IFaceDetector
{
public:
    virtual ~IFaceDetector() = default;
    virtual QList<FaceInfo> detectFaces(FaceImageEntity& entity) = 0;
};

#endif // IFACEDETECTOR_H
