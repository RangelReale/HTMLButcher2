#pragma once

#include <QSplashScreen>
#include <QMouseEvent>
#include <QKeyEvent>

namespace HTMLButcher2
{

class HTMLButcherSplash : public QSplashScreen
{
	Q_OBJECT
public:
	HTMLButcherSplash();
protected:
	void mousePressEvent(QMouseEvent *event) override;
	void keyPressEvent(QKeyEvent *event) override;
};

} // namespace HTMLButcher2
