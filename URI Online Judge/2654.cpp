#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Creature {
    string name;
    int power, kills, deaths;

    bool operator < (const Creature &that) const {
        if (power != that.power)
            return power > that.power;
        if (kills != that.kills)
            return kills > that.kills;
        if (deaths != that.deaths)
            return deaths < that.deaths;
        return name < that.name;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int creatureCount;
    cin >> creatureCount;

    vector<Creature> creatures(creatureCount);
    for (auto &[name, power, kills, deaths] : creatures)
        cin >> name >> power >> kills >> deaths;

    cout << min_element(creatures.begin(), creatures.end())->name << "\n";
}