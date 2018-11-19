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

bool isWord(char word1[]){
    int j=0;
    while(word1[j] != '\0'){
            if(!isalpha(word1[j]))
                return false;
            j++;
    }
    return true;
}

bool checkifdupe(char word1[][MAX_WORD_LENGTH+1], char word2[][MAX_WORD_LENGTH+1], int separation[], int n, int& f)
{
    if(n == 0)
        return false;
    for(int i=n-1; i > -1; i--){
        if((fuzzyStrCmp(word1[n], word1[i]) && fuzzyStrCmp(word2[n], word2[i])) || (fuzzyStrCmp(word1[n], word2[i]) && fuzzyStrCmp(word2[n], word1[i]))){
            if(separation[n] > separation[i])
                f = i;
            else
                f = n;
            return true;
        }
    }
    return false;
}

int makeProper(char word1[][MAX_WORD_LENGTH+1], char word2[][MAX_WORD_LENGTH+1], int separation[], int nPatterns)
{
    int n = nPatterns; 
    int i = 0;
    int dupevar;
    if(nPatterns < 0)
        n = 0;
    while(i < n){
        if(separation[i] < 0){
            killrow(word1, word2, separation, n, i);
            continue;
            }
        if(!isWord(word1[i]) || !isWord(word2[i])){
            killrow(word1, word2, separation, n, i);
            continue;
        }
        checkifdupe(word1, word2, separation, i, dupevar);
        if(checkifdupe(word1, word2, separation, i, dupevar)){
            killrow(word1, word2, separation, n, dupevar);
            continue;
        }
        i++;
    }
    
    return n;
}

int find(const char document[], const char a1[MAX_WORD_LENGTH+1])
{
    int n = strlen(document);
    int n1 = strlen(a1);
    int l = 0;
    for(int i=0; i < n; i++){
        if(document[i] == a2[0]){
            while(a1[l] && l+i < n && document[l+i] == a2[l])
                l++;
            }
    if(l == n1){
      k = i;
      break;
    }
  }
  if(l != n2)
    return -1;
  return k;
    }
}

int rate(const char document[], const char word1[][MAX_WORD_LENGTH+1], const char word2[][MAX_WORD_LENGTH+1], const int separation[], int nPatterns)
{
    
}

int main(){
    char a1[20] = "nefarious", a2[20] = "NefAriOus";
    assert(fuzzyStrCmp(a1, a2) == 1);
    strcpy(a2, "lavida");
    assert(fuzzyStrCmp(a1, a2) == 0);
    
    const int TEST1_NRULES = 5;
    char test1w1[TEST1_NRULES][MAX_WORD_LENGTH+1] = {
        "mad", "deranged", "nefarious", "PloT", "have"
    };
    char test1w2[TEST1_NRULES][MAX_WORD_LENGTH+1] = {
        "scientist", "robot", "plot", "nEfArious", "mad"
    };
    int test1dist[TEST1_NRULES] = {1,3,3,4,1};
    int k = makeProper(test1w1, test1w2, test1dist, TEST1_NRULES);
    for(int i = 0; i < k; i++){
        cout << test1w1[i] << " " << test1w2[i] << " " << test1dist[i] << endl;
    }
    cout << "All tests succeeded!" << endl;
}