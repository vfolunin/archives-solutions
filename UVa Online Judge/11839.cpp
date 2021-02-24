#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    for (int i = 0; i < n; i++) {
        char res = ' ';

        for (int j = 0; j < 5; j++) {
            int x;
            cin >> x;

            if (x <= 127) {
                if (res == ' ')
                    res = 'A' + j;
                else
                    res = '*';
            }
        }

        if (res == ' ')
            res = '*';

        cout << res << "\n";
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}