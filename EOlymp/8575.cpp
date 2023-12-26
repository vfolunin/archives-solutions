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

    int res = 0;
    for (int nominal : { 500, 200, 100, 50, 20, 10, 5, 2, 1 }) {
        res += sum / nominal;
        sum %= nominal;
    }

    cout << res;
}