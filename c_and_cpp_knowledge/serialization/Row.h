
#ifndef ROW_H 
#define ROW_H

#include <string>

struct Row{
	std::string key;
	std::string value;
	Row() {}
	Row(const char* key, const char* value)
		: key(key),
		  value(value)
		{ }	
};

#endif //struct row
