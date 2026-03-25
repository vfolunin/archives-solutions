#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ask(int i) {
    static vector<int> memo(2e5 + 1, -1e9);
    int &res = memo[i];
    if (res != -1e9)
        return res;

    cout << "? " << i << endl;

    cin >> res;

    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    int valueA = ask(1), valueB = ask(size);
    int l = 2, r = size - 1;

    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        int valueM = ask(m);

        if (abs(valueA - valueM) < abs(valueM - valueB))
            l = m;
        else
            r = m;
    }

    int valueL = ask(l), valueR = ask(r);
    int maxL = max(abs(valueA - valueL), abs(valueL - valueB));
    int maxR = max(abs(valueA - valueR), abs(valueR - valueB));

    cout << "! 1 " << (maxL < maxR ? l : r) << " " << size << endl;
}