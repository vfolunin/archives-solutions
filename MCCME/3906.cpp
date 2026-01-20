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

    vector<int> a(4);
    int sum = 0;

    for (int &value : a) {
        cin >> value;
        sum += value;
    }

    if (sum < 2) {
        cout << 1;
    } else if (sum < 5) {
        cout << 0;
    } else {
        sort(a.rbegin(), a.rend());
        for (int i = 0; i < a.size(); i++) {
            sum -= a[i];
            if (sum <= 4) {
                cout << i + 1;
                break;
            }
        }
    }
}