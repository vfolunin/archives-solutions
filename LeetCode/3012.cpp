class Solution {
public:
    int minimumArrayLength(vector<int> &a) {
        int minValue = *min_element(a.begin(), a.end());
        int minCount = count(a.begin(), a.end(), minValue);
        if (minCount == 1)
            return 1;
        
        for (int value : a)
            if (value % minValue)
                return 1;
        
        return (minCount + 1) / 2;
    }
};