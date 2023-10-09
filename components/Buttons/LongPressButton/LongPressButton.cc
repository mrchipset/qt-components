#include "LongPressButton.h"

LongPressButton::LongPressButton(QWidget* parent) : QPushButton(parent),
    mLongPressThreshold(1000)
{
    setAutoRepeat(false);   // block auto repeat, otherwise click will always emit in a period
    mLongPressTimer.setInterval(mLongPressThreshold);
    mLongPressTimer.setSingleShot(true);
    connect(&mLongPressTimer, &QTimer::timeout,
            this, &LongPressButton::longPressed, Qt::DirectConnection);
}

void LongPressButton::setLongPressThreshold(uint32_t threshold)
{
    mLongPressThreshold = threshold;
}

uint32_t LongPressButton::longPressThreshold() const
{
    return mLongPressThreshold;
}

void LongPressButton::mousePressEvent(QMouseEvent *ev)
{
    mLongPressTimer.start();
    QPushButton::mousePressEvent(ev);
}

void LongPressButton::mouseReleaseEvent(QMouseEvent *ev)
{
    if (mLongPressTimer.isActive()) {   // normal click handle logic before long press
        mLongPressTimer.stop();
        QPushButton::mouseReleaseEvent(ev);
    } else {    // long pressed, block click signal emitted from QPushButton::mouseReleaseEvent
        Q_EMIT released();
        blockSignals(true);
        QPushButton::mouseReleaseEvent(ev);
        blockSignals(false);
    }

}
