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

    unordered_map<string, int> count, minPrice;
    for (int i = 0; i < 6; i++) {
        string name;
        int price;
        cin >> name >> name >> price;

        count[name]++;
        if (!minPrice.contains(name) || minPrice[name] > price)
            minPrice[name] = price;
    }

    string res = count.begin()->first;
    for (auto &[name, _] : count)
        if (count[res] < count[name] || count[res] == count[name] && minPrice[res] >  minPrice[name])
            res = name;
    
    cout << res;
}