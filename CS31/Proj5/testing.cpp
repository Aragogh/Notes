#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
#include <cassert>
using namespace std;

const int MAX_WORD_LENGTH = 20;

bool fuzzyStrCmp(char a1[], char a2[]){
    if(strlen(a1)!= strlen(a2))
        return false;
    char comp1[MAX_WORD_LENGTH+1], comp2[MAX_WORD_LENGTH+1];
    for(int i=0; i <= strlen(a1); i++){
        comp1[i] = toupper(a1[i]);
        comp2[i] = toupper(a2[i]);
    }
    comp1[strlen(a1)+1] = '\0';
    comp2[strlen(a1)+1] = '\0';
    return !strcmp(comp1, comp2);
}

int main()
{
    char a[MAX_WORD_LENGTH+1];
    strcpy(a, "aaaaaaaaaaaaaaaaaaa");
    assert(fuzzyStrCmp(a, a) == 1);
    cout << "All tests succeeded!"; 
}