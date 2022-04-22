class Solution {
public:
    vector<int> constructRectangle(int area) {
        int h = sqrt(area);
        while (area % h)
            h--;
        return { area / h, h };
    }
};