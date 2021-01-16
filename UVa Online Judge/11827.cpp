#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    string line;
    getline(cin, line);

    stringstream ss(line);
    vector<int> a;
    int x;
    while (ss >> x)
        a.push_back(x);
    
    int maxGcd = 0;
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < i; j++)
            maxGcd = max(maxGcd, gcd(a[i], a[j]));

    cout << maxGcd << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}