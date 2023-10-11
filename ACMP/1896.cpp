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
    for (int i = 0; i < size; i++) {
        cin >> a[i];
        a[i] = -abs(a[i]);

        if (i && a[i - 1] > a[i]) {
            a[i] = -a[i];

            if (a[i - 1] > a[i]) {
                cout << "No";
                return 0;
            }
        }
    }

    cout << "Yes\n";
    for (int value : a)
        cout << value << " ";
}