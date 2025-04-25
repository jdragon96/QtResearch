#include <QByteArray>
#include <QDebug>
#include <QFile>
#include <QString>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

class Sensor {
public:
  QString SensorID;
  double AmbientTemperature = 0.0;
  double ObjectTemperature = 0.0;

  void print() {
    qInfo() << "********************************";
    qInfo() << "SensorID : " << SensorID;
    qInfo() << "AmbientTemperature : " << AmbientTemperature;
    qInfo() << "ObjectTemperature : " << ObjectTemperature;
    qInfo() << "********************************";
  }

  static Sensor fromXML(const QString path) {
    // 1. open file
    QFile file(path);
    file.open(QIODevice::ReadOnly);

    // 2. read data
    QByteArray data = file.readAll();
    file.close();

    // 3. parsing xml
    QXmlStreamReader stream(data);
    Sensor sensor;

    while (!stream.atEnd()) {
      QXmlStreamReader::TokenType token = stream.readNext();
      switch (token) {
      case QXmlStreamReader::Comment:
        break;
      case QXmlStreamReader::DTD:
        break;
      case QXmlStreamReader::Characters:
        break;
      case QXmlStreamReader::ProcessingInstruction:
        break;
      case QXmlStreamReader::EntityReference:
        break;
      case QXmlStreamReader::NoToken:
        break;
      case QXmlStreamReader::Invalid:
        break;
      case QXmlStreamReader::StartDocument:
        break;
      case QXmlStreamReader::EndDocument:
        break;
      case QXmlStreamReader::StartElement:
        if (stream.name().toString() == "Sensor") {
          sensor.SensorID = stream.attributes().value("SensorID").toString();
          sensor.AmbientTemperature =
              stream.attributes().value("AmbientTemperature").toDouble();
          sensor.ObjectTemperature =
              stream.attributes().value("ObjectTemperature").toDouble();
        }
        break;
      case QXmlStreamReader::EndElement:
        break;
      }
    }
    return sensor;
  }

  bool saveXML(QString path) {
    // 1. open file
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly)) {
      qCritical() << "Could not write file!";
      qCritical() << file.errorString();
      return false;
    }

    // 2. class to xml
    QXmlStreamWriter stream(&file);
    stream.writeStartDocument();
    stream.setAutoFormatting(true);
    {
      stream.writeStartElement("Sensor");
      stream.writeAttribute("SensorID", SensorID);
      stream.writeAttribute("AmbientTemperature",
                            QString::number(AmbientTemperature));
      stream.writeAttribute("ObjectTemperature",
                            QString::number(ObjectTemperature));
      stream.writeEndElement();
    }
    stream.writeEndDocument();

    // 3. save xml
    file.close();
    return true;
  }
};

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  Sensor sensor;
  sensor.SensorID = "45DS4HBNL981";
  sensor.AmbientTemperature = 45.76;
  sensor.ObjectTemperature = 7789.211;

  sensor.print();
  sensor.saveXML("test.xml");
  auto sensor2 = Sensor::fromXML("test.xml");
  sensor2.print();

  return a.exec();
}
