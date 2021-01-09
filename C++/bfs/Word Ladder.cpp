#include "headers/CoreMinial.h"

/**
 *  bfs —— 对于每个单词的每个位置从a - z暴力替换
 **/

class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;
        unordered_map<string, int> pathCnt{{{beginWord, 1}}};
        queue<string> q{{beginWord}};
        while (!q.empty()) {
            string word = q.front(); q.pop();
            for (int i = 0; i < word.size(); ++i) {
                string newWord = word;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    newWord[i] = ch;
                    if (wordSet.count(newWord) && newWord == endWord) return pathCnt[word] + 1;
                    if (wordSet.count(newWord) && !pathCnt.count(newWord)) {
                        q.push(newWord);
                        pathCnt[newWord] = pathCnt[word] + 1;
                    }   
                }
            }
        }
        return 0;
    }
    
};

/**
 *  dfs —— 超时
 **/ 

// class Solution {
// public:
    
//     int res = INT_MAX;
    
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         int start = 0, end = -1;
//         bool find = false;
//         for (int i = 0;i<wordList.size();i++) {
//             if (endWord == wordList[i]) {
//                 find = true;
//                 end = i;
//                 break;
//             }
//         }
//         if (!find) { return 0; }
//         wordList.push_back(beginWord);
//         start = wordList.size() - 1;
//         // Construct graph
//         vector<vector<int>> graph(wordList.size(), vector<int>(wordList.size(), 0));
//         constructGraph(wordList, graph);
//         // bfs
//         bfs(graph, start, end, 0);
//         return res == INT_MAX ? 0 : res + 1;
//     }
    
//     bool canTransform(string str1, string str2) {
//         int count = 0;
//         for(int i = 0;i<str1.size();i++) {
//             if (str1[i] != str2[i]) {
//                 count++;
//             }
//         }
//         return count == 1;
//     }
    
//     void constructGraph(vector<string>& wordList, vector<vector<int>>& graph) {
//         int size = wordList.size();
//         for (int i = 0;i<size;i++) {
//             for (int j = i + 1;j<size;j++) {
//                 if (canTransform(wordList[i], wordList[j])) {
//                     graph[i][j] = 1;
//                     graph[j][i] = 1;
//                 }
//             }
//         }
//     }
    
//     void bfs(vector<vector<int>>& graph, int start, int end, int dis) {
//         if (start == end) {
//             res = min(res, dis);
//             return;
//         }
//         for (int i = 0;i<graph.size();i++) {
//             if (graph[start][i] == 1) {
//                 graph[start][i] = 0;
//                 graph[i][start] = 0;
//                 bfs(graph, i, end, dis + 1);
//                 graph[start][i] = 1;
//                 graph[i][start] = 1;
//             }
//         }
//     }
// };