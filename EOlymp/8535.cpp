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
    getline(cin, s);

    vector<int> has(10);
    for (char c : s)
        if (isdigit(c))
            has[c - '0'] = 1;

    if (count(has.begin() + 1, has.end(), 0)) {
        for (int i = 1; i < has.size(); i++)
            if (!has[i])
                cout << i;
    } else {
        cout << 0;
    }
}