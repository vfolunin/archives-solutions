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

    vector<int> a(3);
    for (int &value : a)
        cin >> value;

    int maxValue = *max_element(a.begin(), a.end());

    if (*min_element(a.begin(), a.end()) == maxValue) {
        cout << 0;
    } else {
        for (int i = 0; i < a.size(); i++)
            if (a[i] == maxValue)
                cout << (char)('A' + i) << " ";
    }
}