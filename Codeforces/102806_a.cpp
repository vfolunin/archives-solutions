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

    a[0] = -abs(a[0]);
    for (int i = 1; i < a.size(); i++) {
        if (a[i - 1] <= -abs(a[i])) {
            a[i] = -abs(a[i]);
        } else if (a[i - 1] <= abs(a[i])) {
            a[i] = abs(a[i]);
        } else {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    for (int value : a)
        cout << value << " ";
}