#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

void rev(vector<int> &v, int pos) {
    cout << v.size() - pos << " ";
    reverse(v.begin(), v.begin() + pos + 1);
}

bool solve() {
    vector<int> v(1);
    char c;
    if (!(cin >> noskipws >> v[0] >> c))
        return 0;

    while (c != '\n') {
        int x;
        cin >> x >> c;
        v.push_back(x);
    }

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << (i + 1 < v.size() ? ' ' : '\n');

    for (int targetPos = v.size() - 1; targetPos >= 0; targetPos--) {
        int pos = max_element(v.begin(), v.begin() + targetPos + 1) - v.begin();
        if (pos == targetPos)
            continue;
        if (pos != 0)
            rev(v, pos);
        rev(v, targetPos);
    }
    cout << "0\n";

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}