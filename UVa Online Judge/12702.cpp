#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int imgH, imgW;
    cin >> imgH >> imgW;

    vector<vector<int>> img(imgH, vector<int>(imgW));
    for (int i = 0; i < imgH; i++)
        for (int j = 0; j < imgW; j++)
            cin >> img[i][j];

    int kerH, kerW;
    cin >> kerH >> kerW;
    int ci = kerH / 2, cj = kerW / 2;

    vector<vector<int>> ker(kerH, vector<int>(kerW));
    for (int i = 0; i < kerH; i++)
        for (int j = 0; j < kerW; j++)
            cin >> ker[i][j];

    vector<vector<int>> res(imgH, vector<int>(imgW));
    for (int i = 0; i < imgH; i++) {
        for (int j = 0; j < imgW; j++) {
            if (!img[i][j])
                continue;
            for (int ki = 0; ki < kerH; ki++) {
                for (int kj = 0; kj < kerW; kj++) {
                    int ti = i + ki - ci, tj = j + kj - cj;
                    if (0 <= ti && ti < imgH && 0 <= tj && tj < imgW)
                        res[ti][tj] |= img[ti][tj] | ker[ki][kj];
                }
            }
        }
    }

    cout << "Case " << test << ":\n";
    for (int i = 0; i < imgH; i++) 
        for (int j = 0; j < imgW; j++)
            cout << res[i][j] << (j + 1 < imgW ? " " : "\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}