class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size() / 2;
        unordered_set<int> mapper;
        for (auto candy : candyType) {
            mapper.insert(candy);
        }
        return min((int)mapper.size(), n);
    }
};
