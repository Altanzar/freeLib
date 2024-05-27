#include "coverlabel.h"

#include <QResizeEvent>

CoverLabel::CoverLabel(QWidget *parent)
    :QLabel(parent)
{
    setMinimumSize(1,1);
    setScaledContents(false);
}

void CoverLabel::setImage(const QImage &image)
{
    if(!image.isNull()){
        pix = QPixmap::fromImage(image);
        pix.setDevicePixelRatio(devicePixelRatioF());
        QLabel::setPixmap(scaledPixmap());
        show();
    }else
        hide();
}

QPixmap CoverLabel::scaledPixmap() const
{
    return pix.scaledToHeight(this->size().height()*devicePixelRatioF(), Qt::SmoothTransformation);
}

QSize CoverLabel::sizeHint() const
{
    int h = height();
    return pix.isNull() ?size() :QSize( (float)h * pix.width() / pix.height(), h );
}

void CoverLabel::resizeEvent(QResizeEvent */*event*/)
{
    if(!pix.isNull())
        QLabel::setPixmap(scaledPixmap());
}

