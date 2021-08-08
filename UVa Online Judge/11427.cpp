#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double getDayLoseP(double winP, int gameLimit) {
    vector<vector<double>> p(gameLimit + 1, vector<double>(gameLimit + 1));
    p[0][0] = 1;
    for (int games = 1; games <= gameLimit; games++) {
        p[games][0] = p[games - 1][0] * (1 - winP);
        for (int wins = 1; wins <= winP * games; wins++)
            p[games][wins] = p[games - 1][wins - 1] * winP + p[games - 1][wins] * (1 - winP);
    }

    double res = 0;
    for (int wins = 0; wins <= winP * gameLimit; wins++)
        res += p[gameLimit][wins];
    return res;
}

void solve(int test) {
    double num, den;
    int gameLimit;
    cin >> num;
    cin.ignore();
    cin >> den >> gameLimit;

    double p = getDayLoseP(num / den, gameLimit);
    int res = 1 / p;

    cout << "Case #" << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}