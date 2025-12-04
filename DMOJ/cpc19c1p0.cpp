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

    string s(4, ' ');
    for (char &c : s)
        cin >> c;

    vector<int> order = { 0, 1, 2, 3 };
    do {
        if (s[order[0]] == 'L' && s[order[1]] == 'R' &&
            s[order[2]] == 'L' && s[order[3]] == 'R')
            break;
    } while (next_permutation(order.begin(), order.end()));

    cout << order[0] + 1 << " " << order[1] + 1 << "\n";
    cout << order[2] + 1 << " " << order[3] + 1;
}