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
    int d;
    cin >> s >> d;

    while (d % 2 == 0) {
        if (s.back() == '1') {
            cout << "NO";
            return 0;
        }
        s.pop_back();
        d /= 2;
    }

    cout << "YES";
}