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

    int value;
    cin >> value;

    bool found = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == value) {
            cout << i + 1 << " ";
            found = 1;
        }
    }

    if (!found)
        cout << -1;
}