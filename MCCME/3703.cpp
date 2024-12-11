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

    int roomCount, price;
    cin >> roomCount >> price;

    int bedroomArea = 0, nonBalconyArea = 0, balconyArea = 0;
    for (int i = 0; i < roomCount; i++) {
        int area;
        string type;
        cin >> area >> type;

        if (type == "bedroom")
            bedroomArea += area;
        if (type == "balcony")
            balconyArea += area;
        else
            nonBalconyArea += area;
    }

    cout << nonBalconyArea + balconyArea << "\n";
    cout << bedroomArea << "\n";
    cout << fixed << (nonBalconyArea + balconyArea * 0.5) * price;
}