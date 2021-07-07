#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void) {
    int x;
    cin >> x;

    int indexN = 1;
    for (int i = 1; i <= x; ++i) {
        if ((i * (i + 1)) / 2 >= x) {
            indexN = i;
            break;
        }
    }

    //    cout<<"--------------------"<<endl;
    //    cout<<x<<endl;
    //    cout<<indexN<<endl;
    //    cout<<"--------------------"<<endl;
    int cntNum = x - (indexN * (indexN - 1)) / 2;
    int numerator = 0;
    int denominator = 0;
    if (indexN % 2 == 0) {
        numerator = 1 + (cntNum - 1);
        denominator = indexN - (cntNum - 1);
    }
    else {
        numerator = indexN - (cntNum - 1);
        denominator = 1 + (cntNum - 1);
    }
    cout << numerator << "/" << denominator << endl;

    return 0;
}