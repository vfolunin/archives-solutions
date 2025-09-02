class Matrix3D {
    vector<set<pair<int, int>>> layers;
    set<pair<int, int>> sortedLayers;

public:
    Matrix3D(int size) : layers(size) {
        for (int x = 0; x < size; x++)
            sortedLayers.insert({ 0, x });
    }
    
    void setCell(int x, int y, int z) {
        sortedLayers.erase({ layers[x].size(), x });
        layers[x].insert({ y, z });
        sortedLayers.insert({ layers[x].size(), x });
    }
    
    void unsetCell(int x, int y, int z) {
        sortedLayers.erase({ layers[x].size(), x });
        layers[x].erase({ y, z });
        sortedLayers.insert({ layers[x].size(), x });
    }
    
    int largestMatrix() {
        return sortedLayers.rbegin()->second;
    }
};