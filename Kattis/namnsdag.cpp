#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int distance(string &a, string &b) {
    if (a.size() != b.size())
        return 1e9;

    int res = 0;
    for (int i = 0; i < a.size(); i++)
        res += a[i] != b[i];
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a;
    int size;
    cin >> a >> size;

    for (int i = 1; 1; i++) {
        string b;
        cin >> b;

        if (distance(a, b) <= 1) {
            cout << i;
            break;
        }
    }
}