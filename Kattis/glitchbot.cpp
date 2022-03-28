#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> process(vector<string> &commands) {
    int x = 0, y = 0, d = 0;

    static int dy[] = { 1, 0, -1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    for (string &command : commands) {
        if (command == "Left") {
            d = (d + 3) % 4;
        } else if (command == "Right") {
            d = (d + 1) % 4;
        } else {
            x += dx[d];
            y += dy[d];
        }
    }

    return { x, y };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int targetX, targetY, commandCount;
    cin >> targetX >> targetY >> commandCount;

    vector<string> commands(commandCount);
    for (string &command : commands)
        cin >> command;

    for (int i = 0; i < commands.size(); i++) {
        string prevCommand = commands[i];
        for (string command : { "Left", "Right", "Forward" }) {
            commands[i] = command;
            if (process(commands) == make_pair(targetX, targetY)) {
                cout << i + 1 << " " << command;
                return 0;
            }
        }
        commands[i] = prevCommand;
    }
}