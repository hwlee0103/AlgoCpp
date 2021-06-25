#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int cnt = 0;

	for(int i = 1; i <= 9; ++i)
	{
		if(n < pow(10, i))
		{
			cnt += i * (n - pow(10, i - 1) + 1);
			break;
		}
		else
			cnt += i * (pow(10, i) - pow(10, i - 1));
	}

	cout << cnt << endl;

	return 0;
}