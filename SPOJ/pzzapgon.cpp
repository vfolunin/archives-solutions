#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    int x = 0, y = 0, step;
    for (char d; cin >> step >> d; ) {
        if (d == 'N')
            y -= step;
        else if (d == 'S')
            y += step;
        else if (d == 'W')
            x -= step;
        else
            x += step;
    }
    
    cout << (int)ceil(hypot(x, y));
}