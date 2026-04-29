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

    int size, limit;
    string s;
    cin >> size >> limit >> s;

    vector<int> count(26);
    for (char c : s)
        count[c - 'a']++;

    cout << (*max_element(count.begin(), count.end()) <= limit ? "YES" : "NO");
}