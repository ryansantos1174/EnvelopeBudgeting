// mymodel.h
#include <QAbstractTableModel>
#include <QComboBox>
#include <QStringList>
#include <QTableWidget>

QTableWidget *createTransactionTable(int dim);
QTableWidget *addRows(int number, QTableWidget *table);
