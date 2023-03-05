#include <QFile>
#pragma once
#include <QXmlStreamWriter>

class xmlHandler : public QXmlStreamWriter {

public:
  xmlHandler(QFile *file);
  ~xmlHandler();
  void writeToFile(std::vector<std::vector<QString>> *data);
  void readFromFile();

private:
  QFile *inputFile;
  QXmlStreamWriter *xmlWriter;
};
