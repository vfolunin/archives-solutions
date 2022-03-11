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

    int restaurantCount;
    cin >> restaurantCount;

    for (int i = 0; i < restaurantCount; i++) {
        int menuSize;
        string name;
        cin >> menuSize;
        cin.ignore();
        getline(cin, name);

        set<string> menu;
        for (int j = 0; j < menuSize; j++) {
            string meal;
            getline(cin, meal);
            menu.insert(meal);
        }

        if (menu.count("pea soup") && menu.count("pancakes")) {
            cout << name;
            return 0;
        }
    }

    cout << "Anywhere is fine I guess";
}