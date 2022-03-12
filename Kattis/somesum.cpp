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

    int n;
    cin >> n;

    vector<int> count(2);
    for (int l = 1, r = n; r <= 100; l++, r++)
        count[((l + r) * (r - l + 1) / 2) % 2]++;

    if (count[0] > count[1])
        cout << "Even";
    else if (count[0] == count[1])
        cout << "Either";
    else
        cout << "Odd";
}