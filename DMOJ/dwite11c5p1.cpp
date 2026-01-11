#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    vector<int> date(3);
    if (!(cin >> date[2] >> date[1] >> date[0]))
        return 0;

    cout << (date <= vector<int>{ 1997, 10, 27 } ? "old enough\n" : "too young\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    while (solve());
}