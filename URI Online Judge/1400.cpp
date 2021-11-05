#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool has7(int n) {
    while (n) {
        if (n % 10 == 7)
            return 1;
        n /= 10;
    }
    return 0;
}

bool solve() {
    int peopleCount, clapPos, clapCount;
    cin >> peopleCount >> clapPos >> clapCount;

    if (!peopleCount)
        return 0;

    for (int i = 1, step = 1, pos = 1; 1; i++) {
        if ((i % 7 == 0 || has7(i)) && pos == clapPos) {
            if (!--clapCount) {
                cout << i << "\n";
                break;
            }
        }
        if (pos == peopleCount && step == 1 || pos == 1 && step == -1)
            step = -step;
        pos += step;
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}