// mymodel.cpp
#include "BudgetModel.h"

BudgetModel::BudgetModel(QObject *parent) : QAbstractTableModel(parent) {}

int BudgetModel::rowCount(const QModelIndex & /*parent*/) const { return 2; }

int BudgetModel::columnCount(const QModelIndex & /*parent*/) const { return 3; }

QVariant BudgetModel::data(const QModelIndex &index, int role) const {
  if (role == Qt::DisplayRole)
    return QString("Row%1, Column%2")
        .arg(index.row() + 1)
        .arg(index.column() + 1);

  return QVariant();
}
