#pragma once

#include <QObject>

namespace HTMLButcher2 {
namespace Project {

class ButcherProject : public QObject
{
	Q_OBJECT
public:
	ButcherProject();

	void newProject();
	void close();

	void open(const QString &filename);
	void save(bool force = false);
	void saveAs(const QString &filename, bool force = false);

	bool isOpen();
	bool isModified();

	const QString &filename();
Q_SIGNALS:
	void onNew();
	void onClosing();
	void onClose();
	void onOpen();
	void onSave();

	void onChanged();
private:
	void doLoad(const QString &filename);
	void doSave(const QString &filename);

	QString _filename;
	bool _isopen;
	bool _modified;
};

} } // HTMLButcher2::Project