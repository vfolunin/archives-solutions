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

    int n;
    cin >> n;

    int time = (n - 1) * 5;

    if (time <= 12 * 60)
        cout << time / 60 << " " << time % 60;
    else
        cout << "NO";
}