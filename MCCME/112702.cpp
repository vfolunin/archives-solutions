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
    cin >> s >> s;

    for (char a = 'a'; a <= 'z'; a++) {
        if (s.find(a) == -1) {
            cout << a;
            return 0;
        }
    }

    for (char a = 'a'; a <= 'z'; a++) {
        for (char b = 'a'; b <= 'z'; b++) {
            if (s.find(string(1, a) + b) == -1) {
                cout << a << b;
                return 0;
            }
        }
    }
}