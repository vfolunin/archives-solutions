#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool check(vector<int> &a, int delta) {
    for (int value : a)
        if (value != a.front() && value != a.front() + delta && value != a.back())
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    if ((a.back() - a.front()) % 2 == 0 && check(a, (a.back() - a.front()) / 2))
        cout << "Yes\n" << max((a.back() - a.front()) / 2, 1);
    else if (check(a, a.back() - a.front()))
        cout << "Yes\n" << max(a.back() - a.front(), 1);
    else
        cout << "No\n";
}