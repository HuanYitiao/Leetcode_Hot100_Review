#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    void moveZeroes(vector<int>& nums)
    {
        int left  = 0;
        int right = 0;
        while (right < nums.size())
        {
            if (nums[right] != 0)
            {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};

// ============== 测试框架 ==============

void runTest(int testNum, vector<int> input, vector<int> expected)
{
    Solution sol;
    sol.moveZeroes(input);

    bool pass = (input == expected);
    cout << "Test " << testNum << ": " << (pass ? "✅ PASS" : "❌ FAIL");
    if (!pass)
    {
        cout << "  expected [";
        for (int i = 0; i < expected.size(); i++)
        {
            cout << expected[i] << (i < expected.size() - 1 ? "," : "");
        }
        cout << "], got [";
        for (int i = 0; i < input.size(); i++)
        {
            cout << input[i] << (i < input.size() - 1 ? "," : "");
        }
        cout << "]";
    }
    cout << endl;
}

int main()
{
    cout << "===== LeetCode 283. 移动零 =====" << endl << endl;

    // Test 1: 基本用例
    runTest(1, { 0, 1, 0, 3, 12 }, { 1, 3, 12, 0, 0 });

    // Test 2: 单个零
    runTest(2, { 0 }, { 0 });

    // Test 3: 无零
    runTest(3, { 1, 2, 3 }, { 1, 2, 3 });

    // Test 4: 全零
    runTest(4, { 0, 0, 0 }, { 0, 0, 0 });

    // Test 5: 零在末尾（已经是答案）
    runTest(5, { 1, 2, 0, 0 }, { 1, 2, 0, 0 });

    // Test 6: 零在开头
    runTest(6, { 0, 0, 1 }, { 1, 0, 0 });

    // Test 7: 交替出现
    runTest(7, { 0, 1, 0, 2, 0, 3 }, { 1, 2, 3, 0, 0, 0 });

    // Test 8: 单个非零
    runTest(8, { 5 }, { 5 });

    return 0;
}