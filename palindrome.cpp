#include <iostream>
using namespace std;

int main()
{
     int orignalNumber, number, digitPlace, revNumber = 0;

     cout << "Enter a positive number: ";
     cin >> number;
     if (number < 0){
         cout << "Invalid Input";
         return 1;
     }
     
     orignalNumber = number;
     do
     {
         digitPlace = number % 10;
         revNumber = (revNumber * 10) + digitPlace;
         number = number / 10;
     } while (number != 0);

     cout << " The reverse of the number is: " << revNumber << endl;

     if (orignalNumber == revNumber)
         cout << " The number is a palindrome.";
     else
         cout << " The number is not a palindrome.";

    return 0;
}
