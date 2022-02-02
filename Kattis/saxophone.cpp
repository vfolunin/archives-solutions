#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string tune;
    getline(cin, tune);

    static string notes = "cdefgabCDEFGAB";
    static vector<string> fingers = {
        "0111001111", "0111001110", "0111001100", "0111001000",
        "0111000000", "0110000000", "0100000000", "0010000000",
        "1111001110", "1111001100", "1111001000", "1111000000",
        "1110000000", "1100000000"
    };

    vector<int> presses(10);
    string curFingers = "0000000000";

    for (char c : tune) {
        int note = notes.find(c);
        for (int i = 0; i < 10; i++)
            presses[i] += curFingers[i] == '0' && fingers[note][i] == '1';
        curFingers = fingers[note];
    }

    for (int i = 0; i < 10; i++)
        cout << presses[i] << (i + 1 < 10 ? ' ' : '\n');
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}