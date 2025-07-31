#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

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

    int aSize, bSize;
    cin >> aSize >> bSize;

    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;

    vector<int> b(bSize);
    for (int &value : b)
        cin >> value;

    a.insert(a.end(), a.begin(), a.end());
    if (kmp(a, b)) {
        cout << 1;
        return 0;
    }

    reverse(b.begin(), b.end());
    cout << kmp(a, b);
}