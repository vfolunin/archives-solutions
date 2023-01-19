#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unordered_set<int> perfect = { 6, 28, 496, 8128, 33550336 };

    int value;
    cin >> value;

    cout << (perfect.count(value) ? "YES" : "NO");
}