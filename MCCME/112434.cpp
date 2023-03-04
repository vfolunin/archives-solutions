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

    int size;
    cin >> size;

    map<int, int> count;
    for (int i = 0; i < size; i++) {
        int den, num;
        cin >> den >> num;
        if (num % den)
            count[num % den]++;
    }

    int resValue = 0, resCount = 0;
    for (auto &[value, count] : count) {
        if (resCount <= count) {
            resValue = value;
            resCount = count;
        }
    }

    cout << resValue;
}