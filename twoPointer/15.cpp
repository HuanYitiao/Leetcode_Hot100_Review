#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        // TODO: 你来填这里
        // 暴力 O(n³) 会超时
        // 提示：先排序，固定一个数，剩下两个用双指针找
        // 难点：去重！排序后跳过相同的元素
    }
};

// ============== 测试框架 ==============

vector<vector<int>> normalize(vector<vector<int>> v)
{
    for (auto& triplet : v)
        sort(triplet.begin(), triplet.end());
    sort(v.begin(), v.end());
    return v;
}

void runTest(int testNum, vector<int> input, vector<vector<int>> expected)
{
    Solution sol;
    auto     result = sol.threeSum(input);

    auto normResult   = normalize(result);
    auto normExpected = normalize(expected);

    bool pass = (normResult == normExpected);
    cout << "Test " << testNum << ": " << (pass ? "✅ PASS" : "❌ FAIL");
    if (!pass)
    {
        cout << "  expected " << expected.size() << " triplets, got " << result.size();
        cout << endl << "  Your output: ";
        for (auto& t : result)
        {
            cout << "[" << t[0] << "," << t[1] << "," << t[2] << "] ";
        }
    }
    cout << endl;
}

int main()
{
    cout << "===== LeetCode 15. 三数之和 =====" << endl << endl;

    // Test 1: 基本用例
    runTest(1, { -1, 0, 1, 2, -1, -4 }, { { -1, -1, 2 }, { -1, 0, 1 } });

    // Test 2: 无解
    runTest(2, { 0, 1, 1 }, {});

    // Test 3: 全零
    runTest(3, { 0, 0, 0 }, { { 0, 0, 0 } });

    // Test 4: 不够三个元素
    runTest(4, { 1, 2 }, {});

    // Test 5: 大量重复（去重是关键）
    runTest(5, { -1, -1, -1, 2, 2, 2 }, { { -1, -1, 2 } });

    // Test 6: 多组解
    runTest(6, { -2, 0, 1, 1, 2 }, { { -2, 0, 2 }, { -2, 1, 1 } });

    // Test 7: 含正负和零
    runTest(7,
            { -4, -2, -1, 0, 1, 2, 3, 4 },
            { { -4, 0, 4 }, { -4, 1, 3 }, { -2, -1, 3 }, { -2, 0, 2 }, { -1, 0, 1 } });

    // Test 8: 全部相同非零
    runTest(8, { 1, 1, 1, 1 }, {});

    return 0;
}