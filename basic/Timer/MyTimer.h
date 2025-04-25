#ifndef MYTIMER_H
#define MYTIMER_H

#include <QDebug>
#include <QObject>
#include <QTime>
#include <QTimer>

class MyTimer : public QObject {

  Q_OBJECT
public:
  explicit MyTimer(QObject *parent = nullptr);

signals:

public slots:
  void timeout();
  void dostuff();

private:
  QTimer timer;
  int number;
};

#endif // MYTIMER_H
