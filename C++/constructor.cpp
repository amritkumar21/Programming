#include<iostream>
using namespace std;
class Complex
{
  private:
    int a, b;
  public:
   void setData(int x, int y)
   {
     a=x;
     b=y;
   }
   void showData()
   {
    cout<<a<<b;
   }
  Complex operator + (Complex c)
  {
      Complex temp;
      temp.a = c.a+a;
      temp.b = c.b+b;
      return temp;
  }

};
class Integer
{
  private:
    int x;
  public:
    void setData(int a)
    {
      x=a;
    }
    void showData()
    {
      cout<<"x = "<<x<<" "; 
    }
    Integer operator ++ ()
    {
        Integer i;
        i.x = ++x;
        return i;
    }
};

int main()
{

  Integer i1,i2;
  i1.setData(3);
  i2 = i1.operator++();
  i1.showData();
  i2.showData();

  
}


