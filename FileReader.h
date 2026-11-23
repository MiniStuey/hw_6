#ifndef FILEREADER_H
#define FILEREADER_H

#include <vector>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;
#include "Record.h"
#include "Operator.h"


// This function takes in a string with items delimited by commas
// and returns a vector of those items.
// Example - input: "str1,str2,str3,str4"
//          output: {"str1", "str2", "str3", "str4"}
vector<string> split(string line) {
  vector<string> v;
  string s;
  istringstream is(line);
  while (getline(is, s, ','))
    v.push_back(s);
  return v;
}


class FileReader : public Operator {
    private:
    fstream file;
    string line;
    string filename;
    int currPage = 0;
    vector<string> attributeNames;
    vector<string> attributeTypes;
    public:

    FileReader() {
    }

    FileReader(string fname) {
        filename = fname;
    }

    void open() {
      file.open(filename, ios::in);
      getline(file, line);

      if (line.empty()) {
        cout << "empty file" << endl;
        file.close();
        return;
      } // covers for when there are no more pages to read from the file

      attributeNames = split(line);

      getline(file, line);

      attributeTypes = split(line);
      getline(file, line); // not useful data in this line, just to move the cursor to the next line)
    }

    vector<Record> next() {
        vector<Record> outPage;
        int cursor = 0;

        while(cursor < pageSize) {
            if (!getline(file, line)) {
                break;
            } // covers for end of file

            if (line.empty()) {
                break;
            } // idk why i am trying to cover line being empty while the file hasn't ended but imma leave it here

            cursor++;

            vector<string> attributeValues = split(line);

            Record record;

            for(int i = 0; i < attributeNames.size(); i++) {
                Attribute attr(attributeNames[i], attributeTypes[i], attributeValues[i]);
                record.addAttribute(attr);
            }

            outPage.push_back(record);
        }

        return outPage;
    }

        void close() {
        file.close();
    }
};

#endif
