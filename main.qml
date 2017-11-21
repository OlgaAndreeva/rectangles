import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.0
import QtQuick.Controls 1.4
import com.ics.demo 1.0

Window {

    visible: true
    width: 640
    height: 480
    title: qsTr("HallWay")

    Component {
        id: wallComponent
        GridView {
            id: wall

            cellWidth: brickWidth
            cellHeight: brickHeight
            interactive: false

            width: cellWidth * horizontalBrickCount
            height: cellHeight * verticalBrickCount

            model: dataModel
            delegate: Rectangle {
                id: rect
                width: GridView.view.cellWidth
                height: GridView.view.cellHeight
                color: color

                border {
                    width: 4.5
                    color: 'red'
                }

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        colorDialog.currentBlock = rect
                        colorDialog.open()
                    }
                }

                onColorChanged: {
                    var m = GridView.view.model;

                   m.setColor(m.index(index, 0), color)
                }
            }
        }
    }

    ColorDialog {
        id: colorDialog
        property Rectangle currentBlock: null

        title: "Please choose a color"

        onAccepted: {
            if (!!currentBlock) {
                currentBlock.color = currentColor
            }
        }
    }
    Loader {
        id: leftWallCreator
        readonly property var dataModel: leftModel
        anchors.centerIn: parent
        sourceComponent: wallComponent
        transform: Rotation {
            origin.x: 0
            origin.y: brickHeight * verticalBrickCount / 2
            axis {
                x: 0
                y: 1
                z: 0
            }
            angle: isometricAngle
        }
    }

    Loader {
        id: rightWallCreator
        readonly property var dataModel: rightModel
        anchors.centerIn: parent
        sourceComponent: wallComponent
        transform: Rotation {
            origin.x: brickWidth * horizontalBrickCount
            origin.y: brickHeight * verticalBrickCount / 2
            axis {
                x: 0
                y: 1
                z: 0
            }
            angle: -isometricAngle
        }
    }

    Loader {
        id: floorWallCreator
        readonly property var dataModel: floorModel
        anchors.centerIn: parent
        sourceComponent: wallComponent
        transform: Rotation {
            origin.x: brickWidth * horizontalBrickCount / 2
            origin.y: brickHeight * verticalBrickCount
            axis {
                x: 1
                y: 0
                z: 0
            }
            angle: isometricAngle
        }
    }

    Loader {
        id: ceilWallCreator
        readonly property var dataModel: ceilModel
        anchors.centerIn: parent
        sourceComponent: wallComponent
        transform: Rotation {
            origin.x: brickWidth * horizontalBrickCount / 2
            origin.y: 0
            axis {
                x: 1
                y: 0
                z: 0
            }
            angle: -isometricAngle
        }
    }

    Button {
        text: "Экспорт в XML"

        onClicked: {
            save()
        }
    }
}
