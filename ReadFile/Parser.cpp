#include "Parser.h"


void Parser::ParseSBG(string filename, map<int, Store>* stores)
{
	
	ifstream file;
	file.open(filename);

	if (file){
		string line;
		while (getline(file, line))
		{
			vector<string> items;
			splitString(line, ',', &items);

			if (items.size() >= 19 && items[0].substr(0, 5) == "Store"){
				int storeNum = stoi(items[0].substr(6));
				Store* s = &(*stores)[storeNum];
				if (s->storeNumber() != storeNum){
					s->setStoreNumber(storeNum);
				}
				s->setFiscalMonth(items[1]);
				s->setTotalPoints (stoi(items[2]));
				s->
			}

		}
	}
	else {
		throw exception("File not found!");
	}
}

void Parser::splitString(string str, char delim, vector<string>* tokens)
{
	int start = 0, end = 0;
	while ((end = str.find(delim, start)) != string::npos) {
		tokens->push_back(str.substr(start, end - start));
		start = end + 1;
	}
	tokens->push_back(str.substr(start));
	return;
}
 