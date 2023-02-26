// main.cpp
#include "BudgetModel.h"
#include <QApplication>
#include <QTableView>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  QTableView tableView;
  BudgetModel budget;
  tableView.setModel(&budget);
  tableView.show();
  return a.exec();
}
