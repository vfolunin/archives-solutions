#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> decode(int mask) {
    vector<string> a(4, string(4, '.'));
    for (int bit = 0; bit < 16; bit++)
        if (mask & (1 << bit))
            a[bit / 4][bit % 4] = 'X';
    return a;
}

int encode(vector<string> &a) {
    int mask = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (a[i][j] == 'X')
                mask |= 1 << (i * 4 + j);
    return mask;
}

int rec(int mask) {
    static vector<int> memo(1 << 16);
    int &res = memo[mask];
    if (res)
        return res;

    if (mask == (1 << 16) - 1)
        return res = 1;

    vector<string> a = decode(mask);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {

            if (a[i][j] != 'X') {
                a[i][j] = 'X';

                if (rec(encode(a)) == 2)
                    return res = 1;

                a[i][j] = 'O';
            }

        }
    }

    for (int i = 0; i < 4; i++) {
        for (int len = 1; len <= 3; len++) {
            string prev;

            for (int j = 0; j < len; j++)
                prev += a[i][j];

            if (prev.find('X') == -1) {
                for (int j = 0; j < len; j++)
                    a[i][j] = 'X';

                if (rec(encode(a)) == 2)
                    return res = 1;

                for (int j = 0; j < len; j++)
                    a[i][j] = prev[j];
            }

            prev.clear();

            for (int j = 0; j < len; j++)
                prev += a[i][3 - j];

            if (prev.find('X') == -1) {
                for (int j = 0; j < len; j++)
                    a[i][3 - j] = 'X';

                if (rec(encode(a)) == 2)
                    return res = 1;

                for (int j = 0; j < len; j++)
                    a[i][3 - j] = prev[j];
            }

            prev.clear();

            for (int j = 0; j < len; j++)
                prev += a[j][i];

            if (prev.find('X') == -1) {
                for (int j = 0; j < len; j++)
                    a[j][i] = 'X';

                if (rec(encode(a)) == 2)
                    return res = 1;

                for (int j = 0; j < len; j++)
                    a[j][i] = prev[j];
            }

            prev.clear();

            for (int j = 0; j < len; j++)
                prev += a[3 - j][i];

            if (prev.find('X') == -1) {
                for (int j = 0; j < len; j++)
                    a[3 - j][i] = 'X';

                if (rec(encode(a)) == 2)
                    return res = 1;

                for (int j = 0; j < len; j++)
                    a[3 - j][i] = prev[j];
            }
        }
    }

    return res = 2;
}

void solve() {
    vector<string> a(4);
    for (string &row : a)
        cin >> row;

    cout << (rec(encode(a)) == 1 ? "WINNING\n" : "LOSING\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}