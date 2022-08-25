#include<iostream>
#include<string.h>
using namespace std;
struct book
{
  int bookid;
  char title[20];
  float price;
};

void main()
{
  book b1 = {100,"Harry potter",450};
  book b2;
  b2.bookid = 200;
  strcpy(b2.title,"Amrit");
  b2.price = 100;
}