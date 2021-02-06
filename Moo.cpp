#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef long long ll;

using namespace std;

char getMooPos(ll num, int idx, vector<ll> & totalLength) {
    if (num == 1) return 'm';
    if (num == 2 || num == 3) return 'o';

    char ans;

    if (num <= totalLength[idx - 1]) ans = getMooPos(num, idx - 1, totalLength);
    else if (num > totalLength[idx - 1] + idx + 3) ans = getMooPos(num - (totalLength[idx - 1] + idx + 3), idx - 1, totalLength);
    else {
        if (num - totalLength[idx - 1] == 1) ans = 'm';
        else ans = 'o';
    }
    return ans;
}


int main(void) {

    int n;
    cin >> n;

    vector<ll> totalLength;
    ll maxLength = 0;
    int idx = 0;
    while (maxLength < 1000000000) {
        if (idx == 0) totalLength.push_back(3);
        else {
            totalLength.push_back(totalLength.back() * 2 + idx + 3);
        }
        maxLength = totalLength.back();
        idx++;
    }

    string ansArr = "";
    int num = n;
    for (int j = 0; j < totalLength.size(); ++j) {
        if (n < totalLength[j]) {
            num = j;
            break;
        }
    }
    printf("%c\n", getMooPos(n, num, totalLength));

    return 0;
}