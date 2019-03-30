#include <iostream>

//using namespace std;

int main()
{
    std::cout << "test message";
    int base = 3;
    int exp = 10;
    int ans = 1;
    for(int i = 1; i <= exp; i++)
    {
        ans *= base;
    }
    std::cout << ans;

    return 0;
}
