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

    int amount, limit, queryCount;
    cin >> amount >> limit >> queryCount;

    vector<int> delta(3000);
    for (int i = 0; i < queryCount; i++) {
        int time;
        cin >> time >> delta[time];
    }

    for (int time = 0; time < delta.size(); time++) {
        if (time)
            amount--;

        if (amount < 0) {
            cout << "The printer melts at " << time << " second(s).";
            break;
        }

        amount += delta[time];

        if (amount > limit) {
            cout << "The printer jams at " << time << " second(s).";
            break;
        } else if (amount < 0) {
            cout << "The printer melts at " << time << " second(s).";
            break;
        }
    }
}