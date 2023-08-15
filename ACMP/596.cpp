#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

struct Circle {
    string type;
    int x, y, radius;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int circleCount;
    cin >> circleCount;

    vector<Circle> circles(circleCount);
    vector<string> types;
    for (auto &[type, x, y, radius] : circles) {
        cin >> type >> x >> y >> radius;
        if (find(types.begin(), types.end(), type) == types.end())
            types.push_back(type);
    }
    
    int userX, userY;
    cin >> userX >> userY;

    unordered_map<string, int> count;
    for (auto &[type, x, y, radius] : circles)
        if ((x - userX) * (x - userX) + (y - userY) * (y - userY) <= radius * radius)
            count[type]++;

    cout << types.size() << "\n";
    for (string &type : types)
        cout << type << " " << count[type] << "\n";
}