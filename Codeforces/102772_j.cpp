#include <iostream>
#include <iomanip>
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

    int t = 0;
    for (int i = 0; i < size; i++) {
        int h, m;
        char colon;
        cin >> h >> colon >> m;

        t += h * 60 + m;
    }

    cout << setw(2) << setfill('0') << t / 3600 << ":";
    cout << setw(2) << setfill('0') << t % 3600 / 60 << ":";
    cout << setw(2) << setfill('0') << t % 60;
}