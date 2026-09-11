#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Wave {
    int start, length, amplitude;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int queryCount, size;
    cin >> queryCount >> size;

    vector<Wave> waves;
    for (int i = 0; i < queryCount; i++) {
        char type;
        cin >> type;

        if (type == '!') {
            int start, length, amplitude;
            cin >> start >> length >> amplitude;

            waves.push_back({ start, length, amplitude });
        } else {
            int pos;
            cin >> pos;

            long long res = 0;
            for (auto &[start, length, amplitude] : waves) {
                if (start <= pos && pos < start + length) {
                    if ((pos - start) % 4 == 0)
                        res += amplitude;
                    else if ((pos - start) % 4 == 2)
                        res -= amplitude;
                }
            }

            cout << res << "\n";
        }
    }
}