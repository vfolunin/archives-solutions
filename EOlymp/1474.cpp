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

    int h1, m1, s1, h2, m2, s2;
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;

    int time = h1 * 3600 + m1 * 60 + s1;
    while (h1 != h2 || m1 != m2 || s1 != s2) {
        if (++h1 == 24) {
            if (++m1 == 60) {
                s1 = (s1 + 1) % 60;
                m1 = 0;
            }
            h1 = 0;
        }

        time = (time + 1) % (24 * 3600);
    }

    cout << time / 3600 << " " << time % 3600 / 60 << " " << time % 60;
}