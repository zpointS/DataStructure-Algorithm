# 写C++的时候的一些小心得
本文将以栈的方式书写，也就是最近期的新的将置于顶部，以往的知识点就将被推至底部

主要是太懒了，等知识点多起来了会做一个分类的

### 解读typedef struct node{}a,*b
简单来讲，直接将变量名扔掉就可以清晰的看懂了。[具体可看此处](https://blog.csdn.net/qq_35624030/article/details/105341859)。
```cpp
typedef struct Node{
    ElementType value;
    Node *ptr;
}BTNode,*BTTree[];
```
则BTTree是什么呢？事实上就是:
```cpp
typedef struct Node (*)[];
```
也即把 struct Node (*)[] 重命名为了BTTree！！
### C++读入文件
1. 逐行读入
```cpp
string FileName;
ifstream FileObject;
FileObject.open(FileName.data());
assert(FileObject.is_open());//打开失败则返回错误消息并退出程序

string s;
while(getline(FileObject, s))
    cout<<s<<endl;

FileObject.close();
```
2. 逐字符读入(不读入空格与回车)
```cpp
char c;
while(!FileObject.eof()){
    FileObject >> c;
    cout << c << endl;
}
```
3. 逐字符读入(读入空格与回车)
```cpp
FileObject >> noskipws;
```

### 万能头文件#include<bits/stdc++.h>
头文件#include<bits/stdc++.h>包含了目前C++中所包含的所有头文件，就可以省去很多书写其他头文件的必要了！

常见的STL容器也都包含在内，完全**只需要写这一个头文件**就可以了。


### 主函数int main(int argc, char* argv[])
一句话：**argc表示总共有多少参数，argv是记录参数的数组。**

在main(int argc, char* argv[], char **env)中：
    
    第一个参数，int型的argc，为整型，用来统计程序运行时发送给main函数的命令行参数的个数，在VS中默认值为1。 
    第二个参数，char*型的argv[]，为字符串数组，用来存放指向的字符串参数的指针数组，每一个元素指向一个参数。各成员含义如下： 
        argv[0]指向程序运行的全路径名 
        argv[1]指向在DOS命令行中执行程序名后的第一个字符串 
        argv[2]指向执行程序名后的第二个字符串 
        argv[3]指向执行程序名后的第三个字符串 
        argv[argc]为NULL。

## VSCode中的配置类问题
### [使用其他库/头文件](https://blog.csdn.net/cbc000/article/details/80670413)
Ctrl+Shift+P 搜索Edit configuration中添加json文件后，写入头文件的相对路径。

