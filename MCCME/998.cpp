#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prefixFunction(vector<int> &v) {
    vector<int> p(v.size());
    for (int i = 1; i < v.size(); i++) {
        int border = p[i - 1];
        while (border && v[border] != v[i])
            border = p[border - 1];
        p[i] = border + (v[border] == v[i]);
    }
    return p;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int period = size - prefixFunction(a).back();
    if ((size - 1) % period)
        period = size - 1;

    cout << period;
}