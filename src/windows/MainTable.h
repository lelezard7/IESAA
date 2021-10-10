#ifndef MAINTABLE_H_
#define MAINTABLE_H_

#include <QTableWidget>
#include <QHeaderView>
#include <QVector>


class MainTable : public QTableWidget
{
    Q_OBJECT

private:
    QVector<int> rowHeight_;

public:
    MainTable(QWidget* parent = nullptr);
    virtual ~MainTable();

public slots:
    void rowResized(int logicalIndex, int oldSize, int newSize);
    void rowCountChanged(int oldCount, int newCount);

};

#endif
