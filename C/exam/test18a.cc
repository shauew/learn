#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    while(cin >> str)
    {
        int flag[4] = {0};
        if(str.size() <= 8) goto NG;
        for(int i = 0; i < str.size(); ++i)
        {
            if(str[i] >= 'a' && str[i] <= 'z')        flag[0] = 1;
            else if(str[i] >= 'A' && str[i] <= 'Z')   flag[1] = 1;
            else if(str[i] >= '0' && str[i] <= '9')   flag[2] = 1;
            else                                      flag[3] = 1;
        }
        if(flag[0] + flag[1] + flag[2] + flag[3] < 3) goto NG;
        for(int i = 0; i <= str.size()-6; i++)
            for(int j = i+3;j <=str.size()-3;j++)
                if(str.substr(j,3)==str.substr(i,3))  goto NG;
        cout << "OK" << endl;continue;/*continue必不可少，当程序输出OK后，执行continue直接进入下一循环处理下一行密码。没有continue的话程序会继续执行NG:cout << "NG" << endl;*/
        NG:cout << "NG" << endl;/*因为本行为while(cin>>str)的最后一句程序，执行完后进入下一循环处理下一行密码，故本行不需要添加continue*/
    }
    return 0;
}