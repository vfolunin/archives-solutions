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

    int targetAngle;
    cin >> targetAngle;

    for (int t = 0; 1; t++) {
        int hAngle = t * 5;
        int mAngle = t % 60 * 60;
        int angle = (mAngle - hAngle + 3600) % 3600;

        if (angle == targetAngle) {
            cout << setw(2) << setfill('0') << t / 60 << ":";
            cout << setw(2) << setfill('0') << t % 60;
            break;
        }
    }
}