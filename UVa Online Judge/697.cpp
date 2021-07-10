#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    double upTime, diameter, height, bucketVolume, bucketSpeed, downTime, targetVolume;
    if (!(cin >> upTime >> diameter >> height >> bucketVolume >> bucketSpeed >> downTime >> targetVolume))
        return 0;

    if (test > 1)
        cout << "\n";
    cout.precision(2);
    cout << fixed;
    cout << "Scenario " << test << ":\n";
    cout << "     up hill         " << setw(10) << upTime << " sec\n";
    cout << "     well diameter   " << setw(10) << diameter << " in\n";
    cout << "     water level     " << setw(10) << height << " in\n";
    cout << "     bucket volume   " << setw(10) << bucketVolume << " cu ft\n";
    cout << "     bucket ascent rate " << setw(7) << bucketSpeed << " in/sec\n";
    cout << "     down hill       " << setw(10) << downTime << " sec\n";
    cout << "     required volume " << setw(10) << targetVolume << " cu ft\n";

    diameter /= 12;
    double radius = diameter / 2;
    double deltaHeight = bucketVolume / (acos(-1) * radius * radius);
    height /= 12;
    bucketSpeed /= 12;
    double acceleration = 32.2;

    double time = 0;
    while (targetVolume > 1e-9) {
        time += upTime;
        time += sqrt(2 * height / acceleration);
        time += height / bucketSpeed;
        height += deltaHeight;
        time += downTime;
        targetVolume -= bucketVolume;
    }

    cout << "     TIME REQUIRED   " << setw(10) << time << " sec\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}