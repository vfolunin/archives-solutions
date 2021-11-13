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

    vector<string> a(10);
    for (string &s : a)
        cin >> s;

    for (int i : {2, 6, 8})
        cout << a[i] << "\n";
}