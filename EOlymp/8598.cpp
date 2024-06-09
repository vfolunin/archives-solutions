#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<long long> &health, int singleDamage, int allDamage, long long hits) {
    long long needHits = 0;
    for (int value : health) {
        if (value < hits * allDamage)
            continue;
        value -= hits * allDamage;
        needHits += (value + singleDamage - 1) / singleDamage;
    }
    return needHits <= hits;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, singleDamage, allDamage;
    cin >> size >> singleDamage >> allDamage;
    singleDamage -= allDamage;

    vector<long long> health(size);
    for (long long &value : health)
        cin >> value;

    long long l = 0, r = 1;
    while (!can(health, singleDamage, allDamage, r))
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(health, singleDamage, allDamage, m))
            r = m;
        else
            l = m;
    }

    cout << r;
}