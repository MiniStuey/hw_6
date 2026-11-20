#ifndef PROJECT_H
#define PROJECT_H

#include <vector>
using namespace std;
#include "Record.h"
#include "Operator.h"
#include "FileReader.h"

class Project : public Operator {
  	private:
		Operator *input;
		FileReader fr;
		vector<string> fields;


	public:
    		// Project constructors
    		Project(string fileName, vector<string> fieldNames) {
      			// Implement this
			fr = FileReader(fileName, 4);
			input = &fr;
      			// You would leverage the use of the FileReader class here
    		}
    		
		Project(Operator *op, vector<string> fieldNames) {
      			// Implement this
			input = op;
    		}	

    		void open() {
      			// Implement this
			if (input != null) {
				input->open();
			}

    		vector<Record> next() {
      			vector<Record> outPage;
      			// Implement this
			vector<Record> page = oper.next();
			int cursor = 0;
			while (!page.empty()) {
				Record r = page[cursor];
				Record newR = new Record();
				for (string s : fields) {
					Attribute a = r.getAttribute(s);
					if (a != null) {
						newR.addAttribute(a)
					}
				}
				outPage.push_back(newR);
				cursor++;
			}

      			// Return an empty vector if no more pages exist
      			return outPage;
    		}

    		void close() {
      			if (oper != null) {
				oper.close();
			}
    		}
};

#endif
