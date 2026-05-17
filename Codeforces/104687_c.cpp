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

    int al, ar, bl, br, sum;
    cin >> al >> ar >> bl >> br >> sum;

    int res = 0;
    for (int a = al; a <= ar; a++) {
        int b = sum - a;
        res += bl <= b && b <= br;
    }

    cout << res;
}