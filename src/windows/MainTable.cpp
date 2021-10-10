#include "MainTable.h"


MainTable::
MainTable(QWidget* parent)
    : QTableWidget(parent)
{
    connect(verticalHeader(), &QHeaderView::sectionCountChanged, this, &MainTable::rowCountChanged);
    connect(verticalHeader(), &QHeaderView::sectionResized, this, &MainTable::rowResized);
}

MainTable::
~MainTable() {}

void
MainTable::
rowResized(int logicalIndex, int, int newSize)
{
    rowHeight_[logicalIndex] = newSize;
}

void
MainTable::
rowCountChanged(int, int newCount)
{
    if (!newCount)
        return;

    if (rowHeight_.size() < newCount) {
        rowHeight_.push_back(verticalHeader()->sectionSize(newCount - 1));
        return;
    }

    verticalHeader()->resizeSection(newCount - 1, rowHeight_[newCount - 1]);
}
