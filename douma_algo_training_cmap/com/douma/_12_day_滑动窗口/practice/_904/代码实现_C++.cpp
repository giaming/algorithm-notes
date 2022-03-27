class Solution {
public:
    int totalFruit(vector<int>& tree) {
        // 收集的水果总量最大值
        int res = 0;

        // 定义统计窗口中每种水果类型对应的水果的个数
        // key 是水果种类
        // value 是收集到的水果数
        unordered_map<int, int> counter;

        // 维护滑动窗口
        int left = 0;
        int right = 0;
        while (right < tree.size()) {
            // 统计当前 right 指向水果类型收集到的水果数
            counter[tree[right]]++;

            // left 指针移动
            // 移动时机：当前窗口水果种类超过了 2 种
            // 移动策略：
            //      1. 当前窗口中 left 指向的水果种类对应的水果数减 1
            //      2. 如果这个 left 指向的水果种类对应的水果数为 0，那么从当前窗口中移除掉这个水果种类
            while (counter.size() > 2) {
                counter[tree[left]]--;
                if (counter[tree[left]] == 0) counter.erase(tree[left]);
                left++;
            }

            // 到了这里，当前窗口中最多只有两种水果种类
            // 计算收集的水果总量最大值
            res = max(res, right - left + 1);

            // 右指针移动
            right++;
        }

        return res;
    }
};