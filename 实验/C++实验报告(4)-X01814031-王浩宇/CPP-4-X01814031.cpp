#include <iostream>
#include <string.h>
using namespace std;


/*请把下面的字符串分别改为你的姓名和学号*/
const char *name = "王浩宇";
const char *ID = "X01814031";

/*在下面添加你的代码
类的声明和实现代码都写在下方*/
class String
{
private:
    int length;//字符串的长度
    char *pData;//字符串的内容，注意：字符串以'\0'结尾

public:
    /*改写默认构造函数*/
    String():length(0)
    {
        pData=nullptr;
    }
    /*构造函数*/
    String(const char *s)
    {
        length=strlen(s);//初始化字符串长度
        if(length==0)//如果长度为0则将字符串内容指针指向空
        {
            pData=nullptr;
        }
        else
        {
            pData=new char[length+1];//开辟空间，多开一个char的空间用来存\0作为字符串结尾标识符
            strcpy(pData,s);//strcpy函数用来复制s的内容到Pdata中。
            pData[length]='\0';// \0作为字符串结尾标识符
        }
    }
    /*在下方编写拷贝构造函数*/
    String (const String &v)
    {
        length=v.length;//初始化字符串长度
        if(v.length==0) //如果初始化的字符串的长度为0，指针置为空指针。
        {
            pData=nullptr;
        }
        else
        {
            pData=new char[v.length+1];//开辟空间，多开一个char的空间用来存\0作为字符串结尾标识符
            strcpy(pData,v.pData);//strcpy函数用来复制s的内容到Pdata中。
            pData[v.length]='\0';// \0作为字符串结尾标识符
        }
    }
    /*在下方编写拷贝赋值运算operator=*/
    String &operator=(const String &v)
    {
        length=v.length;//初始化字符串长度
        if(v.length==0) //如果初始化的字符串的长度为0，指针置为空指针。
        {
            pData=nullptr;
        }
        else
        {
            pData=new char[v.length+1];//开辟空间，多开一个char的空间用来存\0作为字符串结尾标识符
            strcpy(pData,v.pData);//strcpy函数用来复制s的内容到Pdata中。
            pData[v.length]='\0';// \0作为字符串结尾标识符
        }
        return *this;  //返回this
    }

    /*析构函数*/
    ~String()
    {
        delete []pData;//析构函数释放空间
    }
    /*在下方编写其它成员函数*/
    int GetLength()//获得字符串的长度
    {
        return length;
    }
    bool GetChar(int index,char &ch)//获取指定位置index处的字符
    {
        if(index>=length)//如果指定的字符位置大于了字符串的长度，则返回false
        {
            return false;
        }
        else
        {
            ch=pData[index];//去除index位置的字符
            return true;
        }
    }

    bool SetChar(int index,const char ch)//把字符串位置index处的字符改变为ch
    {
        if(index>=length)//如果指定的字符位置大于了字符串的长度，则返回false
        {
            return false;
        }
        else
        {
            pData[index]=ch;//更新index位置的字符
            return true;
        }
    }

    String Concat(const String &s)//字符串s拼接到当前对象表示的字符串后面
    {
        String tep;//临时开辟一个字符串tep
        int len=s.length+length;//拼接后的长度为两个字符串的和
        tep.length=len;//更新新字符串的长度
        tep.pData=new char[len+1];//开辟空间
        strcpy(tep.pData,pData);//先把原来的字符串复制到tep中
        strcpy(tep.pData+length,s.pData);//再把连接在后面的字符串加入到tep后面
        tep.pData[len]='\0';//结尾加上字符串结束标识符/0
        *this=tep;//将tep赋值给*this
        return *this;
    }
    /*Display函数不用改写*/
    void Display() const {
        if (0 != pData)
            std::cout << pData;
        std::cout<< endl;
    }
};


/*上述代码编写完成之后，请把下面的宏改为:
#define TEST 1
*/
#define TEST 1

/*=======================================================*/
/*以下代码不要修改*/
/*=======================================================*/
int main(void) {

    std::cout << name << " " << ID << endl;

#if TEST
    String s1;
    s1.Display();

    String s2("Hello World!");
    s2.Display();
    cout << s2.GetLength() << endl;

    String s3(" C++ Programming.");
    s3.Display();
    cout << s3.GetLength() << endl;

    s2.Concat(s3);
    s2.Display();
    cout << s2.GetLength() << endl;

    char ch = 0;
    if (s2.GetChar(0, ch)) {
        s2.SetChar(0, 'h');
        s2.Display();
    }

    String s4 = String("My God!");
    s4.Display();

#endif // TEST

    return 0;
}
