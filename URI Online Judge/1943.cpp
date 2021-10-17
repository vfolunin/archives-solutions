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

    vector<int> top = { 1, 3, 5, 10, 25, 50, 100 };
    cout << "Top " << *lower_bound(top.begin(), top.end(), n) << "\n";
}