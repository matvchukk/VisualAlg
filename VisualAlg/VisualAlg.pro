QT += quick

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        SortingAlg/List/list.cpp \
        SortingAlg/List/list.cpp \
        SortingAlg/Sorts/bubbleSort.cpp \
        SortingAlg/Sorts/complexityvisitor.cpp \
        SortingAlg/Sorts/listofsteps.cpp \
        SortingAlg/Sorts/quickSort.cpp \
        SortingAlg/Sorts/selectionSort.cpp \
        SortingAlg/Sorts/sort.cpp \
        SortingAlg/Sorts/sortdecorator.cpp \
        SortingAlg/Sorts/sortvisitor.cpp \
        SortingAlg/Sorts/step.cpp \
        SortingAlg/Sorts/timingsortdecorator.cpp \
        Tests/TestSorting/sortingTests.cpp \
        Tests/TestTrees/treeTest.cpp \
        TreeAlg/avltree.cpp \
        TreeAlg/avltreecreator.cpp \
        TreeAlg/colordecorator.cpp \
        TreeAlg/heightdecorator.cpp \
        TreeAlg/redblacktree.cpp \
        TreeAlg/redblacktreecreator.cpp \
        TreeAlg/tree.cpp \
        TreeAlg/treecreator.cpp \
        TreeAlg/treeiterator.cpp \
        TreeAlg/treenode.cpp \
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
    PatternsSearching/RabinKarp.h \
    SortingAlg/List/list.h \
    SortingAlg/List/list.h \
    SortingAlg/Sorts/bubbleSort.h \
    SortingAlg/Sorts/complexityvisitor.h \
    SortingAlg/Sorts/listofsteps.h \
    SortingAlg/Sorts/quickSort.h \
    SortingAlg/Sorts/selectionSort.h \
    SortingAlg/Sorts/sort.h \
    SortingAlg/Sorts/sortdecorator.h \
    SortingAlg/Sorts/sortvisitor.h \
    SortingAlg/Sorts/step.h \
    SortingAlg/Sorts/timingsortdecorator.h \
    Tests/doctest.h \
    TreeAlg/avltree.h \
    TreeAlg/avltreecreator.h \
    TreeAlg/colordecorator.h \
    TreeAlg/heightdecorator.h \
    TreeAlg/redblacktree.h \
    TreeAlg/redblacktreecreator.h \
    TreeAlg/tree.h \
    TreeAlg/treecreator.h \
    TreeAlg/treeiterator.h \
    TreeAlg/treenode.h
