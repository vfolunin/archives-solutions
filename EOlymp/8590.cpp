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

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    long long res = 0;

    vector<int> l(size, -1), stack;
    for (int x = size - 1; x >= 0; x--) {
        while (!stack.empty() && a[stack.back()] > a[x]) {
            l[stack.back()] = x;
            stack.pop_back();
        }
        stack.push_back(x);
    }

    vector<int> r(size, size);
    stack.clear();
    for (int x = 0; x < size; x++) {
        while (!stack.empty() && a[stack.back()] > a[x]) {
            r[stack.back()] = x;
            stack.pop_back();
        }
        stack.push_back(x);
    }

    for (int x = 0; x < size; x++)
        res = max(res, 1LL * a[x] * (r[x] - l[x] - 1));

    cout << res;
}