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

    int money;
    cin >> money;

    vector<int> num(3), den = { 35, 100, 10 }, bonus = { 30, 60, 9 };
    for (int &count : num)
        cin >> count;

    int res = 0;
    for (int i = 0; money; i = (i + 1) % num.size()) {
        money--;
        if (++num[i] % den[i] == 0)
            money += bonus[i];
        res++;
    }

    cout << "Martha plays " << res << " times before going broke.";
}