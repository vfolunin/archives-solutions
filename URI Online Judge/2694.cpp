#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int extract(string &line, int &i) {
    while (!isdigit(line[i]))
        i++;
    int res = 0;
    while (i < line.size() && isdigit(line[i]))
        res = res * 10 + line[i++] - '0';
    return res;
}

void solve() {
    string line;
    cin >> line;

    int i = 0;
    int a = extract(line, i);
    int b = extract(line, i);
    int c = extract(line, i);

    cout << a + b + c << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}