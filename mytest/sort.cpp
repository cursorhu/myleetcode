#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <stdlib.h>

using namespace std;

//以普通函数的方式实现自定义排序规则
bool myComp(int i, int j) {
    return (i < j);
}

//以对象的方式实现自定义排序规则
class myCompOper {
public:
    bool operator() (int i, int j) {
        return (i > j);
    }
};

//打印数组
void print_array(std::vector<int> &a, const char *s)
{
    printf("%s\n", s);
    vector<int>::iterator it;
    for (it = a.begin(); it != a.end(); ++it)
    {
        printf("%d ", *it);
    }
    printf("\n");
}

int main() {
    //std::vector<int> array;
    //char num;
    //while(cin.get() != '\n')
    //{
    //    cin >> num;
    //    array.push_back(num);
    //}

    vector<int> array{1,3,4,2,5,7,6,8,9};
    print_array(array, "input array:");

    //默认排序，从小到大
    std::sort(array.begin(), array.end());
    print_array(array, "default sort:");

    //使用STL标准库提供的其它比较规则, 比如 greater<T>，从大到小
    std::sort(array.begin(), array.end(), std::greater<int>());
    print_array(array, "std::greater<T> sort:");

    //自定义比较规则: 普通函数
    std::sort(array.begin(), array.end(), myComp);
    print_array(array, "myComp sort:");

    //自定义比较规则: 类内运算符重载
    std::sort(array.begin(), array.end(), myCompOper());
    print_array(array, "myCompOper sort:");

    //自定义比较规则: Lambda匿名函数
    std::sort(array.begin(), array.end(), [](int i, int j) {return i < j;});
    print_array(array, "Lambda sort:");


    return 0;
}