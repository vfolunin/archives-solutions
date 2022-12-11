#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getNext(vector<int> &a) {
    vector<pair<int, int>> parts;
    for (int value : a) {
        if (parts.empty() || parts.back().first != value)
            parts.push_back({ value, 1 });
        else
            parts.back().second++;
    }

    vector<int> res;
    for (auto &[value, count] : parts) {
        res.push_back(count);
        res.push_back(value);
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> a(1);
    int n;
    cin >> a[0] >> n;

    for (int i = 0; i < n - 1; i++)
        a = getNext(a);

    for (int value : a)
        cout << value << " ";
}