#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int messageSize;
    cin >> messageSize;

    if (!messageSize)
        return 0;

    vector<int> p(messageSize);
    for (int &x : p) {
        cin >> x;
        x--;
    }

    vector<vector<int>> to(60, vector<int>(messageSize));
    to[0] = p;
    for (int level = 1; level < 60; level++)
        for (int i = 0; i < messageSize; i++)
            to[level][i] = to[level - 1][to[level - 1][i]];

    cin.ignore();
    while (1) {
        long long iterationCount;
        cin >> iterationCount;

        if (!iterationCount)
            break;

        cin.ignore();
        string message;
        getline(cin, message);
        message += string(messageSize - message.size(), ' ');

        string cypher(messageSize, ' ');
        for (int messagePos = 0; messagePos < messageSize; messagePos++) {
            int cypherPos = messagePos;
            long long curIterationCount = iterationCount;
            for (int level = 59; level >= 0; level--) {
                if (curIterationCount >= (1LL << level)) {
                    curIterationCount -= (1LL << level);
                    cypherPos = to[level][cypherPos];
                }
            }
            cypher[cypherPos] = message[messagePos];
        }
        cout << cypher << "\n";
    }
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}