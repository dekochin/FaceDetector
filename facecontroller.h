#ifndef FACECONTROLLER_H
#define FACECONTROLLER_H

#include <QObject>
#include <memory>
#include "ifacedetector.h"
#include "faceimageentity.h"
#include "detectorfactory.h"

class FaceController : public QObject
{
    Q_OBJECT
public:
    explicit FaceController(std::shared_ptr<IFaceDetector> det, QObject *parent = nullptr);
    void requestDetection(const QImage& image);
    void handleFileDropped(const QString& path);
    const FaceImageEntity* getCurrentEntity() const;

public slots:
    void onChangeDetector(const QString& name);

private:
    std::shared_ptr<IFaceDetector> detector; // 検出器本体
    QList<FaceImageEntity> entity;
    int index;

    void addEntity(const QList<FaceInfo> &inf, const QString& path, const QImage& image);
    void writeEntity(const QList<FaceInfo> &inf, FaceImageEntity &ent);

signals:
    void imageUpdate();

};

#endif // FACECONTROLLER_H
