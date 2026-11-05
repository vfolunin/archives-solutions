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

    int a, b, dist;
    cin >> a >> b >> dist;

    int distA = (dist - 1) / a * a;
    int distB = (distA + b - 1) / b * b;

    cout << (distB < dist ? "WIN" : "LOSS");
}