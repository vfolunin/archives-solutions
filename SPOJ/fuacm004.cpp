#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, diff;
    cin >> size >> diff;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int res = 0;
    for (int i = 0; i < a.size(); i++)
        for (int j = i + 1; j < a.size(); j++)
            res += abs(a[i] - a[j]) == diff;

    cout << res;
}