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
 
    int a, b, c;
    cin >> a >> b >> c;

    vector<vector<vector<int>>> can(a + 1, vector<vector<int>>(b + 1, vector<int>(c + 1)));
    can[0][0][0] = 1;

    vector<int> da = { 1, 0, 0, 2, 3 };
    vector<int> db = { 1, 1, 0, 0, 0 };
    vector<int> dc = { 0, 1, 1, 0, 0 };

    for (int a = 0; a < can.size(); a++) {
        for (int b = 0; b < can[0].size(); b++) {
            for (int c = 0; c < can[0][0].size(); c++) {
                for (int d = 0; d < da.size(); d++) {
                    int ta = a - da[d];
                    int tb = b - db[d];
                    int tc = c - dc[d];
                    can[a][b][c] |= 0 <= ta && 0 <= tb && 0 <= tc && can[ta][tb][tc];
                }
            }
        }
    }

    cout << (can[a][b][c] ? "YES" : "NO");
}