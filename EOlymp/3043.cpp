#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    int gap = 0;
    for (int i = 0; i + 1 < a.size(); i++)
        gap = max(gap, a[i + 1] - a[i]);

    cout << "Class " << test << "\n";
    cout << "Max " << a.back() << ", Min " << a.front() << ", Largest gap " << gap << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}