#include <iostream>
#include <stack>
#include <queue>
using namespace std;

bool IsPalindromic(string str);

int main() {
    string str;
    bool flag = false;
    cout << "Please input str: " << endl;
    cin >> str;
    flag = IsPalindromic(str);
    if (flag == true) cout << "Yes" << endl;
    if (flag == false) cout << "No" << endl;
}

// 判断一个字符串是不是回文字符串
/*
当我们拥有栈和队列的数据结构时，可以将字符串分别送入一个栈和一个队列中
再分别将队列和栈中的元素依次弹出，每轮对比都相同时，字符串一定是回文字符串
为了减少比较次数，可以将停止条件设置为比较完字符串的一半即可
*/
bool IsPalindromic(string str) {
    stack<int> st;
    queue<int> qu;
    // cout << str.length() << endl;
    for (int i = 0; i < str.length(); i++)
    {
        st.push(str[i]);
        qu.push(str[i]);
    }
    
    for (int i = 0; i < str.length() / 2; i++)
    {
        if (st.top() != qu.front()) return false;
        st.pop();
        qu.pop();
    }
    return true;
}