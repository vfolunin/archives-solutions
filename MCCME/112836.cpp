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

    int size, targetValue;
    cin >> size >> targetValue;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> l(a.size(), -1), stack;
    for (int i = a.size() - 1; i >= 0; i--) {
        while (!stack.empty() && a[stack.back()] <= a[i]) {
            l[stack.back()] = i;
            stack.pop_back();
        }
        stack.push_back(i);
    }

    vector<int> r(a.size(), a.size());
    stack.clear();
    for (int i = 0; i < a.size(); i++) {
        while (!stack.empty() && a[stack.back()] < a[i]) {
            r[stack.back()] = i;
            stack.pop_back();
        }
        stack.push_back(i);
    }

    long long res = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] == targetValue)
            res += 1LL * (i - l[i]) * (r[i] - i);

    cout << res;
}