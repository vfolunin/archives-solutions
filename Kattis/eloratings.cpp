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

    int rating;
    cin >> rating;

    vector<int> to = { 1000, 2400, 2500, 2700 };
    vector<string> rank = { "Invalid", "Amateur", "International grandmaster", "Grandmaster", "Super grandmaster" };

    cout << rank[upper_bound(to.begin(), to.end(), rating) - to.begin()];
}