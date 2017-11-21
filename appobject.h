#pragma once

#include <QObject>
#include <QFile>


// forward declaration
class ColorModel;


class AppObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(quint8 verticalBrickCount READ verticalBrickCount CONSTANT)
    Q_PROPERTY(quint8 horizontalBrickCount READ horizontalBrickCount CONSTANT)
    Q_PROPERTY(qreal brickWidth READ brickWidth CONSTANT)
    Q_PROPERTY(qreal brickHeight READ brickHeight CONSTANT)
    Q_PROPERTY(qreal isometricAngle READ isometricAngle CONSTANT)
    Q_PROPERTY(ColorModel * leftModel READ leftModel CONSTANT)
    Q_PROPERTY(ColorModel * rightModel READ rightModel CONSTANT)
    Q_PROPERTY(ColorModel * ceilModel READ ceilModel CONSTANT)
    Q_PROPERTY(ColorModel * floorModel READ floorModel CONSTANT)

public:
    explicit AppObject(const QUrl & source, QObject *parent = 0);

    quint8 verticalBrickCount() const;
    quint8 horizontalBrickCount() const;
    qreal brickWidth() const;
    qreal brickHeight() const;
    qreal isometricAngle() const;

    ColorModel * leftModel() const;
    ColorModel * rightModel() const;
    ColorModel * ceilModel() const;
    ColorModel * floorModel() const;

public slots:
    void save();

private:
    void load(const QUrl & source);

private:
    quint8 m_verticalBrickCount;
    quint8 m_horizontalBrickCount;
    qreal m_brickWidth;
    qreal m_brickHeight;
    qreal m_isometricAngle;
    ColorModel * m_leftModel;
    ColorModel * m_rightModel;
    ColorModel * m_ceilModel;
    ColorModel * m_floorModel;
};
