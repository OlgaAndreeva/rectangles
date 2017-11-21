#include "colormodel.h"
#include <QVariant>
#include <QDebug>


ColorModel::ColorModel(size_t row, size_t column, QObject * parent)
    : QAbstractListModel(parent)
    , rows_(row)
    , columns_(column)
    , colors_(static_cast<int>(row * column))
{
}


int ColorModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return colors_.size();
}

QVariant ColorModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid())
    {
        if (role == Qt::BackgroundColorRole)
        {
            return colors_[index.row()];
        }
    }
    return QVariant();
}

bool ColorModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid())
    {
        if (role == Qt::BackgroundColorRole)
        {
            if (QVariant::Color == value.type())
            {
                colors_[index.row()] = value.value<QColor>();
                dataChanged(index, index, QVector<int>() << role);
                return true;
            }
        }
    }
    return false;
}

QHash<int, QByteArray> ColorModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles.insert(Qt::BackgroundColorRole, "color");
    return roles;
}

void ColorModel::setColor(const QModelIndex &index, const QColor &color)
{
    setData(index, QVariant::fromValue(color), Qt::BackgroundColorRole);
}
