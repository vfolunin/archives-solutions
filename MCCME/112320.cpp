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

    bool updated = 1;
    for (int i = 0; updated; i++) {
        updated = 0;

        for (int j = a.size() - 1; j; j--) {
            if (a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
                updated = 1;
            }
        }

        if (!i || updated) {
            for (int value : a)
                cout << value << " ";
            cout << "\n";
        }
    }
}