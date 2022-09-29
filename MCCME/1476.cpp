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

    int angle;
    cin >> angle;

    angle %= 360;

    cout << "It is " << angle / 30 << " hours " << angle % 30 * 2 << " minutes.";
}