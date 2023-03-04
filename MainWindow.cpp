// Create the MainWindow
#include "MainWindow.h"
#include "BudgetModel.h"

BudgetMainWindow::BudgetMainWindow(QTableWidget *centWidget,
                                   std::vector<QDockWidget *> dockWidgets) {
  centralWidget = centWidget;
  widgets = dockWidgets;
}

QMainWindow *BudgetMainWindow::createMainWindow() {
  QMainWindow *mainWindow = new QMainWindow();

  mainWindow->setCentralWidget(centralWidget);

  for (auto &widget : widgets) {
    mainWindow->addDockWidget(Qt::TopDockWidgetArea, widget);
  }
  return mainWindow;
}

std::vector<QDockWidget *> BudgetMainWindow::setWidgets() {

  QPushButton *button1 = new QPushButton("Push me Bitch");
  QPushButton *button2 = new QPushButton("You won't");

  QDockWidget *dock1 = new QDockWidget("Button1");
  QDockWidget *dock2 = new QDockWidget("Button2");

  dock1->setWidget(button1);
  dock2->setWidget(button2);

  std::vector<QDockWidget *> widgets = {dock1, dock2};
  return widgets;
}
