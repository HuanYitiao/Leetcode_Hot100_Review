#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    int subarraySum(vector<int>& nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0]     = 1;
        int count = 0;
        int pre   = 0;
        for (int& n : nums)
        {
            pre += n;
            if (mp.end() != mp.find(pre - k))
            {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};

// ============== 测试框架 ==============

void runTest(int testNum, vector<int> nums, int k, int expected)
{
    Solution sol;
    int      result = sol.subarraySum(nums, k);

    bool pass = (result == expected);
    cout << "Test " << testNum << ": " << (pass ? "✅ PASS" : "❌ FAIL");
    if (!pass)
    {
        cout << "  (expected " << expected << ", got " << result << ")";
    }
    cout << endl;
}

int main()
{
    cout << "===== LeetCode 560. 和为K的子数组 =====" << endl << endl;

    // Test 1: 基本用例
    runTest(1, { 1, 1, 1 }, 2, 2);

    // Test 2: 连续求和
    runTest(2, { 1, 2, 3 }, 3, 2);

    // Test 3: 单个元素等于k
    runTest(3, { 5 }, 5, 1);

    // Test 4: 单个元素不等于k
    runTest(4, { 5 }, 3, 0);

    // Test 5: 含负数
    runTest(5, { 1, -1, 1, -1 }, 0, 4);

    // Test 6: 全部为零
    runTest(6, { 0, 0, 0 }, 0, 6);

    // Test 7: 负数求和
    runTest(7, { -1, -1, 1 }, -2, 1);

    // Test 8: 整个数组和为k
    runTest(8, { 1, 2, 3 }, 6, 1);

    // Test 9: 无解
    runTest(9, { 1, 2, 3 }, 100, 0);

    return 0;
}