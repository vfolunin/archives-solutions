#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n, ballCount;
    cin >> n >> ballCount;

    if (!n)
        return 0;

    vector<int> ball(ballCount);
    for (int &b : ball)
        cin >> b;

    vector<int> canMake(n + 1);
    for (int i = 0; i < ballCount; i++)
        for (int j = i; j < ballCount; j++)
            if (abs(ball[i] - ball[j]) <= n)
                canMake[abs(ball[i] - ball[j])] = 1;

    cout << (count(canMake.begin(), canMake.end(), 0) ? "N\n" : "Y\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}