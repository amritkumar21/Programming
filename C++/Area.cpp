#include<iostream>
using namespace std;

int area(int l, int b)
{
  return l*b;
}
float area(int r)
{
  return 3.14*r*r;
}\

int main()
{
  int r;
  cout<<"area of circle is"<<area(6);
  cout<<"area of rectangle is"<<area(3,4);

}