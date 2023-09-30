#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string getNumber(int index) {
    long long count = 3;
    for (; index >= count; count *= 3)
        index -= count;

    string res;
    for (count /= 3; count; count /= 3) {
        res += index / count + '1';
        index %= count;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << getNumber(n - 1);
}