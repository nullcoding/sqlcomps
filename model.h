#ifndef MODEL_H
#define MODEL_H

#include <QtWidgets>
#include <QtSql>

#include "db.h"

void initializeModel(QSqlTableModel *model);
QTableView *createView(QSqlTableModel *model);

QSqlTableModel *setupModel(int category);

#endif // MODEL_H
