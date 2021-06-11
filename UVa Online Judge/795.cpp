#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rotate(vector<string> &grill) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            swap(grill[i][j], grill[5 - j][i]);
            swap(grill[5 - j][i], grill[5 - i][5 - j]);
            swap(grill[5 - i][5 - j], grill[j][5 - i]);
        }
    }
}

bool solve() {
    string cypher;
    if (!getline(cin, cypher))
        return 0;

    vector<string> grill = {
        "010101",
        "000010",
        "001000",
        "010010",
        "000001",
        "000100"
    };

    string message;
    for (int part = 0; part * 36 < cypher.size(); part++) {
        for (int turn = 0; turn < 4; turn++) {
            for (int i = 0; i < 6; i++)
                for (int j = 0; j < 6; j++)
                    if (grill[i][j] == '1')
                        message += cypher[part * 36 + i * 6 + j];
            rotate(grill);
        }
    }

    reverse(message.begin(), message.end());
    while (message.back() == '#')
        message.pop_back();

    cout << message << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}