#ifndef PROJECT_H
#define PROJECT_H

#include <vector>
#include <string>
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
			fr = FileReader(fileName);
			input = &fr;
            fields = fieldNames;
      			// You would leverage the use of the FileReader class here
    		}
    		
			Project(Operator *op, vector<string> fieldNames) {
      			// Implement this
			input = op;
            fields = fieldNames;
    		}	

    		void open() {
      			// Implement this
			if (input != nullptr) {
				input->open();
			}
            }

    		vector<Record> next() {
      			vector<Record> outPage;
				vector<Record> inPage = input->next();
      			// Implement this

				for (Record r : inPage) {
					Record newR;

					for (string s : fields) {
						Attribute a = r.getAttribute(s);
						
                        if (a.name != "") {
                            newR.addAttribute(a);
                        }
					}
					outPage.push_back(newR);
				}

				return outPage;
			}

    		void close() {
      			if (input != nullptr) {
				input->close();
				}
    		}
};

#endif