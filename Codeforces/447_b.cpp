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

    string s;
    int opCount;
    cin >> s >> opCount;

    vector<int> price(26);
    for (int &price : price)
        cin >> price;

    int cost = 0;
    for (int i = 0; i < s.size(); i++)
        cost += price[s[i] - 'a'] * (i + 1);

    int maxPrice = *max_element(price.begin(), price.end());
    cost += opCount * (s.size() + s.size() + opCount + 1) / 2 * maxPrice;

    cout << cost;
}