class Solution {
public:
    // store parents of every province
    vector<int> parent;

    // children count of each node
    vector<int> size;

    int unionCount = 0;

    // returns a province main city
    int find(int city) {
        if (city == parent[city])
            return city;
        
        return parent[city] = find(parent[city]);
    }

    // merge two provinces
    int unify(int city1, int city2) {
        int parent1 = find(city1);
        int parent2 = find(city2);

        if (parent1 == parent2) return 0;

        if (size[parent1] >= parent2) {
            parent[parent2] = parent1;
            size[parent1] += size[parent2];
        } else {
            parent[parent1] = parent2;
            size[parent2] += size[parent1];
        }

        return 1;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        const int n = isConnected.size();
        parent.reserve(n);
        size.resize(n, 0);

        //initially, each city is a parent
        for (int i = 0; i < n; i++) {
            parent.emplace_back(i);
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    unionCount += unify(i, j);
                }
            }
        };

        return n - unionCount;
        
    }
};
