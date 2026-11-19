#ifndef RECORD_H
#define RECORD_H

#include <iostream>
using namespace std;

class Attribute {
    public:
        string name;
        string type;
        string value;
    
    Attribute(string n, string t, string v) {
        name = n;
        type = t;
        value = v;
    }
};

class Record {
    private:
        vector<Attribute> attributes;

    public:
        void addAttribute(Attribute attr) {
            attributes.push_back(attr);
        }
public:
    friend ostream& operator<< (ostream& os, const Record& r) {
      // Implement this to write a string to os displaying all attribute values
      for (Attribute attr : r.attributes) {
          os << attr.name << ", ";
          os << attr.type << ", ";
          os << attr.value << ", ";
          os << endl;
      }
      // Finally, return os
      return os;
    }

    Attribute getAttribute(string n) {
	    for (Attribute a : attributes) {
		if (a.name == n) {
			return a;
		}
	    }
	    return null;
    }


};

#endif
