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

    int a;
    string s;
    cin >> a >> s;

    cout << a + stoi(string(s.rbegin(), s.rend()));
}