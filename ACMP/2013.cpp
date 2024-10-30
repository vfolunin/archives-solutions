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

    int index;
    cin >> index;

    string s = "¡¿–¿¡¿ÕŸ» ";
    set<string> values;
    sort(s.begin(), s.end());
    do {
        values.insert(s.substr(0, 7));
    } while (next_permutation(s.begin(), s.end()));

    cout << vector<string>(values.begin(), values.end())[index - 1];
}