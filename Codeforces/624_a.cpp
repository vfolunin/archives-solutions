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

    double width, distance, speed1, speed2;
    cin >> width >> distance >> speed1 >> speed2;

    cout << fixed << (distance - width) / (speed1 + speed2);
}