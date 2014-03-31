#include "dbg.h"

DebugWidget::DebugWidget()
{
    this->setWindowTitle("Debug Log");
    this->setAttribute( Qt::WA_QuitOnClose, false ); //quit only when main window is closed
    QBoxLayout* layout = new QVBoxLayout();
    this->setLayout(layout);
    QPlainTextEdit *textEdit = new QPlainTextEdit(this);
    QFont font = QFont("Monospace");
    font.setStyleHint(QFont::TypeWriter);
    textEdit->setFont(font);
    textEdit->setReadOnly(true);
    layout->addWidget(textEdit);
    this->show();
    DEBUG_DISPLAY = textEdit;
}

DebugWidget::~DebugWidget()
{
	this->hide();
}

/*void setupDebugDisplay()
{
    QWidget *widget = new QWidget();
    widget->setWindowTitle( "Debug Log" );
    widget->setAttribute( Qt::WA_QuitOnClose, false ); //quit only when main window is closed
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
}*/
