QT += quick

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        SortingAlg/List/list.cpp \
        SortingAlg/List/list.cpp \
        SortingAlg/Sorts/managersort.cpp \
        SortingAlg/Sorts/managersortwrapper.cpp \
        main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    SortingAlg/List/list.h \
    SortingAlg/List/list.h \
    SortingAlg/Sorts/bubbleSort.h \
    SortingAlg/Sorts/managersort.h \
    SortingAlg/Sorts/managersortwrapper.h \
    SortingAlg/Sorts/mergeSort.h \
    SortingAlg/Sorts/sort.h
