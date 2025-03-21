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
        count[c - 'a']++;

    int evenCount = 0;
    for (int count : count)
        evenCount += count && count % 2 == 0;

    cout << (evenCount % 2 ? "Grisha" : "Dima");
}