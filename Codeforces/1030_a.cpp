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

    for (int i = 0; i < size; i++) {
        int hard;
        cin >> hard;

        if (hard) {
            cout << "HARD";
            return 0;
        }
    }

    cout << "EASY";
}