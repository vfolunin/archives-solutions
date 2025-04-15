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
    int t2 = t * 12 % 720;
    
    cout << ((t - t2) % 720 + 720) % 720 / 11;
}