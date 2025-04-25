#include "watcher.h"
#include <QCoreApplication>

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);
  Watcher w;
  return a.exec();
}