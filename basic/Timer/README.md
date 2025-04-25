# Timer

## 1. MyTimer

- 현재 쓰레드의 이벤트 루프를 통해 비동기 처리를 수행
    - 이벤트루프는 QApplication 객체가 생성

```c++
#include <QApplication>
#include <QDebug>

#include "MyTimer.h"

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  MyTimer t;
  t.dostuff();
  qInfo() << "Do Something!";

  return a.exec();
}
```

```bash
Do Something!
"17:50:19"
"17:50:20"
"17:50:21"
"17:50:22"
"17:50:23"
Complete!
```

## 2. FileSystemWatcher

- 파일 및 폴더 변경을 감지

```c++
#include "watcher.h"
#include <QCoreApplication>

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);
  Watcher w;
  return a.exec();
}
```
```bash

```