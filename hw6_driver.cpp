#include <iostream>
using namespace std;

#include "Project.h"
#include "FileReader.h"

int main() {

  Project op1("student.data", {"FirstName", "LastName"});
  op1.open();

  int recordCount=0;
  int pageCount=0;

  int recordCount2=0;
  int pageCount2=0;

  /*
  Record r;
  Attribute a = Attribute("name", "string", "n");
  r.addAttribute(a);
  cout << r << endl;
  */

  FileReader op2 = FileReader("student.data", 4);
  op2.open();

  vector<Record> page;
  do {
    pageCount++;
    page = op1.next();
    cout << "-----------------Page-----------------" << endl;
    for(auto record : page) {
      recordCount++;
      cout << record << endl;
    }
  } while (page.size() > 0);

  cout << "[Finished]" << endl;
  cout << "    pages  received: " << pageCount << endl;
  cout << "   records received: " << recordCount << endl;


  //FileReader testing
  vector<Record> page2;
  do {
    pageCount2++;
    page2 = op2.next();
    cout << "-----------------Page-----------------" << endl;
    for(auto record : page2) {
      recordCount2++;
      cout << record << endl;
    }
  } while (page2.size() > 0);

  cout << "[Finished]" << endl;
  cout << "    pages  received: " << pageCount2 << endl;
  cout << "   records received: " << recordCount2 << endl;

  return 0;
}
