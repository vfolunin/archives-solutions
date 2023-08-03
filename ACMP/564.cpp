#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double triangleArea(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    double bestArea = 0;
    int bestI, bestJ, bestK;

    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            for (int k = j + 1; k < a.size(); k++) {
                if (a[i] >= a[j] + a[k] || a[j] >= a[i] + a[k] || a[k] >= a[i] + a[j])
                    continue;

                double area = triangleArea(a[i], a[j], a[k]);
                if (bestArea < area) {
                    bestArea = area;
                    bestI = i;
                    bestJ = j;
                    bestK = k;
                }
            }
        }
    }

    if (bestArea)
        cout << fixed << bestArea << "\n" << bestI + 1 << " " << bestJ + 1 << " " << bestK + 1;
    else
        cout << -1;
}