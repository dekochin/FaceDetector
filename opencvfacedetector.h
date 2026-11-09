#ifndef OPENCVFACEDETECTOR_H
#define OPENCVFACEDETECTOR_H

#include "ifacedetector.h"
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <QDebug>

class OpenCVFaceDetector : public IFaceDetector
{
public:
    OpenCVFaceDetector();
    QList<FaceInfo> detectFaces(const QImage& image) override;

private:
    cv::Ptr<cv::FaceDetectorYN> detector;
};

#endif // OPENCVFACEDETECTOR_H
