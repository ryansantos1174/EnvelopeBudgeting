#include "XML_Handler.h"

xmlHandler::xmlHandler(QFile *file) {
  // Setup xml writer and ensure the formatting is always set
  inputFile = file;
  xmlWriter = new QXmlStreamWriter(inputFile);
  xmlWriter->setAutoFormatting(true);
}

void xmlHandler::writeToFile(std::vector<std::vector<QString>> *data) {
  inputFile->open(QIODevice::WriteOnly);
  xmlWriter->writeStartDocument();
  xmlWriter->writeStartElement("Transactions");

  std::vector<std::vector<QString>>::iterator row;
  std::vector<QString>::iterator column;
  for (row = data->begin(); row != data->end(); row++) {
    for (column = row->begin(); column != row->end(); column++) {
      xmlWriter->writeStartElement(*column);
      xmlWriter->writeEndElement();
    }
  }

  xmlWriter->writeEndElement();
  xmlWriter->writeEndDocument();
  inputFile->close();
}
