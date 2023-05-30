#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int n, string &s) {
    if (!n) {
        cout << "'" << s << "'";
        return;
    }

    cout << "[";
    s.push_back('0');
    rec(n - 1, s);
    s.pop_back();
    cout << ", ";
    s.push_back('1');
    rec(n - 1, s);
    s.pop_back();
    cout << "]";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    string s;
    rec(n, s);
}