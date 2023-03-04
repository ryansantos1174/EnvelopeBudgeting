#include "BudgetModel.h"
#include "MainWindow.h"
#include <QApplication>
#include <QTableWidget>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  QTableWidget *table = createTransactionTable(8);

  QPushButton *button1 = new QPushButton("Push me Bitch");
  QPushButton *button2 = new QPushButton("You won't");

  QDockWidget *dock1 = new QDockWidget("Button1");
  QDockWidget *dock2 = new QDockWidget("Button2");

  dock1->setWidget(button1);
  dock2->setWidget(button2);

  std::vector<QDockWidget *> widgets = {dock1, dock2};

  BudgetMainWindow *main = new BudgetMainWindow(table, widgets);
  QMainWindow *mainWindow = main->createMainWindow();
  mainWindow->show();
  return a.exec();
}
