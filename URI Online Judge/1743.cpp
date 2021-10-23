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

    vector<int> a(5);
    for (int &x : a)
        cin >> x;

    vector<int> b(5);
    for (int &x : b) {
        cin >> x;
        x = !x;
    }

    cout << (a == b ? "Y\n" : "N\n");
}