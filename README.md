# Qt Research


## 1. Qt 설치

### 1.1. Windows Qt6 설치하기

- https://www.qt.io/download-open-source 접속
- `Download the Qt Online Installer` 버튼 클릭

### 1.2. 빌드 옵션 체크

- `Edit` - `Preference` - `Kits` 매뉴 클릭
    - Auto-detected 된 빌드 옵션이 있는지 확인한다.


## 2. Qt 핵심 개념

### 2.1. MOC

- MOC(Meta-Object Compiler)는 `Slot/Signal` 매커니즘과 런타임 타입 정보를 지원하기 위한 메크로
    - `Signal/Slot`, `Property`, `metaObject` 관련 C++ 코드를 자동생성 해줌
    - 자동 생성된 C++ 코드는 `moc_<Class 이름>.cpp` 파일로 생성
    - 동작 흐름
        1. 헤더 파일에 `Q_OBJECT` 선언
        2. 빌드 시스템은 자동으로 MOC를 호출, 헤더파일 파싱
        3. `moc_*.cpp` 파일 생성
        4. `moc_*.cpp` 파일 컴파일, 최종 바이너리에 링크

### 2.2. 

## 2. 이야깃 거리

### 2.1. STL vs Qt

- 개인적으론 Qt 앱이라면 Qt의 기능을 사용하는 것이 바람직하다고 생각
    - Qt 마이그레이션이 필요한 경우, STL은 큰 단점이될 가능성이 큼

### 2.2. QMake vs CMake

- 