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

    int size;
    cin >> size;

    vector<int> has(26);
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        has[s[0] - 'A'] = 1;
    }

    cout << find(has.begin(), has.end(), 0) - has.begin();
}