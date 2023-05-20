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

    for (int i = 2; i < size; i++) {
        if (a[i] - a[i - 1] != a[1] - a[0]) {
            cout << "NO";
            return 0;
        }
    }

    cout << a[1] - a[0];
}