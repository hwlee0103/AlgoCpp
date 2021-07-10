#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

void splitWord(string str, char delimeter, vector<string> & words) {
	int size = str.length();
	string word = "";

	for (int i = 0; i < size; ++i) {
		if (str[i] == delimeter && word != "") {
			words.push_back(word);
			word = "";
			continue;
		}
		if (str[i] != ' ') {
			word += str[i];
		}
	}
	if (word != "") words.push_back(word);
}


int main(void) {
	string str;
	getline(cin, str);

	string stringBuff;
	vector<string> words;
	words.clear();

	splitWord(str, ' ', words);

	cout << words.size() << endl;

	return 0;
}