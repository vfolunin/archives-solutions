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
    
    double speed, distance, time;
    cin >> speed >> distance >> time;

    speed *= 5280.0 / 3600;

    cout << (speed * time >= distance ? "MADE IT" : "FAILED TEST");
}