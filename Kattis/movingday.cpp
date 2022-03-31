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

    int boxCount;
    long long targetVolume;
    cin >> boxCount >> targetVolume;

    long long maxVolume = 0;
    for (int i = 0; i < boxCount; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        maxVolume = max(maxVolume, a * b * c);
    }

    cout << maxVolume - targetVolume;
}