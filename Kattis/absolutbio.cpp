#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int queryCount;
    cin >> queryCount >> queryCount;

    unordered_set<int> occupied;
    for (int i = 0; i < queryCount; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int seat;
            cin >> seat;

            if (!occupied.count(seat)) {
                cout << "Ledig\n";
                occupied.insert(seat);
            } else {
                cout << "Upptagen\n";
            }
        } else {
            int seatA, seatB;
            cin >> seatA >> seatB;

            if (!occupied.count(seatB)) {
                cout << "Ledig\n";
                occupied.erase(seatA);
                occupied.insert(seatB);
            } else {
                cout << "Upptagen\n";
            }
        }
    }
}