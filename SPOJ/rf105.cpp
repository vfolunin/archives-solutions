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

    int aSize;
    cin >> aSize;

    vector<string> a(aSize);
    for (string &s : a)
        cin >> s;

    int bSize;
    cin >> bSize;

    vector<string> b(bSize);
    for (string &s : b)
        cin >> s;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<string> res;
    set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));

    for (string &s : res)
        cout << s << " ";
}