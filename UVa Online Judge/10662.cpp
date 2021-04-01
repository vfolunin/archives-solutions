#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int agencyCount, restaurantCount, hotelCount;
    if (!(cin >> agencyCount >> restaurantCount >> hotelCount))
        return 0;

    vector<int> agencyCost(agencyCount);
    vector<vector<int>> agencyRestaurant(agencyCount, vector<int>(restaurantCount));
    for (int i = 0; i < agencyCount; i++) {
        cin >> agencyCost[i];
        for (int j = 0; j < restaurantCount; j++)
            cin >> agencyRestaurant[i][j];
    }

    vector<int> restaurantCost(restaurantCount);
    vector<vector<int>> restaurantHotel(restaurantCount, vector<int>(hotelCount));
    for (int i = 0; i < restaurantCount; i++) {
        cin >> restaurantCost[i];
        for (int j = 0; j < hotelCount; j++)
            cin >> restaurantHotel[i][j];
    }

    vector<int> hotelCost(hotelCount);
    vector<vector<int>> hotelAgency(hotelCount, vector<int>(agencyCount));
    for (int i = 0; i < hotelCount; i++) {
        cin >> hotelCost[i];
        for (int j = 0; j < agencyCount; j++)
            cin >> hotelAgency[i][j];
    }

    int bestCost = 1e9, bestA, bestR, bestH;
    for (int a = 0; a < agencyCount; a++) {
        for (int r = 0; r < restaurantCount; r++) {
            for (int h = 0; h < hotelCount; h++) {
                if (agencyRestaurant[a][r] || restaurantHotel[r][h] || hotelAgency[h][a])
                    continue;
                int cost = agencyCost[a] + restaurantCost[r] + hotelCost[h];
                if (cost < bestCost) {
                    bestCost = cost;
                    bestA = a;
                    bestR = r;
                    bestH = h;
                }
            }
        }
    }

    if (bestCost < 1e9)
        cout << bestA << " " << bestR << " " << bestH << ":" << bestCost << "\n";
    else
        cout << "Don't get married!\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}