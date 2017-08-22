#include "HTMLButcher2/Project/ButcherProject.h"
#include "HTMLButcher2/Core/ButcherException.h"

namespace HTMLButcher2 {
namespace Project {

ButcherProject::ButcherProject() :
	QObject(), _filename(), _isopen(false), _modified(false)
{

}

void ButcherProject::newProject()
{
	close();

	_filename = "";
	_modified = true;

	_isopen = true;

	emit onNew();
	emit onChanged();
}

void ButcherProject::close()
{
	if (_isopen)
	{
		emit onClosing();

		_filename = "";
		_modified = false;

		_isopen = false;

		emit onClose();
		emit onChanged();
	}
}

void ButcherProject::open(const QString &filename)
{
	close();

	doLoad(filename);
	_filename = filename;
	_isopen = true;
	_modified = true;

	emit onOpen();
	emit onChanged();
}

void ButcherProject::save(bool force)
{
	if (!_modified && !force)
		return;

	if (_filename.isEmpty())
		throw Core::ButcherException(tr("File name not specified"));

	doSave(_filename);

	_modified = true;

	emit onSave();
	emit onChanged();
}

void ButcherProject::saveAs(const QString &filename, bool force)
{
	_filename = filename;
	save(force);
}

bool ButcherProject::isOpen()
{
	return _isopen;
}

bool ButcherProject::isModified()
{
	return _modified;
}

const QString &ButcherProject::filename()
{
	return _filename;
}

void ButcherProject::doLoad(const QString &filename)
{

}

void ButcherProject::doSave(const QString &filename)
{

}

} } // HTMLButcher2::Project