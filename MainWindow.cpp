// Create the MainWindow
#include "MainWindow.h"
#include "BudgetModel.h"
#include <iostream>

//
BudgetMainWindow::BudgetMainWindow(QFile *file, QTableWidget *tableWidget) {
  table = tableWidget;
  mainWindow = new QMainWindow();
  toolbar = new QToolBar();
  xml = new xmlHandler(file);
}

void BudgetMainWindow::createMainWindow() {
  // Defining Buttons
  saveButton = new QPushButton("Save Filessss", this);
  addLineButton = new QPushButton("Add Lines to Table", this);

  // Adding buttons to toolbar
  toolbar->addWidget(saveButton);
  toolbar->addWidget(addLineButton);

  // Connect Buttons
  connect(addLineButton, &QPushButton::released, this,
          &BudgetMainWindow::handleRowButton);
  connect(saveButton, &QPushButton::released, this,
          &BudgetMainWindow::handleSaveButton);
  std::cout << "Connected buttons" << std::endl;

  // Adding toolbar to main window
  mainWindow->setCentralWidget(table);
  mainWindow->addToolBar(Qt::TopToolBarArea, toolbar);
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

// Used to add numberCells to table
void BudgetMainWindow::addCells(int numberCells) {
  std::cout << "You clicked the buttons" << std::endl;
  // Get current cell count
  int currentCells = table->rowCount();
  // Increase table row count
  table->setRowCount(currentCells + numberCells);
}

void BudgetMainWindow::handleRowButton() {
  addLineButton->setText("You Clicked Me");
  addLineButton->resize(100, 100);
  table = addRows(20, table);
}

void BudgetMainWindow::handleSaveButton() {
  std::cout << "About to read Data" << std::endl;
  std::cout << table->item(1, 1) << std::endl;
  std::vector<std::vector<QString>> *outputData = readData(table);
  // std::vector<std::vector<QString>> *output_ptr = &outputData;
  //  FIXME finish implementing this
  std::cout << "Right before Writing" << std::endl;
  xml->writeToFile(outputData);
}

void BudgetMainWindow::readTableData() { readData(table); }

void BudgetMainWindow::showWindow() { mainWindow->show(); }
