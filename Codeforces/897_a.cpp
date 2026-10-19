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

    int size, opCount;
    string s;
    cin >> size >> opCount >> s;

    for (int i = 0; i < opCount; i++) {
        int l, r;
        char a, b;
        cin >> l >> r >> a >> b;

        replace(s.begin() + l - 1, s.begin() + r, a, b);
    }

    cout << s;
}