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

    long long sum = 0;
    for (int value; cin >> value; )
        sum += value;

    cout << (sum + 2) / 3;
}