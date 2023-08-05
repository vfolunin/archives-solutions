#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Train {
    string name;
    double speed;

    bool operator < (const Train &that) const {
        return speed < that.speed;
    }

    friend istream &operator >> (istream &in, Train &train) {
        in.ignore(2);
        getline(in, train.name, '"');

        int h1, m1, h2, m2;
        char colon;
        in >> h1 >> colon >> m1 >> h2 >> colon >> m2;

        double time = h2 * 60 + m2 - h1 * 60 - m1;
        if (time <= 0)
            time += 24 * 60;

        train.speed = 650 * 60 / time;

        return in;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int trainCount;
    cin >> trainCount;

    vector<Train> trains(trainCount);
    for (Train &train : trains)
        cin >> train;

    auto [name, speed] = *max_element(trains.begin(), trains.end());

    cout << "The fastest train is \"" << name << "\".\n";
    cout.precision(0);
    cout << "Its speed is " << fixed << speed << " km / h, approximately.";
}