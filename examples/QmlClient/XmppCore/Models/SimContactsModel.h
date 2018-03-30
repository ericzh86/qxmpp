#ifndef SIMCONTACTSMODEL_H
#define SIMCONTACTSMODEL_H

#include <QStandardItemModel>

class SimContactInfo;

class SimContactsModel : public QStandardItemModel
{
    Q_OBJECT

public:
    explicit SimContactsModel(QObject *parent = nullptr);

public:
    void updateInfo(SimContactInfo *info);
    void removeInfo(SimContactInfo *info);

public:
    SimContactInfo *info(const QString &id) const;

public:
    QHash<int, QByteArray> roleNames() const;
private:
    QHash<QString, QStandardItem *> infos;
};

#endif // SIMCONTACTSMODEL_H
