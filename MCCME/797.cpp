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

    vector<int> a(3);
    int sum = 0;
    for (int &value : a) {
        cin >> value;
        sum += value;
    }

    sort(a.begin(), a.end());

    if (sum % 2 == 0 && a[2] <= sum / 2 && a[2] <= a[0] * 2 + 1)
        cout << "YES";
    else
        cout << "NO";
}