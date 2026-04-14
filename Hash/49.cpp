#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> group;
        for (string& s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            group[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& [_, val] : group)
        {
            result.push_back(val);
        }
        return result;
    }
};

// ============== 测试框架 ==============

// 辅助函数：排序结果以便比较（因为输出顺序不固定）
vector<vector<string>> normalize(vector<vector<string>> groups)
{
    for (auto& g : groups)
    {
        sort(g.begin(), g.end());
    }
    sort(groups.begin(), groups.end());
    return groups;
}

void runTest(int testNum, vector<string> input, vector<vector<string>> expected)
{
    Solution sol;
    auto     result = sol.groupAnagrams(input);

    auto normResult   = normalize(result);
    auto normExpected = normalize(expected);

    bool pass = (normResult == normExpected);

    cout << "Test " << testNum << ": " << (pass ? "✅ PASS" : "❌ FAIL") << endl;

    if (!pass)
    {
        cout << "  Expected " << expected.size() << " groups, got " << result.size() << " groups" << endl;
        cout << "  Your output:" << endl;
        for (auto& group : result)
        {
            cout << "    [";
            for (int i = 0; i < group.size(); i++)
            {
                cout << "\"" << group[i] << "\"";
                if (i < group.size() - 1)
                    cout << ", ";
            }
            cout << "]" << endl;
        }
    }
}

int main()
{
    cout << "===== LeetCode 49. 字母异位词分组 =====" << endl;
    cout << endl;

    // Test 1: 基本用例
    runTest(1, { "eat", "tea", "tan", "ate", "nat", "bat" }, { { "bat" }, { "nat", "tan" }, { "ate", "eat", "tea" } });

    // Test 2: 空字符串
    runTest(2, { "" }, { { "" } });

    // Test 3: 单个字符
    runTest(3, { "a" }, { { "a" } });

    // Test 4: 全部相同
    runTest(4, { "abc", "bca", "cab" }, { { "abc", "bca", "cab" } });

    // Test 5: 全部不同
    runTest(5, { "abc", "def", "ghi" }, { { "abc" }, { "def" }, { "ghi" } });

    // Test 6: 包含重复字母的异位词
    runTest(6, { "aab", "aba", "baa", "abb", "bab" }, { { "aab", "aba", "baa" }, { "abb", "bab" } });

    // Test 7: 空数组边界
    // strs.length >= 1 根据题意，所以最小是1个元素

    cout << endl;
    cout << "=============================" << endl;
    cout << "编译: g++ -std=c++17 -o solution solution.cpp" << endl;
    cout << "运行: ./solution" << endl;

    return 0;
}