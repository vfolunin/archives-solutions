#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_map<string, int> points = {
        { "Poblano", 1500 },
        { "Mirasol", 6000 },
        { "Serrano", 15500 },
        { "Cayenne", 40000 },
        { "Thai", 75000 },
        { "Habanero", 125000 }
    };

    int res = 0;
    for (int i = 0; i < size; i++) {
        string type;
        cin >> type;

        res += points[type];
    }

    cout << res;
}