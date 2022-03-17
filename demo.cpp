#include <iostream>
using namespace std;
int main()
{
    int *p = (int *)malloc(sizeof(int) * 10);
            std::cout << *(p+4) << std::endl;
}
