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
    n--;

    for (int a = 1, b = 1; 1; ) {
        string s = to_string(a);

        if (n >= s.size()) {
            n -= s.size();
        } else {
            cout << s[n];
            break;
        }

        int c = a + b;
        a = b;
        b = c;
    }
}