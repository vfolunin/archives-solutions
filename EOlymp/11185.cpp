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

    int start, finish, routeCount;
    cin >> start >> finish >> routeCount;

    int res = 1e9;
    for (int i = 0; i < routeCount; i++) {
        int price, size;
        cin >> price >> size;

        unordered_map<int, int> route;
        for (int i = 0; i < size; i++) {
            int v;
            cin >> v;

            route[v] = i;
        }

        if (route.count(start) && route.count(finish) && route[start] < route[finish])
            res = min(res, price);
    }

    cout << (res != 1e9 ? res : -1);
}