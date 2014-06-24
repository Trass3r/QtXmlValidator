
#include <QCoreApplication>
#include <QStringList>
#include <QFile>
#include <QXmlSchema>
#include <QXmlSchemaValidator>
#include <QUrl>
#include <stdio.h>

int main(int argc, char* argv[])
{
	QCoreApplication app(argc, argv);

	QStringList args = app.arguments();
	if (args.size() != 3)
	{
		printf("Usage: QtXmlValidator input.xsd input.xml\n");
		return -1;
	}

	QXmlSchema schema;

	schema.load(QUrl::fromLocalFile(args[1]));
	if (!schema.isValid())
	{
		printf("schema not valid\n");
		return -2;
	}

	QXmlSchemaValidator validator(schema);
	if (validator.validate(QUrl::fromLocalFile(args[2])))
		printf("valid xml!\n");
	else
		printf("invalid xml!\n");
}