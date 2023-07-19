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

    string s;
    int n;
    cin >> s >> n;

    cout << (s == "Home" || n % 2 ? "Yes" : "No");
}