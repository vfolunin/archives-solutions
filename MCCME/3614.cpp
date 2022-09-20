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

    double angle;
    cin >> angle;

    int time = angle * 120;

    cout << time / 3600 << " " << time % 3600 / 60 << " " << time % 60;
}