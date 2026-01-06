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

    int a, b, c = 7;
    cin >> a >> b;
    if (b)
        cin >> c;

    cout << "It takes " << 6 * a + (7 - b) * c << " hours for Team 610 build a robot.";
}