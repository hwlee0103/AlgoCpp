#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

typedef long long ll;
using namespace std;


int main(void) {
	ll num;
	cin >> num;

	ll x = 1;
	ll index = 1;
	while (x < num) {
		//cout << "index :: " << index << '\n';
		//cout << x << "\n";
		//cout << "--------------" << "\n";
		x += index * 6;
		index++;
	}
	cout << index << endl;

	return 0;
}