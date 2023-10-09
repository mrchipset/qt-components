#ifndef LongPressButton_H
#define LongPressButton_H

#include <QWidget>
#include <QPushButton>
#include <QTimer>

/**
 * @brief The LongPressButton class
 *
 * demo code
 *   QDialog dlg;
 *   dlg.resize(480, 320);
 *   LongPressButton btn(&dlg);
 *   btn.setText(QObject::tr("Long Press Me"));
 *   QObject::connect(&btn, &LongPressButton::clicked, [=](){
 *       qDebug() << "Click";
 *   });
 *   QObject::connect(&btn, &LongPressButton::pressed, [=](){
 *       qDebug() << "Pressed";
 *   });

 *   QObject::connect(&btn, &LongPressButton::longPressed, [=](){
 *       qDebug() << "Long Pressed";
 *   });
 *   QObject::connect(&btn, &LongPressButton::released, [=](){
 *       qDebug() << "Release";
 *   });
 *   btn.move(100, 100);
 *   dlg.show();
 *
 */
class LongPressButton : public QPushButton
{
    Q_OBJECT
public:
    LongPressButton(QWidget* parent=nullptr);

    /**
     * @brief setLongPressThreshold
     * @param threshold long press threshold after press, unit is milliseconds
     */
    void setLongPressThreshold(uint32_t threshold);
    uint32_t longPressThreshold() const;

    Q_SIGNAL void longPressed();
private:
    QTimer mLongPressTimer;
    uint32_t mLongPressThreshold;
protected:
    void mousePressEvent(QMouseEvent* ev) override;
    void mouseReleaseEvent(QMouseEvent* ev) override;
};

#endif // LongPressButton_H
