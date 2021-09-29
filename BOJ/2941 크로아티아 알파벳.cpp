#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

bool isCroatian(string word, map<string, int> croatian) {
	if (croatian[word] > 0) return true;
	else return false;
}

int main(void) {
	string str;
	cin >> str;

	map<string, int> croatian;
	croatian.insert({ "dz=", 1 });
	croatian.insert({ "c=", 1 });
	croatian.insert({ "c-", 1 });
	croatian.insert({ "d-", 1 });
	croatian.insert({ "lj", 1 });
	croatian.insert({ "nj", 1 });
	croatian.insert({ "s=", 1 });
	croatian.insert({ "z=", 1 });

	int count = 0;
	for (int i = 0; i < str.length(); ++i) {
		string now = "";
		now = str[i];
		if(i < str.length() -1 ) now += str[i + 1];
		
		if (now == "dz") {
			now += str[i + 2];
		}

		if (isCroatian(now, croatian)) {
			count++;
			if (now.length() == 2) ++i;
			else i += 2;
		}
		else {
			count++;
		}
	}

	cout << count << '\n';

	return 0;
}