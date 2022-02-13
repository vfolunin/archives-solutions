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

    int roomCount, bookedRoomCount;
    cin >> roomCount >> bookedRoomCount;

    if (roomCount == bookedRoomCount) {
        cout << "too late";
        return 0;
    }

    vector<int> booked(roomCount);
    for (int i = 0; i < bookedRoomCount; i++) {
        int room;
        cin >> room;
        booked[room - 1] = 1;
    }

    cout << find(booked.begin(), booked.end(), 0) - booked.begin() + 1;
}