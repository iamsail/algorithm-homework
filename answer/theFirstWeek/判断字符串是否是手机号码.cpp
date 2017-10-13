#include <iostream>
#include <regex>
using namespace std;
int main() {


//    regex 表示一个正则表达式
//    regex_match 表示一个正则表达式的匹配操作，目标字符串与正则表达式完全匹配才返回true（python中的macth是从开头进行匹配）
//    regex_search 表示一个正则表达式的搜索操作，将在目标字符串中搜索所有匹配的结果
//    smatch 保存在string对象中搜索到的匹配结果（python存在group中，group返回匹配的第一个结果）
//    sregex_iterator smatch的迭代器？（python的groups返回匹配结果的列表）
//    regex_replace 使用给定格式替换一个正则表达式



    regex regTe1("^1\\d{10}$");
//    smatch r1;
    string s1;
    cin >> s1;
//    cout << regex_match(s1, r1,regTe1) << endl;
    cout << regex_match(s1,regTe1) << endl;
    return 0;
}




