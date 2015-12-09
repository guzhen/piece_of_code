#include <map>
#include <string>
#include <iostream>

static const std::map<int, std::string> map=
{{1,"一"},{2,"二"},{3,"三"},{4,"四"},{5,"五"},{6,"六"},{7,"七"},
{8,"八"},{9,"九"},{10,"十"},{100,"百"},{1000,"千"},{10000,"万"}};

std::string num2Chinese(int num)
{
    std::string cn;
    int n=num,pre=0;
    for (auto it = map.crbegin();it!=map.crend();++it)
    {
        int count=0;
        for (;n>=it->first;n-=it->first)++count;
        if(!count)continue;
        if (pre/10>it->first) cn+="零";
        if (it->first>=10 && (count!=1||num>20))cn+=map.at(count);
        cn += it->second;
        pre = it->first;
    }
    return cn;
}

int main()
{
    num2Chinese(1230000);
    return 0;
}
