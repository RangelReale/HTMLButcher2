#include "HTMLButcher2/HTMLButcherMain.h"

#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QLabel>

namespace HTMLButcher2
{

HTMLButcherMain::HTMLButcherMain(QWidget *parent) :
	QMainWindow(parent)
{
	setWindowIcon(QIcon(":/hbico_48.png"));

	createActions();
	createMenus();
	createToolBars();
}

void HTMLButcherMain::createActions()
{
	filemenu_new = new QAction(tr("&New"), this);
	filemenu_new->setShortcut(QKeySequence::New);
	filemenu_new->setIcon(QIcon(":/ico_new.png"));
	filemenu_new->setIconVisibleInMenu(false);
	connect(filemenu_new, &QAction::triggered, this, &HTMLButcherMain::onMenuFileNew);

	filemenu_open = new QAction(tr("&Open"), this);
	filemenu_open->setShortcut(QKeySequence::Open);
	filemenu_open->setIcon(QIcon(":/ico_open.png"));
	filemenu_open->setIconVisibleInMenu(false);
	connect(filemenu_open, &QAction::triggered, this, &HTMLButcherMain::onMenuFileOpen);

	filemenu_save = new QAction(tr("&Save"), this);
	filemenu_save->setShortcut(QKeySequence::Save);
	filemenu_save->setIcon(QIcon(":/ico_save.png"));
	filemenu_save->setIconVisibleInMenu(false);
	connect(filemenu_save, &QAction::triggered, this, &HTMLButcherMain::onMenuFileSave);
}

void HTMLButcherMain::createToolBars()
{
	//
	// FILE
	//
	QToolBar *filetb = new QToolBar(tr("File"), this);
	addToolBar(Qt::TopToolBarArea, filetb);

	filetb->addAction(filemenu_new);
	filetb->addAction(filemenu_open);
	filetb->addAction(filemenu_save);

	//
	// VIEW
	//
	QToolBar *viewtb = new QToolBar(tr("View"), this);
	addToolBar(Qt::TopToolBarArea, viewtb);

	viewtb->addWidget(new QLabel(tr("View:"), this));

	//
	// TOOLS
	//
	QToolBar *toolstb = new QToolBar(tr("Tools"), this);
	addToolBar(Qt::LeftToolBarArea, toolstb);

	QAction *toolsmenu_inserthorline = new QAction(tr("Insert horizontal line"), this);
	toolsmenu_inserthorline->setIcon(QIcon(":/ico_insert_hline.png"));
	toolsmenu_inserthorline->setIconVisibleInMenu(false);
	connect(toolsmenu_inserthorline, &QAction::triggered, this, &HTMLButcherMain::onMenuToolsInserHorLine);
	toolstb->addAction(toolsmenu_inserthorline);

	QAction *toolsmenu_insertverline = new QAction(tr("Insert vertical line"), this);
	toolsmenu_insertverline->setIcon(QIcon(":/ico_insert_vline.png"));
	toolsmenu_insertverline->setIconVisibleInMenu(false);
	connect(toolsmenu_insertverline, &QAction::triggered, this, &HTMLButcherMain::onMenuToolsInserVerLine);
	toolstb->addAction(toolsmenu_insertverline);

	QAction *toolsmenu_moveline = new QAction(tr("Move line"), this);
	toolsmenu_moveline->setIcon(QIcon(":/ico_move_line.png"));
	toolsmenu_moveline->setIconVisibleInMenu(false);
	connect(toolsmenu_moveline, &QAction::triggered, this, &HTMLButcherMain::onMenuToolsMoveLine);
	toolstb->addAction(toolsmenu_moveline);

	QAction *toolsmenu_deleteline = new QAction(tr("Delete line"), this);
	toolsmenu_deleteline->setIcon(QIcon(":/ico_delete_line.png"));
	toolsmenu_deleteline->setIconVisibleInMenu(false);
	connect(toolsmenu_deleteline, &QAction::triggered, this, &HTMLButcherMain::onMenuToolsDeleteLine);
	toolstb->addAction(toolsmenu_deleteline);

	QAction *toolsmenu_insertgarea = new QAction(tr("Insert global area"), this);
	toolsmenu_insertgarea->setIcon(QIcon(":/ico_insert_garea.png"));
	toolsmenu_insertgarea->setIconVisibleInMenu(false);
	connect(toolsmenu_insertgarea, &QAction::triggered, this, &HTMLButcherMain::onMenuToolsInsertAreaGlobal);
	toolstb->addAction(toolsmenu_insertgarea);

	QAction *toolsmenu_deletegarea = new QAction(tr("Delete global area"), this);
	toolsmenu_deletegarea->setIcon(QIcon(":/ico_delete_garea.png"));
	toolsmenu_deletegarea->setIconVisibleInMenu(false);
	connect(toolsmenu_deletegarea, &QAction::triggered, this, &HTMLButcherMain::onMenuToolsDeleteAreaGlobal);
	toolstb->addAction(toolsmenu_deletegarea);

	QAction *toolsmenu_insertmarea = new QAction(tr("Insert map area"), this);
	toolsmenu_insertmarea->setIcon(QIcon(":/ico_insert_marea.png"));
	toolsmenu_insertmarea->setIconVisibleInMenu(false);
	connect(toolsmenu_insertmarea, &QAction::triggered, this, &HTMLButcherMain::onMenuToolsInsertAreaMap);
	toolstb->addAction(toolsmenu_insertmarea);

	QAction *toolsmenu_deletemarea = new QAction(tr("Delete map area"), this);
	toolsmenu_deletemarea->setIcon(QIcon(":/ico_delete_marea.png"));
	toolsmenu_deletemarea->setIconVisibleInMenu(false);
	connect(toolsmenu_deletemarea, &QAction::triggered, this, &HTMLButcherMain::onMenuToolsDeleteAreaMap);
	toolstb->addAction(toolsmenu_deletemarea);

	QAction *toolsmenu_cancelop = new QAction(tr("Cancel operation"), this);
	toolsmenu_cancelop->setIcon(QIcon(":/ico_cancel.png"));
	toolsmenu_cancelop->setIconVisibleInMenu(false);
	connect(toolsmenu_cancelop, &QAction::triggered, this, &HTMLButcherMain::onMenuToolsCancelOperation);
	toolstb->addAction(toolsmenu_cancelop);

}

/*********
 * MENUS
 ********/

void HTMLButcherMain::createMenus()
{
	//
	// FILE
	//
	QMenu *filemenu = menuBar()->addMenu(tr("&File"));

	filemenu->addAction(filemenu_new);

	filemenu->addAction(filemenu_open);

	QAction *filemenu_close = new QAction(tr("C&lose"), this);
	filemenu_close->setShortcut(QKeySequence::Close);
	connect(filemenu_close, &QAction::triggered, this, &HTMLButcherMain::onMenuFileClose);
	filemenu->addAction(filemenu_close);

	filemenu->addAction(filemenu_save);

	QAction *filemenu_saveas = new QAction(tr("Save &as..."), this);
	filemenu_saveas->setShortcut(QKeySequence::SaveAs);
	connect(filemenu_saveas, &QAction::triggered, this, &HTMLButcherMain::onMenuFileSaveAs);
	filemenu->addAction(filemenu_saveas);

	filemenu->addSeparator();

	QAction *filemenu_saveforweb = new QAction(tr("Save for &Web..."), this);
	filemenu_saveforweb->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_W));
	connect(filemenu_saveforweb, &QAction::triggered, this, &HTMLButcherMain::onMenuFileSaveForWeb);
	filemenu->addAction(filemenu_saveforweb);

	QAction *filemenu_saveallforweb = new QAction(tr("Save all for We&b..."), this);
	connect(filemenu_saveallforweb, &QAction::triggered, this, &HTMLButcherMain::onMenuFileSaveAllForWeb);
	filemenu->addAction(filemenu_saveallforweb);

	filemenu->addSeparator();

	QAction *filemenu_preferences = new QAction(tr("&Preferences..."), this);
	connect(filemenu_preferences, &QAction::triggered, this, &HTMLButcherMain::onMenuFilePreferences);
	filemenu->addAction(filemenu_preferences);

	filemenu->addSeparator();

	QAction *filemenu_exit = new QAction(tr("E&xit"), this);
	filemenu_exit->setShortcut(QKeySequence::Quit);
	filemenu_exit->setMenuRole(QAction::QuitRole);
	connect(filemenu_exit, &QAction::triggered, this, &HTMLButcherMain::close);
	filemenu->addAction(filemenu_exit);
}

