class WordDistance {
    unordered_map<string, vector<int>> indexes;
    int size;

    int dist(int a, int b) {
        return abs(a - b);
    }

public:
    WordDistance(vector<string> &words) {
        for (int i = 0; i < words.size(); i++)
            indexes[words[i]].push_back(i);
        size = words.size();
    }
    
    int shortest(const string &wordA, const string &wordB) {
        vector<int> &a = indexes[wordA];
        vector<int> &b = indexes[wordB];

        int res = min(dist(a.front(), b.back()), dist(a.back(), b.front()));
        for (int ai = 0, bi = 0; ai < a.size() && bi < b.size(); ) {
            res = min(res, dist(a[ai], b[bi]));
            if (a[ai] < b[bi])
                ai++;
            else
                bi++;
        }
        return res;
    }
};