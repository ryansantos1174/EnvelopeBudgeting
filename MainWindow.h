#include <QDockWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>
#include <QWidget>
#include <vector>
class BudgetMainWindow : public QMainWindow {
  Q_OBJECT
public:
  BudgetMainWindow(QTableWidget *centWidget,
                   std::vector<QDockWidget *> dockWidgets);
  virtual ~BudgetMainWindow(){};
  QMainWindow *createMainWindow();
  std::vector<QDockWidget *> setWidgets();

private:
  std::vector<QDockWidget *> widgets;
  QWidget *centralWidget;
};
