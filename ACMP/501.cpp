#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Rectangle {
	int x1, y1, x2, y2;

	int area() {
		return (x2 - x1) * (y2 - y1);
	}

	bool intersectsWith(Rectangle &that) {
		return x1 <= that.x2 && that.x1 <= x2 && y1 <= that.y2 && that.y1 <= y2;
	}

	Rectangle intersection(Rectangle &that) {
		return { max(x1, that.x1), max(y1, that.y1), min(x2, that.x2), min(y2, that.y2) };
	}

	friend istream &operator >> (istream &in, Rectangle &r) {
		in >> r.x1 >> r.y1 >> r.x2 >> r.y2;
		if (r.x1 > r.x2)
			swap(r.x1, r.x2);
		if (r.y1 > r.y2)
			swap(r.y1, r.y2);
		return in;
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int rectangleCount;
	cin >> rectangleCount;

	vector<Rectangle> rectangles(rectangleCount);
	for (Rectangle &rectangle : rectangles)
		cin >> rectangle;

	Rectangle target;
	cin >> target;

	int res = 0;
	for (Rectangle &rectangle : rectangles)
		if (rectangle.intersectsWith(target))
			res += rectangle.intersection(target).area();

	cout << res;
}