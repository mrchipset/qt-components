#ifndef EDITABLEBUTTON_H
#define EDITABLEBUTTON_H

#include <QPushButton>
#include <QLineEdit>

class EditableButtonLineEdit;

class EditableButton : public QPushButton
{
    Q_OBJECT
public:
    EditableButton(QWidget* parent=nullptr);

Q_SIGNALS:
    /**
     * @brief textChanged signal emitted when edit finished.
     * @param text the new text write to QPushButton
     */
    void textChanged(const QString text);
private:
    EditableButtonLineEdit* mEdit;  ///< LineEdit

    void createEditLabel();
    void destroyEditLabel();
private Q_SLOTS:
    void onEditFinished();
protected:
    virtual void mouseDoubleClickEvent(QMouseEvent* ev) override;
    virtual void focusOutEvent(QFocusEvent* ev) override;
};

class EditableButtonLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    EditableButtonLineEdit(QWidget* parent=nullptr);

protected:
    virtual void focusOutEvent(QFocusEvent* ev) override;
};

#endif // EDITABLEBUTTON_H
