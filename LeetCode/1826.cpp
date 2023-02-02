class Solution {
    bool check(vector<int> &a, vector<int> &b, int pos) {
        for (int i = 0; i < pos; i++)
            if (a[i] != b[i])
                return 0;
        for (int i = pos; i + 1 < a.size(); i++)
            if (a[i] != b[i + 1])
                return 0;
        return 1;
    }
    
    bool check(vector<int> &a, vector<int> &b) {
        for (int i = 0; i < a.size(); i++)
            if (check(a, b, i))
                return 1;
        return 0;
    }

public:
    int badSensor(vector<int> &a, vector<int> &b) {
        bool aIsBad = check(a, b);
        bool bIsBad = check(b, a);

        if (aIsBad == bIsBad)
            return -1;
        else if (aIsBad)
            return 1;
        else
            return 2;
    }
};