#pragma once

#include <QSplashScreen>
#include <QMouseEvent>
#include <QKeyEvent>

namespace HTMLButcher2
{

class HTMLButcherSplash : public QSplashScreen
{
public:
	HTMLButcherSplash();
protected:
	void mousePressEvent(QMouseEvent *event) override;
	void keyPressEvent(QKeyEvent *event) override;
};

}
