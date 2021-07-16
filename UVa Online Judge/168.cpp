#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    vector<vector<int>> graph(26);

    while (1) {
        char v;
        cin >> v;

        if (v == '#')
            return 0;

        if (cin.peek() == ':') {
            cin.ignore();

            while (isalpha(cin.peek())) {
                char to;
                cin >> to;

                graph[v - 'A'].push_back(to - 'A');
            }
        }

        if (cin.peek() == '.')
            break;
        cin.ignore();
    }
    cin.ignore();

    char cv, cp;
    int period;
    cin >> cv >> cp >> period;
    int v = cv - 'A', p = cp - 'A';

    vector<int> blocked(26);

    for (int timer = 1; 1; timer++) {
        int nextV = -1;
        for (int to : graph[v]) {
            if (to != p && !blocked[to]) {
                nextV = to;
                break;
            }
        }

        if (nextV == -1) {
            cout << "/" << (char)(v + 'A') << "\n";
            break;
        }

        if (timer % period == 0) {
            cout << (char)(v + 'A') << " ";
            blocked[v] = 1;
        }

        p = v;
        v = nextV;
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}