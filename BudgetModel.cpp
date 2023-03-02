// File that implements custom table view for budget
#include "BudgetModel.h"

QTableWidget *createTransactionTable(int dim) {
  QTableWidget *table = new QTableWidget(dim, 4);
  QStringList heading = {"Date", "Price", "Description", "Category"};

  QStringList categories = {"Housing", "Food", "Pets", "Transportation"};

  table->setHorizontalHeaderLabels(heading);

  // Hard coded initially
  for (int j = 0; j <= table->rowCount(); j++) {
    QComboBox *transactionCategories = new QComboBox();
    transactionCategories->addItems(categories);
    table->setCellWidget(j, 3, transactionCategories);
  }

  return table;
}

// Add number amount of rows to table
QTableWidget *addRows(int number, QTableWidget *table) {
  int currentRows = table->rowCount();
  table->setRowCount(currentRows + number);
  return table;
};
