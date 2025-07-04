#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!getline(cin, s))
        return 0;

    vector<int> count(26);
    for (char c : s)
        if (isalpha(c))
            count[tolower(c) - 'a']++;

    int i = max_element(count.begin(), count.end()) - count.begin();

    cout << (char)(i + 'A') << " " << count[i] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}