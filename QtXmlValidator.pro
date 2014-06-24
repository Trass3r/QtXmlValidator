TEMPLATE = app
TARGET = QtXmlValidator

SOURCES += main.cpp

QT += xml xmlpatterns

win32 {
	CONFIG += console
}