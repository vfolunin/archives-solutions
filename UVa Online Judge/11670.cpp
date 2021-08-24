#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<double> &particles, double distance, double time) {
    double last = particles[0] + time;
    for (int i = 1; i < particles.size(); i++) {
        if (last + distance < particles[i] - time)
            return 0;
        last = min(last + distance, particles[i] + time);
    }
    return 1;
}

bool solve(int test) {
    int particleCount;
    cin >> particleCount;

    if (!particleCount)
        return 0;

    vector<double> particles(particleCount);
    for (double &p : particles)
        cin >> p;
    sort(particles.begin(), particles.end());

    double distance;
    cin >> distance;

    double l = 0, r = 1e9;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (can(particles, distance, m))
            r = m;
        else
            l = m;
    }

    cout << "Case " << test << ": ";
    cout.precision(3);
    cout << fixed << l << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}