//
// MENU: FILE
//

void HTMLButcherMain::onMenuFileNew(bool checked)
{

}

void HTMLButcherMain::onMenuFileOpen(bool checked)
{

}

void HTMLButcherMain::onMenuFileClose(bool checked)
{

}

void HTMLButcherMain::onMenuFileSave(bool checked)
{

}

void HTMLButcherMain::onMenuFileSaveAs(bool checked)
{

}

void HTMLButcherMain::onMenuFileSaveForWeb(bool checked)
{

}

void HTMLButcherMain::onMenuFileSaveAllForWeb(bool checked)
{

}

void HTMLButcherMain::onMenuFilePreferences(bool checked)
{

}

//
// MENU: TOOLS
//

void HTMLButcherMain::onMenuToolsInserHorLine(bool checked)
{

}

void HTMLButcherMain::onMenuToolsInserVerLine(bool checked)
{

}

void HTMLButcherMain::onMenuToolsMoveLine(bool checked)
{

}


void HTMLButcherMain::onMenuToolsDeleteLine(bool checked)
{

}

void HTMLButcherMain::onMenuToolsInsertAreaGlobal(bool checked)
{

}

void HTMLButcherMain::onMenuToolsDeleteAreaGlobal(bool checked)
{

}

void HTMLButcherMain::onMenuToolsInsertAreaMap(bool checked)
{

}

void HTMLButcherMain::onMenuToolsDeleteAreaMap(bool checked)
{

}

void HTMLButcherMain::onMenuToolsCancelOperation(bool checked)
{

}

} // namespace HTMLButcher2