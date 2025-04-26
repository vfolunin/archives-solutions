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

    int size, limit;
    cin >> size >> limit;

    int exceed = 0, remain = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value > limit)
            exceed += value - limit;
        else
            remain += limit - value;
    }

    cout << exceed << " " << remain;
}