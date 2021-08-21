#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void mark(vector<vector<int>> &ticket, int ball) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (ticket[i][j] == ball)
                ticket[i][j] = 0;
}

bool win0(vector<vector<int>> &ticket) {
    return !ticket[0][0] && !ticket[0][4] && !ticket[4][0] && !ticket[4][4];
}

bool win1(vector<vector<int>> &ticket) {
    for (int i = 0; i < 5; i++)
        if (ticket[2][i])
            return 0;
    return 1;
}

bool win2(vector<vector<int>> &ticket) {
    for (int i = 0; i < 5; i++)
        if (ticket[i][i] || ticket[i][4 - i])
            return 0;
    return 1;
}

bool win3(vector<vector<int>> &ticket) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (ticket[i][j])
                return 0;
    return 1;
}

void solve(int test) {
    int ballCount, ticketCount;
    cin >> ballCount >> ticketCount;

    vector<int> balls(ballCount);
    for (int &b : balls)
        cin >> b;

    vector<int> cost(4);
    for (int &c : cost)
        cin >> c;

    if (test > 1)
        cout << "\n";
    cout << "Case " << test << ":\n";

    for (int i = 0; i < ticketCount; i++) {
        vector<vector<int>> ticket(5, vector<int>(5));
        for (vector<int> &row : ticket)
            for (int &x : row)
                cin >> x;

        int score = 0, w0 = 0, w1 = 0, w2 = 0, w3 = 0;
        for (int j = 0; j < ballCount; j++) {
            mark(ticket, balls[j]);
            if (j < 35 && !w0 && win0(ticket)) {
                w0 = 1;
                score += cost[0];
            }
            if (j < 40 && !w1 && win1(ticket)) {
                w1 = 1;
                score += cost[1];
            }
            if (j < 45 && !w2 && win2(ticket)) {
                w2 = 1;
                score += cost[2];
            }
            if (!w3 && win3(ticket)) {
                w3 = 1;
                score += cost[3];
            }
        }

        cout << score << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}