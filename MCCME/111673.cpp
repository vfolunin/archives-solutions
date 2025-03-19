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
    cin >> s;

    auto [minIt, maxIt] = minmax_element(s.begin(), s.end());

    cout << *minIt << " " << *maxIt;
}