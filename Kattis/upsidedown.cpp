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

    vector<string> a(size);
    for (string &s : a) {
        cin >> s;
        reverse(s.begin(), s.end());
    }

    sort(a.rbegin(), a.rend());

    for (string &s : a)
        cout << s << " ";
}