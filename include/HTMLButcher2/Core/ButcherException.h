#pragma once

#include <QString>

#include <stdexcept>

namespace HTMLButcher2 {
namespace Core {

class ButcherException : public std::runtime_error
{
public:
	ButcherException(const QString &message) :
		std::runtime_error(message.toStdString()), _message(message) {}

	ButcherException(const std::string &message) :
		std::runtime_error(message), _message(QString::fromStdString(message)) {}

	const QString &message() { return _message; }
private:
	QString _message;
};

} } // HTMLButcher::Core