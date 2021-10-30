#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int maxNumber, ticketCount;
    cin >> maxNumber >> ticketCount;

    if (!maxNumber)
        return 0;

    vector<int> tickets(maxNumber);
    for (int i = 0; i < ticketCount; i++) {
        int number;
        cin >> number;
        tickets[number - 1]++;
    }

    int res = 0;
    for (int count : tickets)
        res += count > 1;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}