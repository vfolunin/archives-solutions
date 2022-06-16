class AuthenticationManager {
    int ttl;
    unordered_map<string, int> ttlOf;
    set<pair<int, string>> deleteQueue;
    
    void updateQueue(int time) {
        while (!deleteQueue.empty() && deleteQueue.begin()->first <= time) {
            ttlOf.erase(deleteQueue.begin()->second);
            deleteQueue.erase(deleteQueue.begin());
        }
    }
    
public:
    AuthenticationManager(int ttl) : ttl(ttl) {}
    
    void generate(string id, int time) {
        ttlOf[id] = time + ttl;
        deleteQueue.insert({ ttlOf[id], id });
    }
    
    void renew(string id, int time) {
        updateQueue(time);
        if (ttlOf.count(id)) {
            deleteQueue.erase({ ttlOf[id], id });
            generate(id, time);
        }
    }
    
    int countUnexpiredTokens(int time) {
        updateQueue(time);
        return deleteQueue.size();
    }
};