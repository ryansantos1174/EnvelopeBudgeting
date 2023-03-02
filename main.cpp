#include "BudgetModel.h"
#include <QApplication>
#include <QTableWidget>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  QTableWidget *transactionTable = createTransactionTable(5);
  transactionTable->show();
  return a.exec();
}
