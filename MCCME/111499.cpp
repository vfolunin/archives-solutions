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

    vector<int> score(2);
    int serveCount = 0, player;

    for (string op; cin >> op; ) {
        if (op == "service") {
            player = serveCount / 5 % 2;
            serveCount++;
        } else if (op == "net" || op == "out") {
            score[player ^ 1]++;
        } else if (op == "goal") {
            score[player]++;
        } else if (op == "return") {
            player ^= 1;
        } else {
            break;
        }
    }

    cout << score[0] << " " << score[1];
}