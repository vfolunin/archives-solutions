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

    for (string s; cin >> s; ) {
        next_permutation(s.begin(), s.end());
        cout << s << "\n";
    }
}