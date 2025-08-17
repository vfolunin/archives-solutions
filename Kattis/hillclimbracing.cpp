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

    int size, limit;
    cin >> size >> limit;
    size++;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    for (int i = 0; i + 1 < a.size(); i++) {
        if (a[i + 1] - a[i] > limit) {
            cout << "BUG REPORT";
            return 0;
        }
    }

    cout << "POSSIBLE";
}