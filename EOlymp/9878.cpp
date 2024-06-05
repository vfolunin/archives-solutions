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

    if (size == 1) {
        cout << 1;
        return 0;
    }

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    for (int i = 1; i < a.size(); i++) {
        if (a[i - 1] + a[i] > limit) {
            cout << i;
            return 0;
        }
    }

    cout << a.size();
}