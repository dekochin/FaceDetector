#include "singleimageview.h"
#include "ui_singleimageview.h"

SingleImageView::SingleImageView(std::shared_ptr<FaceController> ctrl, QWidget *parent)
    : BaseFaceView(ctrl, parent)
    , ui(new Ui::SingleImageView)
{
    ui->setupUi(this);

    if (parent) {
        this->resize(parent->size());
    }
    setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->imageLabel->resize(this->size());
    ui->imageLabel->setAlignment(Qt::AlignCenter);
    ui->imageLabel->setText("drag and drop image");
    ui->imageLabel->setAttribute(Qt::WA_TransparentForMouseEvents, true);
}

void SingleImageView::onFileDropped(const QList<QUrl>& urls)
{
    qDebug() << "drop!";
    QString filepath = urls.first().toLocalFile();

    controller->handleFileDropped(filepath);

    return;
}

void SingleImageView::updateView()
{
    const FaceImageEntity* entity = controller->getCurrentEntity();
    if (entity){
        QImage currentImage = entity->getImage();
        QSize labelSize = ui->imageLabel->size();
        QSize trgSize = currentImage.size();
        if (labelSize.width() < trgSize.width() || labelSize.height() < trgSize.height())
        {
            trgSize = labelSize;
        }
        QImage scaledImage = currentImage.scaled(trgSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

        QList<FaceInfo> faces = entity->getDetectedFaces();

        QPainter painter(&scaledImage);
        QPen pen(Qt::green, 2);
        painter.setPen(pen);

        qreal scale_x = qreal(scaledImage.width()) / qreal(currentImage.width());
        qreal scale_y = qreal(scaledImage.height()) / qreal(currentImage.height());

        for (int i = 0; i < faces.size(); i++)
        {
            QRect orgRect = faces[i].rect;
            QRect scaledRect(qRound(orgRect.x() * scale_x),
                             qRound(orgRect.y() * scale_y),
                             qRound(orgRect.width() * scale_x),
                             qRound(orgRect.height() * scale_y)
                             );
            painter.drawRect(scaledRect);
        }

        painter.end();

        QPixmap pixmap = QPixmap::fromImage(scaledImage);
        ui->imageLabel->setPixmap(pixmap);
    }

    return;
}

void SingleImageView::onImageUpdate()
{
    updateView();

    return;
}

SingleImageView::~SingleImageView()
{
    delete ui;
}
