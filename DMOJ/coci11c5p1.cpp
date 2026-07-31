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

    string a, b;
    cin >> a >> b;

    int ai = 0;
    while (b.find(a[ai]) == -1)
        ai++;
    int bi = b.find(a[ai]);

    vector<string> res(b.size(), string(a.size(), '.'));
    res[bi] = a;
    for (int i = 0; i < b.size(); i++)
        res[i][ai] = b[i];

    for (string &row : res)
        cout << row << "\n";
}