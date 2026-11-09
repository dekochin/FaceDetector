#ifndef DETECTORFACTORY_H
#define DETECTORFACTORY_H

#include <QString>
#include <memory>

#include "ifacedetector.h"
#include "opencvfacedetector.h"
#include "moc_facedetector.h"

class DetectorFactory
{
public:
    DetectorFactory();
    static std::unique_ptr<IFaceDetector> makeDetector(const QString& name);
};

#endif // DETECTORFACTORY_H
