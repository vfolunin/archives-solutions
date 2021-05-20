#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> readInts() {
    string line;
    getline(cin, line);
    getline(cin, line);
    stringstream ss(line);
    vector<int> res;
    int x;
    while (ss >> x)
        res.push_back(x);
    return res;
}

bool solve() {
    int k;
    if (!(cin >> k))
        return 0;

    vector<int> a = readInts();
    reverse(a.begin(), a.end());

    vector<int> res(a.size());
    for (int power = a.size() - 1; power; power--) {
        res[power - 1] = a[power];
        a[power - 1] += k * a[power];
    }

    while (res.size() > 1 && !res.back())
        res.pop_back();
    reverse(res.begin(), res.end());

    cout << "q(x): ";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << (i + 1 < res.size() ? " " : "\n");
    cout << "r = " << a[0] << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}