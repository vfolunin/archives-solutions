#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<deque<int>> a(2, deque<int>(5));
    for (deque<int> &row : a)
        for (int &value : row)
            cin >> value;

    for (int i = 0; i < 1e6; i++) {
        if (a[0].empty()) {
            cout << "second " << i;
            return 0;
        }
        if (a[1].empty()) {
            cout << "first " << i;
            return 0;
        }

        int p = a[0].front() < a[1].front();
        if (a[0].front() == 0 && a[1].front() == 9)
            p = 0;
        if (a[0].front() == 9 && a[1].front() == 0)
            p = 1;

        a[p].push_back(a[0].front());
        a[0].pop_front();
        a[p].push_back(a[1].front());
        a[1].pop_front();
    }

    cout << "botva";
}