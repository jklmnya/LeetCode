#include "headers/CoreMinial.h"

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0;
        sort(people.begin(), people.end());
        int start = 0, end = people.size() - 1;
        while(start < end) {
            if (people[start] + people[end] <= limit) {
                start++;
            }
            end--;
            res++;
        }
        if (start == end) {
            res++;
        }
        return res;
    }
};