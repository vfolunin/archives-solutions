class Solution {
public:
    int guessMajority(ArrayReader &reader) {
        vector<int> res = {
            reader.query(1, 2, 3, 4),
            reader.query(0, 2, 3, 4),
            reader.query(0, 1, 3, 4),
            reader.query(0, 1, 2, 4),
            reader.query(0, 1, 2, 3)
        };

        vector<int> type = { 0 };
        for (int i = 1; i < res.size(); i++)
            type.push_back(type.back() ^ (res[i - 1] != res[i]));
        for (int i = 5; i < reader.length(); i++)
            type.push_back(type[4] ^ (res[0] != reader.query(1, 2, 3, i)));
        
        vector<int> count(2);
        for (int type : type)
            count[type]++;
        
        if (count[0] == count[1])
            return -1;
        else if (count[0] > count[1])
            return find(type.begin(), type.end(), 0) - type.begin();
        else
            return find(type.begin(), type.end(), 1) - type.begin();
    }
};