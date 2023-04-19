#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> a;

    while (1) {
        int value;
        cin >> value;

        if (!value)
            break;

        a.push_back(value);
    }

    bool found = 0;
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        int root = sqrt(a[i]);
        if (a[i] == root * root) {
            cout << a[i] << " ";
            found = 1;
        }
    }

    if (!found)
        cout << 0;
}