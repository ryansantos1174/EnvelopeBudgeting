#pragma once
#include "XML_Handler.h"
#include <QDockWidget>
#include <QFile>
#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>
#include <QToolBar>
#include <QWidget>
#include <vector>

class BudgetMainWindow : public QMainWindow {
  Q_OBJECT

public:
  // Constructor and destructors
  BudgetMainWindow(QFile *file, QTableWidget *tableWidget);
  virtual ~BudgetMainWindow(){};

  void createMainWindow();        // Used to add all widgets together
  void addCells(int numberCells); // Used to add more cells to the table
  void readTableData();
  std::vector<QDockWidget *> setWidgets(); // Sets the widgets in the toolbar
  void showWindow();
private slots:
  void handleRowButton();
  void handleSaveButton();

private:
  std::vector<QDockWidget *> widgets;
  QTableWidget *table;
  QToolBar *toolbar;
  QPushButton *addLineButton;
  QPushButton *saveButton;
  QMainWindow *mainWindow;
  xmlHandler *xml;
  QFile *file;
};
