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

    string s;
    for (int i = 1; i <= n; i++)
        s += to_string(i);

    cout << s.find(to_string(n)) + 1;
}