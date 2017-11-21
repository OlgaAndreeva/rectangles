#pragma once

#include <QAbstractListModel>
#include <QVector>
#include <QColor>

class ColorModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ColorModel(size_t row, size_t column, QObject * parent = nullptr);


    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    virtual QHash<int, QByteArray> roleNames() const override;

public slots:
    void setColor(const QModelIndex &index, const QColor & color);

private:
    size_t rows_;
    size_t columns_;
    QVector <QColor> colors_;
};

