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

    int n;
    cin >> n;

    string s = "GCV";
    for (int i = 0; i < n; i++) {
        swap(s[1], s[2]);
        swap(s[0], s[1]);
    }

    cout << s;
}