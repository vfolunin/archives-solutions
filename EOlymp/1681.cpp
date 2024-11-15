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

    vector<int> res = { 0, 1, 2, 14, 60, 406, 2256, 13084, 70978, 423000, 2556298 };

    cout << res[n];
}