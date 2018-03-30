#include "SimContactsModel.h"
#include "SimContactsModel_p.h"

#include "Adapters/SimContactInfo.h"

SimContactsModel::SimContactsModel(QObject *parent)
    : QStandardItemModel(parent)
{
}

void SimContactsModel::updateInfo(SimContactInfo *info)
{
    if (infos.contains(info->id()))
        return;

    auto item = new QStandardItem("v");
    item->setData(QVariant::fromValue(info));
    appendRow(item);
    infos.insert(info->id(), item);
}

void SimContactsModel::removeInfo(SimContactInfo *info)
{
    delete infos.take(info->id());
}

SimContactInfo *SimContactsModel::info(const QString &id) const
{
    auto item = infos.value(id);
    if (item) {
        return item->data().value<SimContactInfo *>();
    }

    return nullptr;
}

QHash<int, QByteArray> SimContactsModel::roleNames() const
{
    QHash<int, QByteArray> roleNames;
    roleNames.insert(Qt::UserRole + 1, "contactInfo");
    return roleNames;
}
