//
// Created by 熊文豪 on 2022/3/9.
//
#include <iostream>
#include "SeqList.h"

class Josephus
        {
public:
    Josephus(int n, int start, int distance)
    {
        if (start < 0 || start > n || distance < 0 || distance > n)
        {
            std::cout << "输入错误！" << std::endl;
            return;
        }
        std::cout << "Josephus问题："<<n<<"个人,"<<"从"<<start<<"开始,"<<"间隔为"<<distance<< std::endl;
        SeqList<char> *list=new SeqList<char>(n);
        for (int i = 0; i < n; i++)
        {
            list->insert(('A' + i));
        }
        list->print();
        while (n> 1)
        {
            start = (start + distance - 1) % n;
            std::cout <<"删除"<<list->remove(start) <<" ";
            list->print();
            n--;
        }
        std::cout << "最后剩下" << list->get(0) << std::endl;
    }
};

int main()
{
    new Josephus(5, 1, 3);
    return 0;
}