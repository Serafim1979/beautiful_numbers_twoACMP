#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<cstring>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::max;
using std::min;
using std::setfill;
using std::setw;
using std::string;

int digit_sum(int n);
int digit_count(int n);

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    if(!in)
    {
        cout << "Unable to open file!" << endl;
        exit(1);
    }

    int n, my_count = 0, quantity = 1;
    in >> n;

    while(true)
    {
        if(digit_sum(quantity) % digit_count(quantity) == 0)
        {
            my_count++;
            if(my_count == n)
            {
                out << quantity;
                return 0;
            }
        }
        quantity++;
    }


    in.close();
    out.close();

    return 0;
}
//////////////////////////////////////////////////////
int digit_sum(int n)
{
    int sum = 0;
    while(n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
//////////////////////////////////////////////////////
int digit_count(int n)
{
    int my_count = 0;
    while(n > 0)
    {
        my_count++;
        n /= 10;
    }
    return my_count;
}
