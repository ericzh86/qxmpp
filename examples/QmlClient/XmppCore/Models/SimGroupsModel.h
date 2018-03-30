#ifndef SIMGROUPMODEL_H
#define SIMGROUPMODEL_H

#include <QStandardItemModel>

class SimGroupModel : public QStandardItemModel
{
    Q_OBJECT

public:
    explicit SimGroupModel(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SIMGROUPMODEL_H
