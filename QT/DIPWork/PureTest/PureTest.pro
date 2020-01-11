TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        funcclass.cpp \
        main.cpp

CONFIG += debug_and_release

QMAKE_CXXFLAGS += -Wno-unused-paramter
QMAKE_CXXFLAGS += -Wno-unused-variable

CONFIG(debug,debug|release){
INCLUDEPATH += $$(OPENCV_DEBUG_PATH)/include \
                $$(OPENCV_DEBUG_PATH)/include/opencv2 \

LIBS += $$(OPENCV_DEBUG_PATH)/x64/mingw/lib/libopencv_*.a

}

CONFIG(release,debug|release){

INCLUDEPATH += $$(OPENCV_PATH)/include \
                $$(OPENCV_PATH)/include/opencv2 \

LIBS += $$(OPENCV_PATH)/x64/mingw/lib/libopencv_*.a

}

HEADERS += \
    funcclass.h
