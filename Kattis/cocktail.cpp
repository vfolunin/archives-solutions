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

    int size, drinkTime;
    cin >> size >> drinkTime;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.rbegin(), a.rend());

    int endTime = 1e9;
    for (int i = 0; i < a.size(); i++) {
        if (endTime <= (i + 1) * drinkTime) {
            cout << "NO";
            return 0;
        }
        endTime = min(endTime, (i + 1) * drinkTime + a[i]);
    }

    cout << "YES";
}