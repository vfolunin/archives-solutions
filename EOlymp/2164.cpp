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
    int shift;
    cin >> s >> shift;

    for (char &c : s)
        c = ((c - 'A' - shift) % 26 + 26) % 26 + 'A';

    cout << s;
}