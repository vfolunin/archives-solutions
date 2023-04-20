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

    int storeCount;
    cin >> storeCount;

    map<int, map<int, vector<string>>> stores;

    for (int i = 0; i < storeCount; i++) {
        string name, street;
        int type, price;
        cin >> name >> street >> type >> price;
        stores[type][price].push_back(name + " " + street);
    }

    for (auto &[type, stores] : stores) {
        if (stores.empty())
            cout << "0 ";
        else
            cout << stores.begin()->second.size() << " ";
    }
}