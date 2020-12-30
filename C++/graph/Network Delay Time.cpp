#include "headers/UStruct.h"
#include "headers/CoreMinial.h"

/*
    Dijkstra
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<bool> visited(N + 1);
        visited[K] = true;
        vector<int> distance(N + 1, INT_MAX);
        int res = -1;
        // Adjacency Matrix
        vector<vector<int>> vec(N + 1, vector<int>(N + 1, INT_MAX));
        for (auto& time : times) {
            vec[time[0]][time[1]] = time[2];
        }
        // init the distance matrix
        for (int i = 1;i<N + 1;i++) {
            distance[i] = vec[K][i];
            vec[i][i] = 0;
        }
        for (int i = 1;i< N + 1;i++) {
            int minDis = INT_MAX;
            int index = 0;
            // get the min distance
            for (int j = 1;j< N + 1;j++) {
                if (!visited[j] && distance[j] < minDis) {
                    index = j;
                    minDis = distance[j];
                }
            }
            visited[index] = true;
            for (int j = 1;j<N+1;j++) {
                if (vec[index][j] != INT_MAX) {
                    // update the weight from start node(K) to node(j)
                    distance[j] = min(distance[j], minDis + vec[index][j]);
                }
            }
        }
        for (int i = 1;i<distance.size();i++) {
            if (i == K) { continue; }
            // if can not arrive the node, return -1
            if (distance[i] == INT_MAX) { return -1; }
            // get max delay time
            else { res = max(res, distance[i]); }
        }
        return res;
    }
};