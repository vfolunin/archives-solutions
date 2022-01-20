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

    vector<int> a(5);
    for (int &x : a)
        cin >> x;

    while (!is_sorted(a.begin(), a.end())) {
        for (int i = 0; i < 4; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                for (int x : a)
                    cout << x << " ";
                cout << "\n";
            }
        }
    }
}