#ifndef MOC_FACEDETECTOR_H
#define MOC_FACEDETECTOR_H

#include "ifacedetector.h"

class MocFaceDetector : public IFaceDetector
{
public:
    MocFaceDetector() = default;
    QList<FaceInfo> detectFaces(const QImage &image) override;
};

#endif // MOC_FACEDETECTOR_H
