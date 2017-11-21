#include "appobject.h"
#include "colormodel.h"

#include <QXmlStreamWriter>

AppObject::AppObject(const QUrl &source, QObject *parent)
    : QObject(parent)
{
    load(source);
}

ColorModel *AppObject::leftModel() const
{
    return m_leftModel;
}

ColorModel *AppObject::rightModel() const
{
    return m_rightModel;
}

ColorModel *AppObject::ceilModel() const
{
    return m_ceilModel;
}

ColorModel *AppObject::floorModel() const
{
    return m_floorModel;
}

quint8 AppObject::verticalBrickCount() const
{
    return m_verticalBrickCount;
}

quint8 AppObject::horizontalBrickCount() const
{
    return m_horizontalBrickCount;
}

qreal AppObject::brickWidth() const
{
    return m_brickWidth;
}

qreal AppObject::brickHeight() const
{
    return m_brickHeight;
}

qreal AppObject::isometricAngle() const
{
    return m_isometricAngle;
}

void AppObject::save()
{
    // TODO: save properties into XML


    QString filename = "C:\\example\\x.xml";
    const QModelIndex &index =  this->m_leftModel->index(2, 0);
    QString id_rec = this->m_leftModel->data(index,2).toString();

    QFile file(filename);
    file.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("HallWay");

    xmlWriter.writeStartElement("rightWall");
    xmlWriter.writeTextElement("Id", id_rec );
    xmlWriter.writeTextElement("Color", "test");

    xmlWriter.writeEndElement();

    file.close();

}

void AppObject::load(const QUrl & source)
{
    Q_UNUSED(source)
    // TODO: load files from XML
    m_brickHeight = m_brickWidth = 140;
    m_verticalBrickCount = m_horizontalBrickCount = 5;
    m_isometricAngle = 70.5;
    m_leftModel = new ColorModel(m_horizontalBrickCount, m_verticalBrickCount, this);
    m_rightModel = new ColorModel(m_horizontalBrickCount, m_verticalBrickCount, this);
    m_floorModel = new ColorModel(m_horizontalBrickCount, m_verticalBrickCount, this);
    m_ceilModel = new ColorModel(m_horizontalBrickCount, m_verticalBrickCount, this);

}

