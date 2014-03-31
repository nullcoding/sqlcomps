#include "mainpage.h"
#include <cstdio>
#include <cassert>
#include <QTextStream>
#include <QPlainTextEdit>
#include <QMetaObject>
#include <QThread>
#include <QDebug>
#include <qglobal.h>
#include <QtMsgHandler>

QWidget         *DEBUG_MESSAGE_DISPLAY_WIDGET   = NULL;
QPlainTextEdit  *DEBUG_MESSAGE_DISPLAY_TEXTEDIT = NULL;
void setupDebugDisplay();
void debugMessageDisplayFunc(QtMsgType type, const QMessageLogContext &context, const QString &msg);

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    if (!createConnection())
        return 1;
    MainPage mp;
    mp.show();
#ifndef NO_DEBUG_WIDGET
    setupDebugDisplay();
    qDebug() << QString("If you can see this, the debug widget is working.");
    qDebug() << QString("Current working directory: %1").arg(QDir::currentPath());

#endif
    return app.exec();
}

void setupDebugDisplay()
{
    QWidget *widget = new QWidget();
    widget->setWindowTitle("NCS Inventory Management - Debug Log");
    widget->setWindowIcon(QIcon(":/ncs.jpg"));
    widget->setAttribute( Qt::WA_QuitOnClose, false ); //quit only when mainwindow is closed
    QBoxLayout* layout = new QVBoxLayout();
    widget->setLayout( layout );
    QPlainTextEdit *textEdit = new QPlainTextEdit( widget );
    QFont font = QFont( "Monospace" );
    font.setStyleHint(QFont::TypeWriter);
    textEdit->setFont( font );
    textEdit->setReadOnly(true);
    layout->addWidget( textEdit );
    widget->show();
    DEBUG_MESSAGE_DISPLAY_WIDGET   = widget;
    DEBUG_MESSAGE_DISPLAY_TEXTEDIT = textEdit;
    qInstallMessageHandler(debugMessageDisplayFunc);
}

void debugMessageDisplayFunc(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
  QByteArray localMsg = msg.toLocal8Bit();
    switch (type)
    {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        abort();
    }
  QTime now = QTime::currentTime();
  QString formattedMessage =
    QString::fromLatin1("%1 %2").arg(now.toString("hh:mm:ss:zzz")).arg(localMsg.constData());//.arg(msg);
  // print on console:
  fprintf( stderr, "%s\n", formattedMessage.toLocal8Bit().constData() );
  // print in debug log window
    bool isMainThread = QThread::currentThread() == QApplication::instance()->thread();
    if(DEBUG_MESSAGE_DISPLAY_TEXTEDIT)
    {
      if(isMainThread)
      {
        DEBUG_MESSAGE_DISPLAY_TEXTEDIT->appendPlainText(formattedMessage);
      }
      else // additional code, so that qDebug calls in threads will work as well
      {
        QMetaObject::invokeMethod(DEBUG_MESSAGE_DISPLAY_TEXTEDIT, "appendPlainText", Qt::QueuedConnection, Q_ARG(QString, formattedMessage));
      }
    }
}
/*
void debugMessageDisplayFunc(QtMsgType type, const char *msg)
{
  bool do_abort = false;
  const char* msgTypeStr = NULL;
  switch (type) {
    case QtDebugMsg:
      msgTypeStr = "Debug";
      break;
    case QtWarningMsg:
      msgTypeStr = "Warning";
      break;
    case QtCriticalMsg:
      msgTypeStr = "Critical";
      break;
    case QtFatalMsg:
      msgTypeStr = "Fatal";
      do_abort = true;
    default:
      assert(0);
      return;
  }
  QTime now = QTime::currentTime();
  QString formattedMessage =
    QString::fromLatin1("%1 %2 %3")
    .arg(now.toString("hh:mm:ss:zzz"))
    .arg(msgTypeStr).arg(msg);
  // print on console:
  fprintf( stderr, "%s\n", formattedMessage.toLocal8Bit().constData() );
  // print in debug log window
  {

    bool isMainThread = QThread::currentThread() == QApplication::instance()->thread();
    if(DEBUG_MESSAGE_DISPLAY_TEXTEDIT)
    {
      if( isMainThread )
        DEBUG_MESSAGE_DISPLAY_TEXTEDIT->appendPlainText( formattedMessage );
      else // additional code, so that qDebug calls in threads will work aswell
        QMetaObject::invokeMethod( DEBUG_MESSAGE_DISPLAY_TEXTEDIT, "appendPlainText", Qt::QueuedConnection, Q_ARG( QString, formattedMessage ) );
    }
  }
}
*/
