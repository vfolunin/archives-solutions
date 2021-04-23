#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int cost(int n) {
    string digitCost = "6255456376";
    int res = 0;
    while (n > 9) {
        res += digitCost[n % 10] - '0';
        n /= 10;
    }
    res += digitCost[n] - '0';
    return res;
}

bool solve(int test) {
    int prevTime;
    int consumption = 0, scoreA = 0, scoreB = 0;

    while (1) {
        string command;
        if (!(cin >> command))
            return 0;

        int h, m, s;
        char c;
        cin >> h >> c >> m >> c >> s;
        int time = h * 60 * 60 + m * 60 + s;

        if (command != "START")
            consumption += (time - prevTime) * (cost(scoreA) + cost(scoreB));

        if (command == "SCORE") {
            string team;
            int points;
            cin >> team >> points;

            if (team == "home")
                scoreA += points;
            else
                scoreB += points;
        }

        if (command == "END")
            break;

        prevTime = time;
    }

    cout << "Case " << test << ": " << consumption << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}