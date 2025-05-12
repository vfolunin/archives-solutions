#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

#include "json.hpp"
using namespace nlohmann;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int feedCount, limit;
    cin >> feedCount >> limit;
    cin.get();

    json res;
    json &offers = res["offers"];

    for (int i = 0; i < feedCount; i++) {
        string s;
        getline(cin, s);

        json parsed = json::parse(s);
        for (json &offer : parsed["offers"])
            if (offers.size() < limit)
                offers.push_back(offer);
    }

    cout << res;
}