#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getD(int size) {
    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    vector<int> d;
    for (int i = 0; i + 1 < a.size(); i++)
        d.push_back(a[i + 1] - a[i]);
    d.push_back(a.front() + 360000 - a.back());
    return d;
}

vector<int> prefixFunction(const vector<int> &a) {
    vector<int> p(a.size());
    for (int i = 1; i < a.size(); i++) {
        int border = p[i - 1];
        while (border > 0 && a[i] != a[border])
            border = p[border - 1];
        p[i] = border + (a[i] == a[border]);
    }
    return p;
}

bool kmp(const vector<int> &text, const vector<int> &pattern) {
    vector<int> a = pattern;
    a.push_back(0);
    a.insert(a.end(), text.begin(), text.end());

    vector<int> p = prefixFunction(a);
    return *max_element(p.begin(), p.end()) == pattern.size();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> da = getD(size);
    da.insert(da.end(), da.begin(), da.end());

    vector<int> db = getD(size);

    cout << (kmp(da, db) ? "possible" : "impossible");
}