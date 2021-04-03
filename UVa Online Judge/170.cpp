#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    vector<deque<string>> pile(13);
    for (int i = 51; i >= 0; i--) {
        pile[i % 13].emplace_front();
        if (!(cin >> pile[i % 13].front()))
            return 0;
    }
    
    static string vals = "A23456789TJQK";
    int pos = 12, moves = 0;
    string last;
    while (!pile[pos].empty()) {
        last = pile[pos].back();
        pile[pos].pop_back();
        pos = vals.find(last[0]);
        moves++;
    }

    cout << setw(2) << setfill('0') << moves << "," << last << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}