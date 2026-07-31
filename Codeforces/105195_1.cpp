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

    int size, index;
    cin >> size >> index;
    index--;

    int pairIndex = index / (size * 2 + 1);
    int seatIndex = index % (size * 2 + 1);

    if (seatIndex < size)
        cout << pairIndex * 2 + 1 << " " << seatIndex + 1;
    else
        cout << pairIndex * 2 + 2 << " " << seatIndex - size + 1;
}