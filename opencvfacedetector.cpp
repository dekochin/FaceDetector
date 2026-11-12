#include "opencvfacedetector.h"

OpenCVFaceDetector::OpenCVFaceDetector()
{
    QString appDir = QCoreApplication::applicationDirPath();
    std::string modelfilepath = QDir(appDir).filePath("face_detection_yunet_2023mar.onnx").toStdString();

    try {
        detector = cv::FaceDetectorYN::create(modelfilepath
                                              , ""
                                              , cv::Size(320,320)
                                              , 0.8f
                                              , 0.3f
                                              , 5000
                                              );
    }
    catch (const cv::Exception& e)
    {
        qWarning() << "failed initialize YuNet detector: " << e.what();
    }

    return;
}

QList<FaceInfo> OpenCVFaceDetector::detectFaces(const QImage &image)
{
    QList<FaceInfo> info;

    // OpenCV用の画像フォーマット用

    QImage rgbImg = image.convertToFormat(QImage::Format_RGB888).rgbSwapped();
    cv::Mat mat(rgbImg.height()
                    , rgbImg.width()
                    , CV_8UC3
                    , const_cast<uchar*>(rgbImg.bits())
                    , rgbImg.bytesPerLine()
                    );
    detector->setInputSize(mat.size());

    cv::Mat faces;
    detector->detect(mat, faces);

    for (int i = 0; i < faces.rows; i++)
    {
        FaceInfo inf;
        inf.rect = QRect(cvRound(faces.at<float>(i, 0)) // x
                         , cvRound(faces.at<float>(i, 1)) // y
                         , cvRound(faces.at<float>(i, 2)) // w
                         , cvRound(faces.at<float>(i, 3)) // h
                         );
        inf.cofidence = faces.at<float>(i, 14);
        info.append(inf);
    }

    return info;
}
