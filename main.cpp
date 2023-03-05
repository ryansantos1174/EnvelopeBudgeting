#include "BudgetModel.h"
#include "MainWindow.h"
#include "XML_Handler.h"
#include <QApplication>
#include <QTableWidget>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  QTableWidget *table = createTransactionTable(8);

  QFile *file = new QFile("budget.xml");
  BudgetMainWindow *main = new BudgetMainWindow(file, table);
  main->createMainWindow();
  main->showWindow();

  return a.exec();
}
