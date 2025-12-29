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
    int l = 0, r = 0;
    for (int &value : a) {
        cin >> value;
        r += value;
    }

    for (int i = 0; i < a.size(); i++) {
        l += a[i];
        r -= a[i];

        if (l == r) {
            cout << i + 1 << "\n";
            return 0;
        }
    }
    
    cout << "Andrew is sad.\n";
}