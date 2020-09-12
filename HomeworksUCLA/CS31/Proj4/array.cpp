#include<iostream>
#include<ctype.h>
#include<string>
#include<cassert>
using namespace std;

int appendToAll(string a[], int n, string value){
  //appends to each element via a loop
  if(n<=0)
    return -1;
  for(int i=0; i<n; i++){
    a[i]+=value;
    cerr << a[i] << endl;
  }
  return n;
}

int lookup(const string a[], int n, string target)
{
  //checks for an element via a loop
  int k=-1;
    for(int i=0; i<n; i++){
      if(a[i] == target){
	k = i;
	break;
      }
    }
  return k;
}

int flip(string a[], int n)
{
  //different cases for odd vs even: swaps i and n-i for i less than the midpoint, essentially
  if(n<=0)
    return -1;
  if( n%2 == 0)
    {
      for(int i=0; i< (n / 2); i++){
	string l = a[i];
	a[i] = a[n-1-i];
	a[n-i-1] = l;
      }
    }
  else
    {
      for(int i=0; i <= (n / 2); i++){
	string l = a[i];
	a[i] = a[n-1-i];
	a[n-i-1] = l;
      }
    }
  for(int j = 0; j < n; j++)
    cerr << a[j] << endl;
  return n;
}

int positionOfMax(const string a[], int n)
{
  //has a running index that is edited every time there's a string that is greater than the current index
  int l = 0;
  if(n <= 0)
    return -1;
  for(int i= n-1; i >= 0; i--){
    if(a[i] >= a[l])
      l = i;
  }
  cerr << l << endl;
  return l;
}


int lookupAny(const string a1[], int n1, const string a2[], int n2)
{
  //two nested loops, checks every element of a2 to see if its equal to our a1, goes backwards to find the least such
  int l = -1;
  for(int i=n1-1; i >= 0; i--)
    {
      for(int j = n2-1; j>=0; j--)
	{
	  if(a1[i] == a2[j])
	    {
	      l = i;
	      break;
	    }
	}
    }
  cerr << l;
  return l;
}

int differ(const string a1[], int n1, const string a2[], int n2)
{
  if(n1 <= 0 || n2 <=0)
    return -1;
  int l = n2;
  if(n1 <= n2)
    l = n1;
  for(int i = 0; i < l; i++){
    if(a1[i] != a2[i]){
      l = i;
      break;
    }
  }
  cerr << l << endl;
  return l;
}

int rotateLeft(string a[], int n, int pos)
{
  // almost literally does what the name is 
  if(pos >= n)
    return -1;
  string l = a[pos];
  for(int i = pos + 1; i < n; i++){
    a[i-1] = a[i];
  }
  a[n-1] = l;
  for(int q=0; q<n; q++)
    cerr << a[q] << endl;
  return pos;
}

int divide(string a[], int n, string divider)
{
  // there's an index i that you up every time you get a hit for something that's less than the divider
  // you switch the hit with a[i] and up the index again to repeat, effectively stacking them on top
  // of each other
  int i = 0;
  for(int j=0; j<n; j++){
    if(a[j] < divider){
      string l = a[i];
      a[i] = a[j];
      a[j] = l;
      i++;
    }
  }
  int l = n;
  while(a[l-1] >= divider){
    l--;
  }
  for(int q=0; q<n; q++)
    cerr << a[q] << endl;
  cerr << l << endl;
  return l;
}

int countRuns(const string a[], int n)
{
  if(n <= 0)
    return -1;
  int i = 1;
  for(int j = 1; j<n; j++){
    if(a[j] != a[j-1])
      i++;
    }
  cerr << i;
  return i;
}

int subsequence(const string a1[], int n1, const string a2[], int n2)
{
  // again, almost literally what it's supposed to do as per the spec:
  // check if everything after an element is equal if the element is equal.
  int l = 0;
  int k;
  if(n2 > n1)
    return -1;
  for(int i=0; i < n1; i++){
    if(a1[i] == a2[0]){
      while(l < n2 && l+i < n1 && a1[l+i] == a2[l])
	l++;
    }
    if(l == n2){
      k = i;
      break;
    }
  }
  if(l != n2)
    return -1;
  return k;
}

int main()
{
  cout << "Hello World!" << endl;
}

	  
