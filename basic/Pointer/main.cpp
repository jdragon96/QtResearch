#include <QApplication>
#include <QList>
#include <QMap>
#include <QScopedPointer>
#include <QSharedPointer>

#include <functional>
#include <vector>

#include "Printer.h"
#include "Test.h"
#include "cat.h"
#include "toy.h"

void ScopedPointerTest() {
  QScopedPointer<Test> sp(new Test());
  sp->setObjectName("ScopedPointer");

  qInfo() << "Scoped Pointer : " << &sp;
  qInfo() << "Pointer Data : " << sp.data();
  qInfo() << "Object Name : " << sp->objectName();
}

void SharedPointerTest() {
  QSharedPointer<Test> sp(new Test());
  sp->setObjectName("SharedPointer");

  qInfo() << "Shared Pointer : " << &sp;
  qInfo() << "Pointer Data : " << sp.data();
  qInfo() << "Object Name : " << sp->objectName();
}

void PointerShaderTest() {
  std::vector<QSharedPointer<Cat>> cats(5);
  QSharedPointer<Toy> toy(new Toy());
  for (int i = 0; i < 5; ++i) {
    cats[i].reset(new Cat());
    cats[i]->play(toy);
  }
  cats[4]->play(nullptr);
}

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);
  Printer("Started ScopedPointer", "Ended ScopedPointer",
          []() { ScopedPointerTest(); });
  Printer("Started SharedPointer", "Ended SharedPointer",
          []() { SharedPointerTest(); });
  PointerShaderTest();
  return a.exec();
}
