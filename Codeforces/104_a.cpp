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

    int sum;
    cin >> sum;

    sum -= 10;

    if (1 <= sum && sum < 10 || sum == 11)
        cout << 4;
    else if (sum == 10)
        cout << 15;
    else
        cout << 0;
}