/*本文件中提供kmp算法相当简洁的写法实现*/
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010, M = 1000010;

int main() {
    int next[N];
    int n, m;
    char p[N], s[M];
    // 这里在输入时就把元素的存放下标变为从1开始的了    
    scanf("%d%s", &n, p + 1);
    scanf("%d%s", &m, s + 1);

    // 构造next数组的过程是用模式串自己匹配自己
    // next[1]=0，代表从头开始匹配，所以直接从i=2开始讨论即可
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && p[i] != p[j + 1]) j = next[j];
        if (p[i] == p[j + 1]) j ++;
        next[i] = j;
    }

    for (int i = 1, j = 0; i <= m; i++) {
        while (j && s[i] != p[j + 1]) j = next[j];
        if (s[i] == p[j + 1]) j ++; 
        if (j == n) printf("%d\n ", i - n);
    }
    return 0;
}