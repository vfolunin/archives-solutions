#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

bool solve() {
    int participantCount, roundCount;
    cin >> participantCount >> roundCount;

    if (!participantCount)
        return 0;

    vector<int> tickets(participantCount);
    long long ticketSum = 0;
    for (int i = 0; i < participantCount; i++) {
        for (int j = 0; j < roundCount; j++)
            cin >> tickets[i];
        ticketSum += tickets[i];
    }

    for (int i = 0; i < participantCount; i++) {
        long long g = gcd(tickets[i], ticketSum);
        cout << tickets[i] / g << " / " << ticketSum / g << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}