#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;

    deque<pair<int, int> > belt;
    for (int i = 0; i < 2 * n; ++i) {
        int x;
        cin >> x;
        belt.push_back({ x, 0 });
    }

    int stageCnt = 0, zeroCnt = 0;
    vector<int> robots;
    vector<int>::iterator iter = robots.begin();

    while (1) {
        stageCnt++;
        //move belt
        belt.push_front(belt.back());
        belt.pop_back();
        //�κ� ��ġ�� �̵��������
        for (int i = 0; i < robots.size(); ++i) {
            robots[i] = (robots[i] + 1) % (2 * n);
            //�κ� ������
            if (robots[i] == n - 1) {
                belt[n - 1].second = 0;
                iter = robots.begin() + (i % (2 * n));
                i--;
                robots.erase(iter);
            }
        }
        //move robot
        for (int i = 0; i < robots.size(); ++i) {
            int next = (robots[i] + 1) % (2 * n);
            //�ű� �� �ִ� ���
            if (belt[next].first > 0 && belt[next].second == 0) {
                belt[robots[i]].second = 0;
                belt[next].first--;
                belt[next].second = 1;
                robots[i] = next;
                if (belt[next].first == 0) zeroCnt++;
            }

            //�κ��� �Ű�µ� ������ ��ġ��� �ٷ� �����ֱ�
            if (robots[i] == n - 1) {
                belt[n - 1].second = 0;
                iter = robots.begin() + (i % (2 * n));
                i--;
                robots.erase(iter);
            }
        }

        //upload robot
        if (/*belt.front().second == 0 &&*/ belt.front().first > 0) {
            robots.push_back(0);
            belt[0].first--;
            belt[0].second = 1;
            if (belt[0].first == 0) zeroCnt++;
        }

        if (zeroCnt >= k) break;
    }
    cout << stageCnt << endl;

    return 0;
}