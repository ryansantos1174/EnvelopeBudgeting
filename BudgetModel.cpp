// File that implements custom table view for budget
#include "BudgetModel.h"
#include <iostream>

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
  QStringList categories = {"Housing", "Food", "Pets", "Transportation"};
  int currentRows = table->rowCount();
  table->setRowCount(currentRows + number);

  for (int j = currentRows; j <= currentRows + number; j++) {
    QComboBox *transactionCategories = new QComboBox();
    transactionCategories->addItems(categories);
    table->setCellWidget(j, 3, transactionCategories);
  }
  return table;
};

std::vector<std::vector<QString>> *readData(QTableWidget *table) {
  // // Loop through items in table
  int rows = table->rowCount();
  int columns = table->columnCount();
  std::vector<std::vector<QString>> *outputData =
      new std::vector<std::vector<QString>>;

  std::vector<QString> rowData = {};
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      QTableWidgetItem *a = table->item(i, j);
      if (a != nullptr) { // Needs to check if item return nullptr otherwise
                          // memory error occurs
        rowData.push_back(table->item(i, j)->text());
      }
    }
    outputData->push_back(rowData);
    rowData.clear();
  }
  std::cout << "Finished" << std::endl;
  return outputData;
}
