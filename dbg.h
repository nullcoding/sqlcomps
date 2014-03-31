#ifndef DBG_H
#define DBG_H

#include <cstdio>
#include <cassert>
#include <QTextStream>
#include <QPlainTextEdit>
#include <QMetaObject>

class DebugWidget : public QWidget
{
	Q_OBJECT

public:
	DebugWidget();
	~DebugWidget();
	QPlainTextEdit *DEBUG_DISPLAY;
};

void debugMessageDisplayFunc(QtMsgType type, const QMessageLogContext &context, const QString &msg);

//QWidget *DEBUG_MESSAGE_DISPLAY_WIDGET;

#endif
