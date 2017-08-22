#pragma once

#include <QObject>

namespace HTMLButcher2 {
namespace Project {

class ButcherProject : public QObject
{
	Q_OBJECT
public:
	ButcherProject();

	void New();

Q_SIGNALS:

};

} } // HTMLButcher2::Project