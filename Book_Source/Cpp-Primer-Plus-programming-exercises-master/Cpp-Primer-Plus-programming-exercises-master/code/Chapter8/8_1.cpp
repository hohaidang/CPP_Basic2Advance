// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<string>

#if(0)
好吧，这个题实在是太尿性了。我一开始都没能理解调用次数是什么意思，参考了网上其他人的答案才明白过来：
http://m.blog.csdn.net/blog/zhaoshu01234/47306759
#endif

using namespace std;

int cnt = 0;

void func(char* str,int flag = 0)
{
    cnt++;
    if(flag){
        for(int i=0;i<cnt;++i) cout << str << endl;
    }
    else cout << str << endl;
}

int main()
{
    char str1[] = "string 1 !";
    char str2[] = "string 2 !";
    cout << "----------one argument: str----------" << endl;
    func(str1);
    func(str2);
    cout << "-------two arguments: str , 0--------" << endl;
    func(str1,0);
    func(str2,0);
    cout << "-------two arguments: str , 1--------" << endl;
    func(str1,1);
    func(str2,1);

    return 0;
}
