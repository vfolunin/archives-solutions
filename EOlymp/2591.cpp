#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Circle {
	int x, y, radius;

	bool intersectsWith(Circle &that) {
		int dx = x - that.x;
		int dy = y - that.y;
		int dr = radius + that.radius;
		return dx * dx + dy * dy <= dr * dr;
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int circleCount;
	cin >> circleCount;

	vector<Circle> circles(circleCount);
	for (auto &[x, y, radius] : circles)
		cin >> x >> y >> radius;

	for (int i = 0; i < circles.size(); i++) {
		int res = 0;
		for (int j = 0; j < circles.size(); j++)
			res += i != j && circles[i].intersectsWith(circles[j]);

		cout << res << "\n";
	}
}