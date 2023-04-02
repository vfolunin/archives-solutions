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
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; i++)
        cout << s << "\n";
}