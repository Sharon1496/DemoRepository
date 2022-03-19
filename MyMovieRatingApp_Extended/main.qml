import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
Window {
    id:window1
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Component{
        id:c1
        Rectangle{
            width:window1.width
            height :50
            color: "#be75dc"
            RowLayout{
                anchors.fill: parent
                spacing:10
                Text{
                    id:t1
                    text:index+1
                    Layout.minimumWidth: 100
                }
                Text{
                    id:t2
                    text: movieName
                    Layout.minimumWidth: 100
                }
                Text{
                    id:t3
                    text:Rating
                    Layout.minimumWidth: 100
                }
            }
        }
    }

    Component{
        id:c2
        Rectangle{
            width:window1.width
            height :50
            color: "#be75dc"
            ColumnLayout{
                anchors.fill: parent
                spacing:10
                ColumnLayout{
                    spacing: 10
                    Text{
                        id:t1
                        text:index+1
                        Layout.minimumWidth: 100
                    }
                }
                RowLayout{
                    spacing:10
                    Text{
                        id:t2
                        text: movieName
                        Layout.minimumWidth: 100
                    }
                    Text{
                        id:t3
                        text:Rating
                        Layout.minimumWidth: 100
                    }
                }

            }
        }
    }

    function insertData(){
        console.log("Insert Data function")
        var inData = {movieName:"Padmavat", Rating:4.2}
        myModel.insert(3,inData)
    }

    function printData(){
        console.log("Print Data function")
        for(var i = 0;i<myModel.count;i++)
        {
            var listElement = myModel.get(i)
            console.log("Movie Name : "+listElement.movieName)
            console.log("Rating : "+listElement.Rating)
            console.log("--------------------------------")
        }
    }

    function deleteData(){
        console.log("Delete Data function")
        myModel.remove(3,1)
    }

    function appendData(){
        console.log("Append Data function")
        var appendData = {movieName:"Udta Punjab", Rating:4.5}
        myModel.append(appendData)
    }

    function rowData(){
        console.log("Row Data function")
        listview.delegate = c1
    }

    function columnData(){
        console.log("Column Data function")
        listview.delegate = c2
    }

    ListModel {
        id: myModel
        ListElement{movieName:"Jab we met"; Rating:4.9}
        ListElement{movieName:"KGF"; Rating:4}
        ListElement{movieName:"Dear Commarade"; Rating:4.8}
        ListElement{movieName:"Arjun Reddy"; Rating:4.4}
        ListElement{movieName:"Kashmir Files"; Rating:5}
        ListElement{movieName:"Pushpa"; Rating:4.8}
        ListElement{movieName:"Sholay"; Rating:4.8}
        ListElement{movieName:"Bahubali"; Rating:4.6}
        ListElement{movieName:"Gangubai"; Rating:4}
        ListElement{movieName:"Bol Bachan"; Rating:4.5}
    }

    ColumnLayout{
        anchors.fill : parent
        ListView{
            id:listview
            spacing:10
            width: parent.width
            height:parent.height-100
            model:myModel
            delegate: c1
        }
        RowLayout
        {
            width: parent.width
            height: parent.height/2
            Layout.alignment: Qt.AlignBottom
            Button
            {
                id:btn1
                text: "Insert"
                onClicked:insertData()
            }
            Button
            {
                id:btn2
                text: "Print"
                onClicked:printData()
            }
            Button
            {
                id:btn3
                text: "Delete"
                onClicked:deleteData()
            }
            Button
            {
                id:btn4
                text: "Append"
                onClicked:appendData()
            }
            Button
            {
                id:btn5
                text: "Row"
                onClicked:rowData()
            }
            Button
            {
                id:btn6
                text: "Column"
                onClicked:columnData()
            }
        }
    }
}
