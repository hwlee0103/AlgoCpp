#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main(void) {

	map<char, int> dial;
	for (int i = 0; i < 26; ++i) {
		char alpha = i + 'A';
		if (0 <= i && i <= 2) {
			dial[alpha] = 2;
		}
		else if (3 <= i && i <= 5) {
			dial[alpha] = 3;
		}
		else if (6 <= i && i <= 8) {
			dial[alpha] = 4;
		}
		else if (9 <= i && i <= 11) {
			dial[alpha] = 5;
		}
		else if (12 <= i && i <= 14) {
			dial[alpha] = 6;
		}
		else if (15 <= i && i <= 18) {
			dial[alpha] = 7;
		}
		else if (19 <= i && i <= 21) {
			dial[alpha] = 8;
		}
		else {
			dial[alpha] = 9;
		}
	}

	string str;
	cin >> str;
	
	int size = str.length();
	int time = 0;
	for (int i = 0; i < size; ++i) {
		time += dial[str[i]] + 1;
	}
	cout << time << endl;

	return 0;
}