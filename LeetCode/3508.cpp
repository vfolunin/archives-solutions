class Router {
    struct Packet {
        int source, destination, timestamp;

        bool operator < (const Packet &that) const {
            return tie(source, destination, timestamp) < 
                   tie(that.source, that.destination, that.timestamp);
        }
    };

    int maxQueueSize;
    deque<Packet> packetQueue;
    set<Packet> packetSet;
    unordered_map<int, deque<int>> times;

public:
    Router(int maxQueueSize) : maxQueueSize(maxQueueSize) {}
    
    bool addPacket(int source, int destination, int timestamp) {
        Packet packet = { source, destination, timestamp };
        if (packetSet.count(packet))
            return 0;
        
        packetQueue.push_back(packet);
        packetSet.insert(packet);
        times[packet.destination].push_back(packet.timestamp);

        if (packetQueue.size() > maxQueueSize)
            forwardPacket();
        
        return 1;
    }
    
    vector<int> forwardPacket() {
        if (packetQueue.empty())
            return {};
        
        Packet packet = packetQueue.front();
        packetQueue.pop_front();
        packetSet.erase(packet);
        times[packet.destination].pop_front();
        return { packet.source, packet.destination, packet.timestamp };
    }
    
    int getCount(int destination, int startTime, int endTime) {
        deque<int> &t = times[destination];
        auto l = lower_bound(t.begin(), t.end(), startTime);
        auto r = upper_bound(t.begin(), t.end(), endTime);
        return r - l;
    }
};