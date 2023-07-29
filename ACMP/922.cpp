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

	long long timeA, timeB, distA, distB, dist;
	cin >> timeA >> timeB >> distA >> distB >> dist;

	long long time = 0, coord = 0;
	while (1) {
		if (coord + distA >= dist) {
			time += (double)(dist - coord) / distA * timeA;
			cout << fixed << time;
			break;
		}

		coord += distA - distB;
		time += timeA + timeB;

		if (coord <= 0) {
			printf("NO");
			break;
		}
	}
}