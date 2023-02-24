class FileSharing {
    set<int> unused;
    unordered_map<int, unordered_set<int>> chunksOf;
    vector<set<int>> usersOf;

public:
    FileSharing(int chunkCount) : usersOf(chunkCount + 1) {}
    
    int join(const vector<int> &chunks) {
        int user = chunksOf.size() + 1;
        if (!unused.empty()) {
            user = *unused.begin();
            unused.erase(unused.begin());
        }

        chunksOf[user] = { chunks.begin(), chunks.end() };
        for (int chunk : chunksOf[user])
            usersOf[chunk].insert(user);

        return user;
    }
    
    void leave(int user) {
        unused.insert(user);
        for (int chunk : chunksOf[user])
            usersOf[chunk].erase(user);
    }
    
    vector<int> request(int user, int chunk) {
        vector<int> res = { usersOf[chunk].begin(), usersOf[chunk].end() };
        if (!res.empty()) {
            chunksOf[user].insert(chunk);
            usersOf[chunk].insert(user);
        }        
        return res;
    }
};