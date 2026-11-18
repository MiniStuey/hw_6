#ifndef PROJECT_H
#define PROJECT_H

#include <vector>
using namespace std;
#include "Record.h"
#include "Operator.h"
#include "FileReader.h"

class Project : public Operator {
  public:
    // Project constructors
    Project(string fileName, vector<string> fieldNames) {
      // Implement this

      // You would leverage the use of the FileReader class here
    }
    Project(Operator *op, vector<string> fieldNames) {
      // Implement this
    }

    void open() {
      // Implement this
    }

    vector<Record> next() {
      vector<Record> outPage;
      // Implement this

      // Return an empty vector if no more pages exist
      return outPage;
    }

    void close() {
      // Implement this
    }
};

#endif
