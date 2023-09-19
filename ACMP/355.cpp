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

    sort(s.begin(), s.end());

    do {
        cout << s << "\n";
    } while (next_permutation(s.begin(), s.end()));
}