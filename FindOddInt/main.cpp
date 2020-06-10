// CA.FindOddInt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

#include <vector>

void erase(std::vector<int>& myNumbers_in, int number_in);

int findOdd(const std::vector<int>& nums) {

    std::vector<int> numbers = nums;
    int result = -1;
    int i = 0;
    while(numbers.size())
    {

        if (numbers.size() == 0) {
            return -1;
        }
        else if (std::count(numbers.begin(), numbers.end(), numbers[i]) % 2 == 0) {
            int mustDeleted = numbers[i];

           /* for (size_t j = 0; j < numbers.size(); j++)
            {
                if (numbers[j] == mustDeleted)
                {
                    numbers.erase(numbers.begin()+j);
                }
            }*/
            erase(numbers, mustDeleted);

        }
        else return numbers[i];

        
    }

    return result;
}


void erase(std::vector<int>& myNumbers_in, int number_in)
{
    std::vector<int>::iterator iter = myNumbers_in.begin();
    while (iter != myNumbers_in.end())
    {
        if (*iter == number_in)
        {
            iter = myNumbers_in.erase(iter);
        }
        else
        {
            ++iter;
        }
    }

}
using V = std::vector<int>;

int main()
{
    std::cout << "Hello World!\n" << findOdd(V{ 1,1,1,1,1,1,10,1,1,1,1 });
    std::cout << "Hello World!\n" << findOdd(V{ 20,1,1,2,2,3,3,5,5,4,20,4,5 });
    std::cout << "Hello World!\n" << findOdd(V{ 1 });
    
    

    system("pause");

}
