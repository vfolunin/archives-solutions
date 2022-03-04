#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int houseCount, secureHouseCount;
    cin >> houseCount >> secureHouseCount;

    long long secureWalkCount = 1LL * houseCount * (houseCount - 1) / 2 + secureHouseCount;
    int prevSecureHouse = 0;

    for (int i = 0; i < secureHouseCount; i++) {
        int curSecureHouse;
        cin >> curSecureHouse;

        long long insecureHouseCount = curSecureHouse - prevSecureHouse - 1;
        secureWalkCount -= insecureHouseCount * (insecureHouseCount - 1) / 2;

        prevSecureHouse = curSecureHouse;
    }

    long long insecureHouseCount = houseCount - prevSecureHouse;
    secureWalkCount -= insecureHouseCount * (insecureHouseCount - 1) / 2;

    cout << secureWalkCount;
}