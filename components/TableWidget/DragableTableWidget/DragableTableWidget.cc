#include "DragableTableWidget.h"
#include <QDebug>
#include <QDropEvent>

DragableTableWidget::DragableTableWidget(QWidget* parent) : QTableWidget(parent)
{
    setDragDropMode(QAbstractItemView::InternalMove);
    setDropIndicatorShown(true);
    setSelectionBehavior(QAbstractItemView::SelectRows);
}

void DragableTableWidget::dropEvent(QDropEvent *ev)
{
    qDebug() << "dropEvent";

    int rowSrc;
    int rowDst;
    int rowToRemove;
    int rowToFill;

    rowSrc = currentRow();
    rowToRemove = rowSrc;
    QTableWidgetItem *pItem = itemAt(ev->pos());
    if (pItem) {    // item exists, so move in the table
        rowDst = pItem->row();
        if (rowSrc == rowDst) {
            return;
        }

        rowToRemove = rowDst < rowSrc ? rowSrc + 1 : rowSrc;
        rowToFill = rowToRemove < rowDst ? rowDst + 1 : rowDst;

    } else {    // no item means, move to the end of the table
        rowDst = rowCount();
        rowToFill = rowDst;
    }

    qDebug() << "src" << rowSrc << "dst" << rowDst << "remove" << rowToRemove << "fill" << rowToFill;
    insertRow(rowToFill);    // insert Row
    const int _rowHeight = rowHeight(rowToRemove);
    setRowHeight(rowToFill, _rowHeight);   // copy the original row height

    // move the items to new row
    for (int col = 0; col < this->columnCount(); ++col) {
        setItem(rowToFill, col, takeItem(rowToRemove, col));
    }

    this->removeRow(rowToRemove); // remove the original row after inserting the new row.

}
