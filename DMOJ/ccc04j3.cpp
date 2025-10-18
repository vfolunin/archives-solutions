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

    int aSize, bSize;
    cin >> aSize >> bSize;

    vector<string> a(aSize);
    for (string &s : a)
        cin >> s;

    vector<string> b(bSize);
    for (string &s : b)
        cin >> s;

    for (string &sa : a)
        for (string &sb : b)
            cout << sa << " as " << sb << "\n";
}