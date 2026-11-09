#include "detectorfactory.h"

DetectorFactory::DetectorFactory() {}

std::unique_ptr<IFaceDetector> DetectorFactory::makeDetector(const QString& name)
{
    std::unique_ptr<IFaceDetector> detector;
    qDebug() << name;
    if (name == "OpenCV YuNet")
    {
        detector = std::make_unique<OpenCVFaceDetector>();
    }
    else
    {
        detector = std::make_unique<MocFaceDetector>();
    }
    return detector;
}