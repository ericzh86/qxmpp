#ifndef SIMSESSIONMODEL_H
#define SIMSESSIONMODEL_H

#include <QStandardItemModel>

class SimSessionModel : public QStandardItemModel
{
    Q_OBJECT

public:
    explicit SimSessionModel(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SIMSESSIONMODEL_H
