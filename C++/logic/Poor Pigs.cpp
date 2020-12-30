#include "headers/CoreMinial.h"

/**
 * 
 * 先看1只小猪，60分钟的话，它最多可以判断出 60/15+1 = 5只水桶中的毒药桶。每隔十五分钟喝一次水，喝四次，如果幸运的话活了下来，就是最后一桶。
 * 再接着看2只小猪，60分钟，它最后可以判断出25只水桶，可以这样：
 * 00     01     02     03      04
 * 10     11     12     13      14
 * 20     21     22     23      24 
 * 30     31     32     33      34
 * 40     41     42     43      44
 * 将桶像上面摆放，第一只猪猪喝掉第一二三四五混合后的水，每隔15分钟喝一次，这样如果不幸运，在x行被毒死了，则证明毒药在第x行，幸运活下来的话，
 * 则毒药在第五行；在第一只猪猪和的同时让第二只猪猪喝第一二三四列混合后的水，如果在y列被毒死，则毒药在第y列，如果活下来，则毒药在第五列。
 * 这样第一只猪猪判断出了横坐标x，第二只猪猪判断出来纵坐标y，则可以知道哪桶水有毒。
 * 
 * 
 **/

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if (buckets == 1) { return 0; }
        int weight = minutesToTest / minutesToDie + 1;
        int res = 1;
        while (pow(weight, res) < buckets) {
            res++;
        }
        return res;
    }
};