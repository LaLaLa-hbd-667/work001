//F - 统计单词数。(P1308)
#include <iostream>
#include <string>
#include <cctype> // 包含 tolower 函数

using namespace std;

// 辅助函数：将字符串全部转换为小写
string toLowerCase(string s) {
    for (char &c : s) {             
        c = tolower(c);
    }
    /*传统写法:
    for (int i = 0; i < s.size(); ++i) {
        s[i] = tolower(s[i]);
    }
        用范围 for 循环，
        连下标 i 都不用管了，直接专注于“我要对每个元素干什么”。
    */
    /*
    1. 核心语法 for (char &c : s)
    · s 就是你要遍历的字符串（其实就是一个装字符的容器）。
    · 冒号 : 读作“在……之中”。
    · 连起来就是：遍历字符串 s 中的每一个字符，每次循环把当前字符起个名叫 c。
    2. 为什么 c 前面有个 &？（极其关键！）
    这里的 & 是引用符号，这也是这段代码能修改字符串的秘诀：
    · 如果没有 &（写成 char c : s）：这叫做“值拷贝”。每次循环，
      系统会复制出一个一模一样的字符给 c。你在循环里改 c，原字符串 s 毫无反应。
    · 加了 &（写成 char &c : s）：这叫做“引用”。此时 c 就是 s 里那个字符的“别名”
     （或者说是直接指向了那个字符）。你改 c，就是直接改 s 本身！
    3. c = tolower(c); 是干嘛的？
    tolower() 是 C++ 自带的函数（全称 to lower），它的作用是把大写字母变成小写字母。
    如果本来就是小写或者数字/符号，它就原样返回。
    所以这句代码的意思就是：把当前的字符变成小写，然后覆盖掉原来的位置。
    */
    return s;
}

int main() {
    string target, text;
    
    // 使用 getline 读取整行，防止包含空格的文章被截断
    getline(cin, target);
    getline(cin, text);
    
    // 将目标单词和文章都转换为小写，实现不区分大小写
    target = toLowerCase(target);
    text = toLowerCase(text);
    
    int count = 0;          // 记录出现次数
    int first_pos = -1;     // 记录第一次出现的位置
    int n = text.length();
    
    // 手动遍历文章，按空格切分出独立的单词
    for (int i = 0; i < n; ) {
        // 跳过空格
        if (text[i] == ' ') {
            i++;
            continue;
        }
        
        // 记录当前单词的起始位置
        int start = i;
        
        // 找到当前单词的结束位置
        while (i < n && text[i] != ' ') {
            i++;
        }
        
        // 截取当前的单词
        // 语法：text.substr(起始索引, 截取长度)
        string current_word = text.substr(start, i - start);
        
        // 判断截取出来的单词是否与目标单词完全匹配
        if (current_word == target) {
            count++;
            if (first_pos == -1) {
                first_pos = start; // 记录第一次匹配到的起始位置
            }
        }
    }
    
    // 输出结果
    if (count > 0) {
        cout << count << " " << first_pos << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}