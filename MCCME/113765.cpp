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

    int price;
    cin >> price;

    vector<double> cost = { price * 0.03, price / 50 * 2.0, price / 100 * 5.0 };
    vector<string> name = { "MM", "BB", "RR" };

    cout << name[max_element(cost.begin(), cost.end()) - cost.begin()];
}