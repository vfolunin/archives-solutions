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

    int h, w, mod;
    cin >> h >> w >> mod;

    vector<vector<long long>> sum(2, vector<long long>(w));
    vector<vector<long long>> ul(2, vector<long long>(w));
    vector<vector<long long>> ur(2, vector<long long>(w));

    for (int x = 0; x < w; x++) {
        cin >> sum[0][x];
        ul[0][x] = ur[0][x] = sum[0][x];
    }

    for (int y = 1; y < h; y++) {
        for (int x = 0; x < w; x++) {
            sum[1][x] = sum[0][x];
            if (y > 1)
                sum[1][x] = (sum[1][x] + sum[0][x]) % mod;
            if (x)
                sum[1][x] = (sum[1][x] + ul[0][x - 1]) % mod;
            if (x + 1 < w)
                sum[1][x] = (sum[1][x] + ur[0][x + 1]) % mod;

            ul[1][x] = ur[1][x] = sum[1][x];
            if (x)
                ul[1][x] = (ul[1][x] + ul[0][x - 1]) % mod;
            if (x + 1 < w)
                ur[1][x] = (ur[1][x] + ur[0][x + 1]) % mod;
        }

        sum = { sum[1], vector<long long>(w, 0) };
        ul = { ul[1], vector<long long>(w, 0) };
        ur = { ur[1], vector<long long>(w, 0)};
    }

    for (long long value : sum[0])
        cout << value << " ";
}