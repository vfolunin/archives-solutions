#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Turtle {
    int weight, strength;

    bool operator < (const Turtle &that) const {
        return strength < that.strength;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<Turtle> turtles;

    int weight, strength;
    while (cin >> weight >> strength)
        turtles.push_back({ weight, strength });

    sort(turtles.begin(), turtles.end());

    vector<int> minWeight(turtles.size() + 1, 1e9);
    minWeight[0] = 0;
    int maxHeight = 0;

    for (auto &[weight, strength] : turtles) {
        for (int height = maxHeight; height >= 0; height--)
            if (strength >= weight + minWeight[height] && minWeight[height + 1] > weight + minWeight[height])
                minWeight[height + 1] = weight + minWeight[height];
        while (maxHeight < turtles.size() && minWeight[maxHeight + 1] < 1e9)
            maxHeight++;
    }

    cout << maxHeight << "\n";
}