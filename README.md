# doc

UTF-8 采用变长度字节来表示字符，理论上最多可以到 6 个字节长度。

UTF-8 编码兼容了 ASC II(0-127)， 也就是说 UTF-8 对于 ASC II 字符的编码是和 ASC II 一样的。

对于超过一个字节长度的字符，才用以下编码规范：

左边第一个字节1的个数表示这个字符编码字节的位数，例如两位字节字符编码样式为为：110xxxxx 10xxxxxx；

三位字节字符的编码样式为：1110xxxx 10xxxxxx 10xxxxxx.；

以此类推，六位字节字符的编码样式为：1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx。 xxx 的值由字符编码的二进制表示的位填入。

1字节：0xxxxxxx

2字节：110xxxxx 10xxxxxx

3字节：1110xxxx 10xxxxxx 10xxxxxx

4字节：11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

5字节：111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx

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
