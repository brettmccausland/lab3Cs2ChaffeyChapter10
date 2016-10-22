#include<iostream>
#include <vector>
using namespace std;
void Exercise10_1();
void Exercise10_2();
void Exercise10_5();
void Exercise10_6();
void Exercise10_9();
void Exercise10_12();
void Exercise10_14();
void print(const vector<int>& a);
bool next_permutation(vector<int>& a);
void reverse(vector<int>& a, int i, int j);
void swap(int& x, int& y);
int main()
{
  system("clear");



  return 0;
}
void Exercise10_1()
{
  //If a string has n letters, then the number of
  //permutations is given by the factorial function:
  //n! = 1 × 2 × 3 × ... × n
￼   //Programming Exercises 439 For example, 3! = 1 × 2 × 3 = 6 and
//  there are six permutations of the three-character
  //string "eat". Implement a recursive factorial function,
  // using the definitions n! = (n − 1)! × n and 0! = 1
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
  //bool b = s.find("Mississippi!", "sip"); // Returns true
  //Hint: If the text starts with the string you want to match,
  //then you are done. If not, consider the sentence that you obtain
  //by removing the first character.

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
     for (int i = 0; i < a.size(); i++) a[i] = i;
     print(a);
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
