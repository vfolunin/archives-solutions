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

    int size, sum;
    cin >> size >> sum;

    if (sum < size || size * 26 < sum) {
        cout << "impossible";
        return 0;
    }

    string res(size, 'a');
    sum -= size;
    for (char &c : res) {
        int delta = min(sum, 25);
        sum -= delta;
        c += delta;
    }

    cout << res;
}