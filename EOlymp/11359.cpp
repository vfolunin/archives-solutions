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
    int sum = 0;

    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
        sum += a[i];

        if (i && a[i - 1] > a[i]) {
            cout << 0;
            return 0;
        }
    }

    cout << count(a.begin(), a.end(), sum % 2) + 1 + (sum % 2 == 0);
}