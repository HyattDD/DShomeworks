/*
本程序实现的功能：
1.实现读取pie后的1000万位小数
2.在1000万位数字中查找自己的生日
3.将查找速度优化到较快的范围内
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

string readFile(string filename);
int kmp_search(string str, string pat);
void build_next(int* next, const string& pat);

int main()
{
	clock_t start = clock();
	// 定义一些关键的变量：字符串、模式串、查找结果下标、圆周率后小数位数
	string pie = readFile("pi-10million.txt");
	string pat;
	int res = 0;
	int len = pie.length();
	// 读取8位生日
	cout << "请输入8位数字生日,例如：20221020:" << endl;
	getline(cin, pat);
	// 计算并输出查询结果
	res = kmp_search(pie, pat);
	if (res == -1) cout << "查找完毕，该生日不在圆周率小数前"<< len << "位中" << endl; 
	else cout << "查找完毕，该生日在圆周率小数第"<< res << "位" << endl;
	clock_t finish = clock();
	printf("本次查找共计耗时%.4f秒\n", (finish - start)/(1e6));
}

// 将文件中1000万位的数字读成字符串
string readFile(string filename) {
	// 创建一个流，并且与文件相接
	ifstream srcfile(filename);
	// 创建一个ostringstream对象，用于动态接收字符
	ostringstream buffer;
	//将字符不断地读入到ostringstream对象buffer缓冲区中
	char ch;
	while(buffer && srcfile.get(ch)) {
		buffer.put(ch);
	}
	// 返回缓冲区中的内容即为读入的字符
	return buffer.str();
}


// kmp算法实现
int kmp_search(const string str, const string pat) {
	if (pat.length() > str.length()) return -1;
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

// 构造next数组
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

