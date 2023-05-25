QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calculate.cpp \
    canset.cpp \
    curve_monitoring.cpp \
    data.cpp \
    error_log.cpp \
    fixed_value_setting.cpp \
    keyboard.cpp \
    main.cpp \
    mainwindow.cpp \
    monitoring_interface.cpp \
    output_monitoring.cpp \
    parameter_setting.cpp \
    popupwindow01.cpp \
    popupwindow02.cpp \
    popupwindow03.cpp \
    popupwindow04.cpp \
    popupwindow05.cpp \
    popupwindow06.cpp \
    popupwindow07.cpp \
    program_editing.cpp \
    program_loop.cpp \
    qcustomplot.cpp \
    userpasswordpage01.cpp \
    userpasswordpage02.cpp \
    userpasswordpage03.cpp

HEADERS += \
    calculate.h \
    canset.h \
    curve_monitoring.h \
    data.h \
    error_log.h \
    fixed_value_setting.h \
    keyboard.h \
    mainwindow.h \
    monitoring_interface.h \
    output_monitoring.h \
    parameter_setting.h \
    popupwindow01.h \
    popupwindow02.h \
    popupwindow03.h \
    popupwindow04.h \
    popupwindow05.h \
    popupwindow06.h \
    popupwindow07.h \
    program_editing.h \
    program_loop.h \
    qcustomplot.h \
    userpasswordpage01.h \
    userpasswordpage02.h \
    userpasswordpage03.h

FORMS += \
    calculate.ui \
    canset.ui \
    curve_monitoring.ui \
    error_log.ui \
    fixed_value_setting.ui \
    keyboard.ui \
    mainwindow.ui \
    monitoring_interface.ui \
    output_monitoring.ui \
    parameter_setting.ui \
    popupwindow01.ui \
    popupwindow02.ui \
    popupwindow03.ui \
    popupwindow04.ui \
    popupwindow05.ui \
    popupwindow06.ui \
    popupwindow07.ui \
    program_editing.ui \
    program_loop.ui \
    userpasswordpage01.ui \
    userpasswordpage02.ui \
    userpasswordpage03.ui

#LIBS += -ldl

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
