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

    vector<int> a(30);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    cout << *lower_bound(a.begin(), a.end(), 20);
}