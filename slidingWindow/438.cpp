#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> cntp(26);
        for (char c : p)
        {
            cntp[c - 'a']++;
        }

        vector<int> ans;
        vector<int> cnts(26);
        for (int r = 0; r < s.size(); r++)
        {
            cnts[s[r] - 'a']++;
            int l = r - p.size() + 1;
            if (l < 0)
            {
                continue;
            }

            if (cnts == cntp)
            {
                ans.push_back(l);
            }
            cnts[s[l] - 'a']--;
        }
        return ans;
    }
};

// ============== 测试框架 ==============

void runTest(int testNum, string s, string p, vector<int> expected)
{
    Solution sol;
    auto     result = sol.findAnagrams(s, p);

    bool pass = (result == expected);
    cout << "Test " << testNum << ": " << (pass ? "✅ PASS" : "❌ FAIL");
    if (!pass)
    {
        cout << "  expected [";
        for (int i = 0; i < expected.size(); i++)
        {
            cout << expected[i] << (i < expected.size() - 1 ? "," : "");
        }
        cout << "], got [";
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << (i < result.size() - 1 ? "," : "");
        }
        cout << "]";
    }
    cout << endl;
}

int main()
{
    cout << "===== LeetCode 438. 找到字符串中所有字母异位词 =====" << endl << endl;

    // Test 1: 基本用例
    runTest(1, "cbaebabacd", "abc", { 0, 6 });

    // Test 2: 连续异位词
    runTest(2, "abab", "ab", { 0, 1, 2 });

    // Test 3: 无匹配
    runTest(3, "hello", "xyz", {});

    // Test 4: s比p短
    runTest(4, "ab", "abc", {});

    // Test 5: 完全相同
    runTest(5, "abc", "abc", { 0 });

    // Test 6: 单字符
    runTest(6, "aaaa", "a", { 0, 1, 2, 3 });

    // Test 7: p有重复字符
    runTest(7, "aabaa", "aa", { 0, 3 });

    // Test 8: 全部是异位词
    runTest(8, "abcabc", "abc", { 0, 1, 2, 3 });

    return 0;
}