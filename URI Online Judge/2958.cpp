#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(string &a, string &b) {
    if (a[1] != b[1])
        return a[1] > b[1];
    return a[0] > b[0];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<string> a(h * w);
    for (string &s : a)
        cin >> s;

    sort(a.begin(), a.end(), compare);

    for (string &s : a)
        cout << s << "\n";
}