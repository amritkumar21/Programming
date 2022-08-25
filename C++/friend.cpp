#include<iostream>
using namespace std;

class Complex
{
    private:
      int a,b;
    public:
      void setData(int x,int y)
      {
        a=x;
        b=y;
      }
      void showData()
      {
        cout<<"\n"<<a<<b;
      }
      friend void fun();
};

void fun()
{
  Complex c;
  c.setData(3,4);
  cout<<"Sum is"<<c.a+c.b;
}

int main()
{
  fun();
}

