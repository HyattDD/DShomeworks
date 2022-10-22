#include <iostream>

using namespace std;

int kmp_search(string str, string pat);
void build_next(int* next, const string& pat);

int main() {
    int index = kmp_search("aabbaabbf", "aabbf");
    cout << index << endl;
}

int kmp_search(string str, string pat) {
    int next[pat.size()];
    // 先计算next数组
    build_next(next, pat);
    // 主串中的指针
    int domIndex = 0;
    // 子串也即模式串中的指针
    int subIndex = 0;
    // 在整个while的过程中domIndex是只增不减的，这也是kmp的高效所在
    while (domIndex < str.length())
    {
        // 字符匹配成功，指针后移
        if (str[domIndex] == pat[subIndex]) {
            domIndex++;
            subIndex++;
        } else if (subIndex > 0) { // 字符中途匹配失败，根据next数组进行跳过部分字符后重新匹配
            subIndex = next[subIndex - 1];
        } else domIndex++;  // 从一开始就匹配失败，主字符串指针直接后移

        // 匹配成功则返回主串中该子串出现的位置
        if (subIndex == pat.length()) return domIndex - subIndex;  
    }
    // 匹配失败返回-1
    return -1;
}


void build_next(int* next, const string& pat) {
    // 构造next数组，next数组第一位设置为-1
    int j = -1;
    next[0] = j;
    // 遍历模式串，求出next数组的内容
    for (int i = 0; i < pat.size(); i++) {
        while (j >= 0 && pat[i] != pat[j + 1]) {
            j = next[j];
        }
        if (pat[i] == pat[j + 1]) {
            j++;
        }
        next[i] = j;
    }
}