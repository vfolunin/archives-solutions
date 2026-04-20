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

    string s;
    cin >> s >> s;

    vector<int> count(5);
    for (char c : s)
        count[c - 'a']++;

    auto [minIt, maxIt] = minmax_element(count.begin(), count.end());

    cout << *minIt << " " << *maxIt;
}