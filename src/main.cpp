#include "HTMLButcher2/HTMLButcherMain.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	app.setOrganizationName("SIB IT");
	app.setApplicationName("HTMLButcher2");
	app.setOrganizationDomain("sibit.com.br");

	HTMLButcher2::HTMLButcherMain window;
	window.show();

	return app.exec();
}

#ifdef WIN32
#include <Windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	return main(__argc, __argv);
}
#endif
