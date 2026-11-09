#ifndef FACEIMAGEENTITY_H
#define FACEIMAGEENTITY_H

#include <QRect>
#include <QString>
#include <QList>
#include <QImage>

struct FaceInfo
{
    QRect rect; // 検出した矩形
    float cofidence; // 矩形の信頼度
};

class FaceImageEntity
{
public:
    FaceImageEntity() = default;
    void setImage(const QString& path, const QImage& img);
    void addDetectResult(const QRect& rect, float conf = 0.0);
    void resetDetectResult();

    const QImage& getImage() const;
    const QList<FaceInfo>& getDetectedFaces() const;
    const QString& getFilepath() const;

private:
    QList<FaceInfo> face;
    QString filepath;
    QImage image;
};

#endif // FACEIMAGEENTITY_H
