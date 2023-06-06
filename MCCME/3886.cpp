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

    vector<int> a;
    while (1) {
        int value;
        cin >> value;

        if (!value)
            break;

        a.push_back(value);
    }

    for (int i = a.size() - 1; i >= 0; i--)
        cout << a[i] << " ";
}