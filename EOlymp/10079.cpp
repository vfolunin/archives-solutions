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

    vector<int> count(26);
    for (char c : s)
        count[tolower(c) - 'a']++;

    cout << (char)(max_element(count.begin(), count.end()) - count.begin() + 'A');
}