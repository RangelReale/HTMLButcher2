#pragma once

#include <QMainWindow>

namespace HTMLButcher2
{

class HTMLButcherMain : public QMainWindow
{
	Q_OBJECT
public:
	HTMLButcherMain(QWidget *parent = NULL);


private:
	//
	// MENUS
	//
	void createMenus();
public Q_SLOTS:
	void onMenuFileNew(bool checked = false);
	void onMenuFileOpen(bool checked = false);
	void onMenuFileClose(bool checked = false);
	void onMenuFileSave(bool checked = false);
	void onMenuFileSaveAs(bool checked = false);
	void onMenuFileSaveForWeb(bool checked = false);
	void onMenuFileSaveAllForWeb(bool checked = false);
	void onMenuFilePreferences(bool checked = false);
};

} // namespace HTMLButcher2