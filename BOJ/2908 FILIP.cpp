#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(void) {

	int a, b;
	cin >> a >> b;
	 
 	string astr = "", bstr = "";
	
	while (a > 0) {
		astr += to_string(a % 10);
		a /= 10;
	}
	while (b > 0) {
		bstr += to_string(b % 10);
		b /= 10;
	}
	a = atoi(astr.c_str());
	b = atoi(bstr.c_str());
	cout << max(a, b) << '\n';

	return 0;
}