#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Rectangle {
	int y1, x1, y2, x2;

	bool has(int y, int x) {
		if (y1 <= y && y <= y2 && (x == x1 || x == x2))
			return 1;
		if (x1 <= x && x <= x2 && (y == y1 || y == y2))
			return 1;
		return 0;
	}

	friend istream &operator >> (istream &in, Rectangle &rectangle) {
		in >> rectangle.y1 >> rectangle.x1 >> rectangle.y2 >> rectangle.x2;
		rectangle.y1--;
		rectangle.x1--;
		rectangle.y2--;
		rectangle.x2--;
		return in;
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int h, w, rectangleCount;
	cin >> h >> w >> rectangleCount;

	vector<Rectangle> rectangles(rectangleCount);
	for (Rectangle &rectangle : rectangles)
		cin >> rectangle;
		
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			int index = -1;
			for (int i = 0; i < rectangles.size(); i++)
				if (rectangles[i].has(y, x))
					index = i;

			cout << (char)(index == -1 ? '.' : 'a' + index);
		}
		cout << "\n";
	}
}