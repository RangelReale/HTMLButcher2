#include "HTMLButcher2/HTMLButcherSplash.h"

#include <QPixmap>
#include <QTimer>

namespace HTMLButcher2
{

HTMLButcherSplash::HTMLButcherSplash() :
	QSplashScreen()
{
	setPixmap(QPixmap(":/hb_splash.png"));

	QTimer::singleShot(2500, this, SLOT(close()));
}

void HTMLButcherSplash::mousePressEvent(QMouseEvent *event)
{
	QSplashScreen::mousePressEvent(event);
	close();
}

void HTMLButcherSplash::keyPressEvent(QKeyEvent *event)
{
	QSplashScreen::keyPressEvent(event);
	close();
}

} // namespace HTMLButcher2