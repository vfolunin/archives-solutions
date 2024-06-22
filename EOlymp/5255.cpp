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

    vector<int> count(10);
    for (char c : s)
        count[c - '0']++;

    cout << max_element(count.begin(), count.end()) - count.begin();
}