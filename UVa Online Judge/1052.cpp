#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Solver {
    int messageLen, messageOnes;
    string compressed;

    int rec(int i, int len, int ones) {
        if (i == compressed.size())
            return len == messageLen && ones == messageOnes;

        if (compressed[i] == '0')
            return rec(i + 1, len + 1, ones);

        int curOnes = 1, nextI = i + 1, res = 0;
        while (1) {
            if (len + curOnes > messageLen || ones + curOnes > messageOnes)
                break;

            if ((nextI == compressed.size() || compressed[nextI] == '0') && curOnes != 2) {
                res += rec(nextI, len + curOnes, ones + curOnes);
                if (res >= 2)
                    return 2;
            }
            
            if (nextI == compressed.size())
                break;
            curOnes = curOnes * 2 + compressed[nextI] - '0';
            nextI++;
        }

        if (i + 1 < compressed.size() && compressed[i + 1] == '1' &&
            (i + 2 == compressed.size() || compressed[i + 2] == '0') &&
            len + 2 <= messageLen && ones + 2 <= messageOnes) {
            res += rec(i + 2, len + 2, ones + 2);
            if (res >= 2)
                return 2;
        }

        return res;
    }
};

bool solve(int test) {
    Solver solver;
    if (!(cin >> solver.messageLen >> solver.messageOnes >> solver.compressed))
        return 0;

    int res = solver.rec(0, 0, 0);

    cout << "Case #" << test << ": ";
    if (res == 0)
        cout << "NO\n";
    else if (res == 1)
        cout << "YES\n";
    else
        cout << "NOT UNIQUE\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}