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

    int volumeCount;
    cin >> volumeCount;

    vector<double> volumes(volumeCount);
    for (double &volume : volumes)
        cin >> volume;

    sort(volumes.begin(), volumes.end());
    
    double minRatio = 1;
    for (int i = 0; i < volumes.size(); i++) {
        if (volumes[i] > i + 1) {
            cout << "impossible";
            return 0;
        }
        minRatio = min(minRatio, volumes[i] / (i + 1));
    }

    cout << fixed << minRatio;
}