class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int delta = tomatoSlices - cheeseSlices * 2;
        if (delta % 2 == 0 && 0 <= delta && delta / 2 <= cheeseSlices)
            return { delta / 2, cheeseSlices - delta / 2 };
        return {};
    }
};