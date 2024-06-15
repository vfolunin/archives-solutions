#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool check(int money, int guess) {
    money *= 100;

    int res = 0;
    while (money >= 120) {
        int delta = money / 120;
        res += delta;
        money = delta * 20 + money % 120;
    }

    return res == guess;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    int res = 0;
    for (int i = 0; i < size; i++) {
        int money, guess;
        cin >> money >> guess;

        res += !check(money, guess);
    }

    cout << res;
}