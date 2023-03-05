// mymodel.h
#include <QAbstractTableModel>
#include <QComboBox>
#include <QString>
#include <QStringList>
#include <QTableWidget>

QTableWidget *createTransactionTable(int dim);
QTableWidget *addRows(int number, QTableWidget *table);
std::vector<std::vector<QString>> *readData(QTableWidget *table);
