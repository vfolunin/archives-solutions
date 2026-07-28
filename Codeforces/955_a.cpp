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

    int hours, minutes;
    cin >> hours >> minutes;

    int hunger, inc, dec;
    double price;
    cin >> hunger >> inc >> price >> dec;

    double res = 1e9;
    for (int time = hours * 60 + minutes; time < 24 * 60; time++, hunger += inc)
        res = min(res, (hunger + dec - 1) / dec * price * (time < 20 * 60 ? 1 : 0.8));

    cout << fixed << res;
}