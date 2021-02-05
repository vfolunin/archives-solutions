#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string text;
    getline(cin, text);

    static string letters = "abcdefghijklmnopqrstuvwxyz ";
    static string presses = "123123123123123123412312341";
    
    int res = 0;
    for (char c : text)
        res += presses[letters.find(c)] - '0';

    cout << "Case #" << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int test = 1; test <= n; test++)
        solve(test);
}