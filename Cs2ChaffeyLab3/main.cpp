#include<iostream>
#include <vector>
using namespace std;
void Exercise10_1();//brett(done)
void Exercise10_5();//brett (done)
void Exercise10_6();//brett(done)
void Exercise10_2();//rex
void Exercise10_12();//rex
void Exercise10_9();//elizabeth
void Exercise10_14();//andre
void print(const vector<int>& a);
bool next_permutation(vector<int>& a);
int RecursiveFactorial(int n);
void reverse(vector<int>& a, int i, int j);
void swap(int& x, int& y);
bool substringmatch(string find, string match);
int substringindex(string find, string match, int &index);
void indexIncrement(int& index,int increment);
int main()
{
    system("clear");
    //Exercise10_1();
    //Exercise10_5();
    // Exercise10_6();


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

void Exercise10_2()
{
  // Write a recursive function void reverse() that reverses a sentence.
  // For example:
  // Sentence greeting = new Sentence("Hello!");
  // greeting.reverse();
  // cout << greeting.get_text() << "\n";
  // prints the string "!olleH".
  // Implement a recursive solution by removing the first character,
  // reversing a sentence consisting of the remaining text,
  // and combining the two.
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
}
void swap(int& x, int& y)
{
  int temp = x;
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
           swap(a[i - 1], a[j]);
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
    swap(a[i], a[j]);
    i++;
    j--;
  }
}
