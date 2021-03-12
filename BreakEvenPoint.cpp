#include <iostream>
#include <algorithm>
#include <cmath>
typedef long long ll;

using namespace std;

int main(void) {
    ll a, b, c;
    cin >> a >> b >> c;

    if (c <= b) {
        cout << "-1" << endl;
        return 0;
    }

    ll x = a / (c - b) + 1;

    cout << x << endl;

    return 0;
}