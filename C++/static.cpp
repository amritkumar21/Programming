#include<iostream>
using namespace std;

class Account
{
  private:
   int balance;
   static float roi;
  public:
   
   void setBalance(int num)
   {
     balance = num;
   }
   void static setRoi(float r)
   {
      roi = r;
   }
};
//float Account:: roi = 3.5f;

int main()
{
   Account a1;
   a1.setBalance(2);
   a1.setRoi(4.3);
   Account::setRoi(5);
   
}