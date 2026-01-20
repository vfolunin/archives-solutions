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

    int size;
    cin >> size;

    vector<double> dist(size), speed(size);
    for (int i = 0; i < size; i++)
        cin >> dist[i] >> speed[i];

    double res = 1e9;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (dist[i] < dist[j] && speed[i] > speed[j])
                res = min(res, (dist[j] - dist[i]) / (speed[i] - speed[j]));
    
    cout << fixed << res;
}