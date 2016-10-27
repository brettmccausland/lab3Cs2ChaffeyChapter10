#include<iostream>
#include <vector>
#include"triangle.h"
using namespace std;
void Exercise10_1();//(done)
void Exercise10_5();//(done)
void Exercise10_6();//(done)
void Exercise10_2();//(done)
void Exercise10_12();//(done)
void Exercise10_9();//(done)
void Exercise10_14();//(done)


void print(const vector<int>& a);
bool next_permutation(vector<int>& a);
int RecursiveFactorial(int n);
void ReverseRecursively(char a[], int front, int back);
void reverse(vector<int>& a, int i, int j);

template<typename Item_type>
void Swap(Item_type& x, Item_type& y);

bool substringmatch(string find, string match);
int substringindex(string find, string match, int &index);
void indexIncrement(int& index,int increment);
void reverse();
void TowersHanoi(int m, string a, string b, string c);
int polygonArea(int x[], int y[], int b, int end);
int main()
{
    system("clear");
    cout<<"Lab 3"<<endl;
    Exercise10_1();
    Exercise10_2();
    Exercise10_14();

    Exercise10_5();
    Exercise10_6();
    Exercise10_12();
    Exercise10_9();

  return 0;
}
void Exercise10_1()
{

    int num;
    num=RecursiveFactorial(3);
    cout<<"num: "<<num<<endl;
}
int RecursiveFactorial(int n)
{
    if(n<1)
        return 1;
    return n * RecursiveFactorial(n-1);
}
void ReverseRecursively(char a[], int front, int back)
 {
     if(back-front<=0)
         return;
     else
     {
         Swap(a[back],a[front]);
          --back;
          ++front;
          ReverseRecursively(a,front,back);
        }
 }

void Exercise10_2()
{

  // Write a recursive function that reverses a sentence.
  // For example:
  // Sentence greeting = new Sentence("Hello!");
  // prints the string "!olleH".
  // Implement a recursive solution by removing the first character,


    char sentence[13]={"Hello There!"};
    ReverseRecursively(sentence,0,12);
    for(int i=0;i<13;i++)
        cout<<sentence[i];
    cout<<endl;
}
void Exercise10_5()
{
  // Use recursion to implement a function bool find(string s, string t)
  //that tests whether a string t is contained in a string s:
  //bool b = s.find("Mississippi!", "sip");
  // Returns true

  //Hint: If the text starts with the string you want to match,
  //then you are done. If not, consider the sentence that you obtain
  //by removing the first character.
    string state="mississippi";
    string sub = "sip";
    bool s;
    s=substringmatch(sub,state);
    if(s)
        cout<<"found a match"<<endl;
    else
        cout<<"No Match"<<endl;


}
bool substringmatch(string find, string match)
{
   string f= match.substr(0,find.size());
   cout<<""<<f<<endl;
    if(find==f)
       return true;
    if(find.length()>match.length())
       return false;
    match.erase(0,1);
    cout<<"find:"<<match<<endl;
    return substringmatch(find,match);
}
int substringindex(string find, string match,int& index)
{
   string f= match.substr(0,find.size());
   cout<<""<<f<<endl;
    if(find==f)
       return index;
    if(find.length()>=match.length())
       return-1;
    match.erase(0,1);
    index++;
    cout<<"find:"<<match<<endl;
    return (substringindex(find,match,index));
}
void indexIncrement(int& index,int increment)
{
    index=index+increment;
}

void Exercise10_6()
{
  // Use recursion to implement a function int
  // index_of(string s, string t) that returns the starting position
  // of the first substring of the strings that matches t.
  // Return –1 if t is not a substring of s. For example,
  // int n = s.index_of("Mississippi!", "sip"); // Returns 6
  // Hint: This is a bit trickier than Exercise P10.5, because
  //you need to keep track of how far the match is from
  //the beginning of the sentence. Make that value a
  // parameter of a helper function.
    string state="mississippi";
    string sub = "sip";
    int s,r=0;

    s=substringindex(sub,state,r);
        cout<<"Index:"<<s<<endl;


}
void Exercise10_9()
{
    //Using recursion, compute the area of a polygon.
    //Cut off a triangle and use the fact that a triangle
    //with corners (x1,y1), (x2,y2), (x3,y3)
  // has area (x1y2 + x2y3 + x3y1 − y1x2 − y2x3 − y3x1) 2.
    int x[]={1,4,6,3,4,6};
    int y[]={3,4,6,3,4,6};
    int area=0;
    area=polygonArea(x,y,0,6);
    cout<<"area:"<<area<<endl;


}
int polygonArea(int x[],int y[],int b,int end)
{
    //int x1, int y1, int x2, int y2, int y3, int x3)

    if(b<=end-3)
    {
        Triangle a(x[b], y[b], x[b+1], y[b+1], y[b+2], x[b+2]);
        return a.get_area()+polygonArea(x,y,b+2,end);
    }
    else
        return 0;
}

void Exercise10_12()
{

    const int n = 4;
     vector<int> a(n);
     for (int i = 0; i < a.size(); i++)
       {
          a[i] = i;
         print(a);
     }
     while (next_permutation(a))
        print(a);

}
void Exercise10_14()
{
  //Write a program that prints the moves necessary to solve
  //the puzzle for n disks. (Ask the user for n at the beginning
  // of the program.)
  // Print moves in the form Move disk from peg 1 to peg 3
    int discs;
      cout << "Enter the number of discs: " << endl;
      cin >> discs;
      TowersHanoi(discs, "Left", "Middle", "Right");

}
void TowersHanoi(int m, string Left, string Middle, string Right)
{
  if(m == 1)
  {
    cout << "Move disc " << m << " from " << Left << " to " << Right << endl;
  }
  else
  {
    TowersHanoi(m-1, Left,Right,Middle);
    cout << "Move disc " << m << " from " << Left << " to " << Right << endl;
    TowersHanoi(m-1,Middle,Left,Right);
  }
}
template<typename Item_type>
void Swap(Item_type& x, Item_type& y)
{
  Item_type temp = x;
  x = y;
  y = temp;
}
void print(const vector<int>& a)
{
     for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
     cout << "\n";
}
bool next_permutation(vector<int>& a)
{
     for (int i = a.size() - 1; i > 0; i--)
     {
        if (a[i - 1] < a[i])
        {
           int j = a.size() - 1;
           while (a[i - 1] > a[j]) j--;
           Swap(a[i - 1], a[j]);
           reverse(a, i, a.size() - 1);
           return true;
        }
    }
    return false;
}
void reverse(vector<int>& a, int i, int j)
{
  while (i < j)
  {
    Swap(a[i], a[j]);
    i++;
    j--;
  }
}
