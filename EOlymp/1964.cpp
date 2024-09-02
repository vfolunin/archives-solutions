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

    vector<int> res = { 1, 3, 15, 87, 519, 3111, 18663, 111975, 671847, 4031079, 24186471 };

    cout << *prev(upper_bound(res.begin(), res.end(), n));
}