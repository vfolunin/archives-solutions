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

    vector<string> a;
    string s;

    while (cin >> s >> s)
        a.push_back(s);

    sort(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++)
        cout << i + 1 << ". " << a[i] << "\n";
}