
#include <iostream>
#include <string>
 
int main()//输入str字串，依次输出分割好的chr，chr为linux默认的utf8
{
    using namespace std;
    string str;//一串包含汉字的字串
    cin >> str;
    string strChar;//str中的一个汉字
    for(int i = 0; str[i] != '\0'; )
    {
        char chr = str[i];
        //chr是0xxx xxxx，即ascii码
        if((chr & 0x80) == 0)
        {
            strChar = str.substr(i,1);
            cout << strChar;
            ++i;
        }//chr是1111 1xxx
        else if((chr & 0xF8) == 0xF8)
        {
            strChar = str.substr(i, 5);
            cout << strChar;
            i+=5;
        }//chr是1111 xxxx
        else if((chr & 0xF0) == 0xF0)
        {
            strChar = str.substr(i, 4);
            cout << strChar;
            i+=4;
        }//chr是111x xxxx
        else if((chr & 0xE0) == 0xE0)
        {
            strChar = str.substr(i, 3);
            cout << strChar;
            i+=3;
        }//chr是11xx xxxx
        else if((chr & 0xC0) == 0xC0)
        {
            strChar = str.substr(i, 2);
            cout << strChar;
            i+=2;
        }
        cout<<endl;
    }
}
