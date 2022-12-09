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
    cin >> s;

    int balance = 0, res = 0;
    for (char c : s) {
        if (c == '(')
            balance++;
        else
            balance--;

        if (balance < 0) {
            balance = 0;
            res++;
        }
    }
    res += balance;

    cout << res;
}