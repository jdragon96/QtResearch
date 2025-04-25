#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QVariantMap>

class Sensor {
public:
  QString SensorID;
  double AmbientTemperature;
  double ObjectTemperature;

  void print() {
    qInfo() << "********************************";
    qInfo() << "SensorID : " << SensorID;
    qInfo() << "AmbientTemperature : " << AmbientTemperature;
    qInfo() << "ObjectTemperature : " << ObjectTemperature;
    qInfo() << "********************************";
  }

  QJsonObject toJson() const {
    QJsonObject obj;
    obj["SensorID"] = SensorID;
    obj["AmbientTemperature"] = AmbientTemperature;
    obj["ObjectTemperature"] = ObjectTemperature;
    return obj;
  }

  static Sensor fromJson(const QJsonObject &obj) {
    Sensor p;
    p.SensorID = obj["SensorID"].toString();
    p.AmbientTemperature = obj["AmbientTemperature"].toDouble();
    p.ObjectTemperature = obj["ObjectTemperature"].toDouble();
    return p;
  }

  static Sensor fromJson(const QString path) {
    // 1. open file
    QFile file(path);
    file.open(QIODevice::ReadOnly);

    // 2. read data
    QByteArray data = file.readAll();
    file.close();

    // 3. parsing json
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);
    if (doc.isNull()) {
      qWarning() << "Failed to parse JSON:" << parseError.errorString();
      return Sensor();
    }

    if (!doc.isObject()) {
      qWarning() << "JSON root is not JSON Object";
      return Sensor();
    }

    if (!file.open(QIODevice::ReadOnly)) {
      qWarning() << "Failed to open JSON file:" << file.errorString();
      return Sensor();
    }

    // 4. json to class
    Sensor p;
    p.SensorID = doc["SensorID"].toString();
    p.AmbientTemperature = doc["AmbientTemperature"].toDouble();
    p.ObjectTemperature = doc["ObjectTemperature"].toDouble();
    return p;
  }

  bool saveJson(QString path) {
    // 1. class to json document
    QJsonDocument doc(toJson());

    // 2. open file
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
      qWarning() << "Failed to open JSON file:" << file.errorString();
      return false;
    }

    // 3. write json
    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();
    return true;
  }
};

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);
  auto sensor = Sensor::fromJson("test.json");
  sensor.print();
  sensor.saveJson("test2.json");
  return a.exec();
}
