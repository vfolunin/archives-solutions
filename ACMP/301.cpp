#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string minNumber(int size, int sum) {
    string res(size, '0');
    res[0] = '1';
    sum--;

    for (int i = res.size() - 1; i >= 0 && sum; i--) {
        int delta = min(sum, '9' - res[i]);
        sum -= delta;
        res[i] += delta;
    }

    return res;
}

string maxNumber(int size, int sum) {
    string res(size, '0');

    for (int i = 0; i < res.size() && sum; i++) {
        int delta = min(sum, 9);
        sum -= delta;
        res[i] += delta;
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int sum, size;
    cin >> sum >> size;

    cout << maxNumber(size, sum) << " " << minNumber(size, sum);
}