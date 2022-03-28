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

    int villagerCount, nightCount;
    cin >> villagerCount >> nightCount;

    vector<long long> villagerSongs(villagerCount);

    for (int i = 0; i < nightCount; i++) {
        int guestCount;
        cin >> guestCount;

        vector<int> guests(guestCount);
        for (int &guest : guests) {
            cin >> guest;
            guest--;
        }

        if (!*min_element(guests.begin(), guests.end())) {
            for (int guest : guests)
                villagerSongs[guest] |= 1LL << i;
        } else {
            long long commonSongs = 0;
            for (int guest : guests)
                commonSongs |= villagerSongs[guest];
            for (int guest : guests)
                villagerSongs[guest] |= commonSongs;
        }
    }

    for (int i = 0; i < villagerCount; i++)
        if (villagerSongs[0] == villagerSongs[i])
            cout << i + 1 << "\n";
}