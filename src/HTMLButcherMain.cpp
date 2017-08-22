#include "HTMLButcher2/HTMLButcherMain.h"

#include <QMenuBar>
#include <QMenu>

namespace HTMLButcher2
{

HTMLButcherMain::HTMLButcherMain(QWidget *parent) :
	QMainWindow(parent)
{
	setWindowIcon(QIcon(":/hbico_48.png"));

	createMenus();
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

	QAction *filemenu_new = new QAction(tr("&New"), this);
	filemenu_new->setShortcut(QKeySequence::New);
	connect(filemenu_new, &QAction::triggered, this, &HTMLButcherMain::onMenuFileNew);
	filemenu->addAction(filemenu_new);

	QAction *filemenu_open = new QAction(tr("&Open"), this);
	filemenu_open->setShortcut(QKeySequence::Open);
	connect(filemenu_open, &QAction::triggered, this, &HTMLButcherMain::onMenuFileOpen);
	filemenu->addAction(filemenu_open);

	QAction *filemenu_close = new QAction(tr("C&lose"), this);
	filemenu_close->setShortcut(QKeySequence::Close);
	connect(filemenu_close, &QAction::triggered, this, &HTMLButcherMain::onMenuFileClose);
	filemenu->addAction(filemenu_close);

	QAction *filemenu_save = new QAction(tr("&Save"), this);
	filemenu_save->setShortcut(QKeySequence::Save);
	connect(filemenu_save, &QAction::triggered, this, &HTMLButcherMain::onMenuFileSave);
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

} // namespace HTMLButcher2