#include "EditableButton.h"
#include <QTimer>
#include <QDebug>


EditableButton::EditableButton(QWidget *parent) : QPushButton(parent),
    mEdit(nullptr)
{
    setText(tr("Edit Me!"));
    mEdit = new EditableButtonLineEdit(this->parentWidget());
    connect(mEdit, &QLineEdit::editingFinished,
            this, &EditableButton::onEditFinished, Qt::DirectConnection);
    mEdit->setText(text());
    mEdit->resize(this->width(), this->height());
    mEdit->setAlignment(Qt::AlignCenter);
    mEdit->setGeometry(this->geometry());
    mEdit->setContextMenuPolicy(Qt::NoContextMenu);
    mEdit->hide();
}

void EditableButton::createEditLabel()
{
    if (mEdit) {

        mEdit->setText(text());
        mEdit->setGeometry(this->geometry());
        mEdit->show();
        mEdit->setFocus(Qt::NoFocusReason);
        mEdit->selectAll();
        mEdit->setCursorPosition(mEdit->text().size());
    }
}

void EditableButton::destroyEditLabel()
{
    if (mEdit) {
        mEdit->hide();
    }
}

void EditableButton::onEditFinished()
{
    if (mEdit->isVisible()) {
        if (mEdit->text() != this->text()) {
            this->setText(mEdit->text());
            Q_EMIT textChanged(this->text());
        }
    }
    destroyEditLabel();
}

void EditableButton::mouseDoubleClickEvent(QMouseEvent *ev)
{
    QPushButton::mouseDoubleClickEvent(ev);
    createEditLabel();
}

/**
 * @brief EditableButton::focusOutEvent
 * @param ev
 *
 * Override the focusOutEvent to force edit finish.
 */
void EditableButton::focusOutEvent(QFocusEvent *ev)
{
    if (mEdit->isVisible()) {
        Q_EMIT mEdit->editingFinished();
    }
    destroyEditLabel();
}



EditableButtonLineEdit::EditableButtonLineEdit(QWidget *parent) : QLineEdit(parent)
{

}

/**
 * @brief EditableButtonLineEdit::focusOutEvent
 * @param ev
 *
 * Override the focusOutEvent to force edit finish.
 */
void EditableButtonLineEdit::focusOutEvent(QFocusEvent *ev)
{
    QLineEdit::focusOutEvent(ev);
    Q_EMIT editingFinished();
}
