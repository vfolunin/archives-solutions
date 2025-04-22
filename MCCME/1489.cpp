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

    int h, m;
    cin >> h >> m;

    int t = h * 60 + m;
    int t2 = t * 22 % 720;
    
    cout << ((360 - t2) % 720 + 720) % 720 / 22;
}