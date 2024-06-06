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

    long long sum;
    cin >> sum;

    long long res = 0;
    for (int nominal : { 100, 20, 10, 5, 1 }) {
        res += sum / nominal;
        sum %= nominal;
    }

    cout << res;
}