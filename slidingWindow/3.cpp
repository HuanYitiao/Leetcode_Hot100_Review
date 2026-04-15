#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> lookup;

        int l = 0;
        int r = 0;

        int res = 0;
        while (r < s.size())
        {
            char c = s[r];
            while (lookup.end() != lookup.find(c))
            {
                lookup.erase(s[l]);
                l++;
            }
            lookup.insert(c);
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};

// ============== 测试框架 ==============

void runTest(int testNum, string input, int expected)
{
    Solution sol;
    int      result = sol.lengthOfLongestSubstring(input);

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
    cout << "===== LeetCode 3. 无重复字符的最长子串 =====" << endl << endl;

    // Test 1: 基本用例
    runTest(1, "abcabcbb", 3);

    // Test 2: 全部相同
    runTest(2, "bbbbb", 1);

    // Test 3: 重复在中间
    runTest(3, "pwwkew", 3);

    // Test 4: 空字符串
    runTest(4, "", 0);

    // Test 5: 单个字符
    runTest(5, "a", 1);

    // Test 6: 全部不重复
    runTest(6, "abcdef", 6);

    // Test 7: 含空格和符号
    runTest(7, "a b c", 3);

    // Test 8: 重复在首尾
    runTest(8, "abca", 3);

    // Test 9: 两个字符交替
    runTest(9, "ababab", 2);

    // Test 10: 较长输入
    runTest(10, "dvdf", 3);

    return 0;
}