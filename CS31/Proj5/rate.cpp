#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cctype>
#include<cassert>
using namespace std;

const int MAX_WORD_LENGTH = 20;

void killrow(char a1[][MAX_WORD_LENGTH+1], char a2[][MAX_WORD_LENGTH+1], int b[], int& n, int row){
    if(row == n){
        n--;
        return;
    }
    for(int i = row; i < n-1; i++){
        strcpy(a1[i], a1[i+1]);
        strcpy(a2[i], a2[i+1]);
        b[i] = b[i+1];
    }
    n--;
}

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

int makeProper(char word1[][MAX_WORD_LENGTH+1], char word2[][MAX_WORD_LENGTH+1], int separation[], int nPatterns)
{
    int n = nPatterns; 
    int i = 0;
    if(nPatterns < 0)
        n = 0;
    while(i < n){
        if(separation[i] < 0){
            killrow(word1, word2, separation, n, i);
            continue;
            }
        i++;
    }       
    return n-1;
}

int main(){
    char a1[20] = "nefarious", a2[20] = "NefAriOus";
    assert(fuzzyStrCmp(a1, a2) == 1);
    strcpy(a2, "lavida");
    assert(fuzzyStrCmp(a1, a2) == 0);
    
    int TEST1_NRULES = 4;
    char test1w1[TEST1_NRULES][MAX_WORD_LENGTH+1] = {
        "mad", "deranged", "nefarious", "have"
    };
    char test1w2[TEST1_NRULES][MAX_WORD_LENGTH+1] = {
        "scientist", "robot", "plot", "mad"
    };
    int test1dist[TEST1_NRULES] = {-1,-3,0,1};
    makeProper(test1w1, test1w2, test1dist, 4);
    for(int i = 0; i <= makeProper(test1w1, test1w2, test1dist, TEST1_NRULES); i++){
        cout << test1w1[i] << " " << test1w2[i] << " " << test1dist[i] << endl;
    }
    cout << "All tests succeeded!" << endl;
}