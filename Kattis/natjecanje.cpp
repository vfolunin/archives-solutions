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

    int teamCount, damagedCount, reserveCount;
    cin >> teamCount >> damagedCount >> reserveCount;

    vector<int> isDamaged(teamCount);

    for (int i = 0; i < damagedCount; i++) {
        int team;
        cin >> team;
        isDamaged[team - 1] = 1;
    }

    vector<int> reserves(reserveCount);
    for (int &reserve : reserves) {
        cin >> reserve;
        reserve--;
    }

    sort(reserves.begin(), reserves.end());

    for (int reserve : reserves) {
        if (0 <= reserve - 1 && isDamaged[reserve - 1])
            isDamaged[reserve - 1] = 0;
        else if (isDamaged[reserve])
            isDamaged[reserve] = 0;
        else if (reserve + 1 < teamCount && isDamaged[reserve + 1])
            isDamaged[reserve + 1] = 0;
    }

    cout << count(isDamaged.begin(), isDamaged.end(), 1);
}