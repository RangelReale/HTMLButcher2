#pragma once

#include <QMainWindow>
#include <QAction>

namespace HTMLButcher2
{

class HTMLButcherMain : public QMainWindow
{
	Q_OBJECT
public:
	HTMLButcherMain(QWidget *parent = NULL);


private:
	void createActions();
	void createToolBars();
	void createMenus();
public Q_SLOTS:
	//
	// MENUS
	//
	void onMenuFileNew(bool checked = false);
	void onMenuFileOpen(bool checked = false);
	void onMenuFileClose(bool checked = false);
	void onMenuFileSave(bool checked = false);
	void onMenuFileSaveAs(bool checked = false);
	void onMenuFileSaveForWeb(bool checked = false);
	void onMenuFileSaveAllForWeb(bool checked = false);
	void onMenuFilePreferences(bool checked = false);

	void onMenuToolsInserHorLine(bool checked = false);
	void onMenuToolsInserVerLine(bool checked = false);
	void onMenuToolsMoveLine(bool checked = false);
	void onMenuToolsDeleteLine(bool checked = false);
	void onMenuToolsInsertAreaGlobal(bool checked = false);
	void onMenuToolsDeleteAreaGlobal(bool checked = false);
	void onMenuToolsInsertAreaMap(bool checked = false);
	void onMenuToolsDeleteAreaMap(bool checked = false);
	void onMenuToolsCancelOperation(bool checked = false);

private:
	QAction *filemenu_new, *filemenu_open, *filemenu_save;
};

} // namespace HTMLButcher2