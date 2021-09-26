#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string s;
    cin >> s;

    int sum = 0;
    for (char c : set<char>(s.begin(), s.end()))
        sum += c;

    string res;
    while (sum) {
        res += sum % 2 + '0';
        sum /= 2;
    }
    reverse(res.begin(), res.end());

    cout << "#" << test << " : " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    for (int test = 1; test <= n; test++)
        solve(test);
}