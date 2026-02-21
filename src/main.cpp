#include "CalculatorWindow.hpp"

#include <QGuiApplication>
#include <QUrl>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWindow>
#include <QFontDatabase>

int main(int argc, char ** argv)
{
	QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine;

	CalculatorWindow calcWindow;

	int id = QFontDatabase::addApplicationFont(":/font/OpenSans-SemiBold.ttf");
	if (id == -1) {
		qDebug() << "Failed to load font!";
	} else {
		QStringList families = QFontDatabase::applicationFontFamilies(id);
		if (!families.isEmpty()) {
			QString family = families.at(0);
			QFont defaultFont(family);
			QGuiApplication::setFont(defaultFont);
		}
	}
	
	engine.rootContext()->setContextProperty("calculator", &calcWindow);
	engine.load(QUrl(QStringLiteral("qrc:/MainMenu.qml")));

	return app.exec();
}