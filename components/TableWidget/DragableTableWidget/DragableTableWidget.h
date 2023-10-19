#ifndef DRAGABLETABLEWIDGET_H
#define DRAGABLETABLEWIDGET_H

#include <QTableWidget>
#include <QWidget>

class DragableTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    DragableTableWidget(QWidget* parent=nullptr);

protected:
    virtual void dropEvent(QDropEvent* ev) override;
};

#endif // DRAGABLETABLEWIDGET_H
