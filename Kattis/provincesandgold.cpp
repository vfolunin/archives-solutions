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

    int a, b, c;
    cin >> a >> b >> c;

    int points = a * 3 + b * 2 + c;

    string res;
    if (points >= 8)
        res += "Province";
    else if (points >= 5)
        res += "Duchy";
    else if (points >= 2)
        res += "Estate";
    if (!res.empty())
        res += " or ";
    if (points >= 6)
        res += "Gold";
    else if (points >= 3)
        res += "Silver";
    else
        res += "Copper";

    cout << res;
}