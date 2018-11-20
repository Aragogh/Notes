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
    if(word1[0]=='\0')
        return false;
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

int documentWords(const char document[], char a[][MAX_WORD_LENGTH+1])
{
    int i = 0;
    int l = 0;
    while(document[l]){
        while(document[l] == ' ')
            l++;
        if(document[l] != ' '){
            int k = 0;
            while(document[l] && document[l] != ' '){
                a[i][k] = document[l];
                l++;
                k++;
                if(document[l] == ' '){
                    a[i][k] = '\0';
                    i++;
                }
            }
        }
    }
    for(int j = 0; j <= i; j++){
        int g = 0;
        int z = 0;
        char b[MAX_WORD_LENGTH+1] = ""; 
        while(a[j][g]){
            while(isalpha(a[j][g])){
                b[z] = a[j][g];
                z++;
                g++;
            }
            g++;
        }
        strcpy(a[j], b);
    }
    int h = 0;
    while( h <= i ){
        if(!strcmp(a[h], "")){
            for(int w = h; w<= i; w++)
                strcpy(a[w], a[w+1]);
            i--;
            continue;
        }
        h++;    
    }
    return i;
}

int ratePattern(const char document[], const char a1[MAX_WORD_LENGTH+1], const char a2[MAX_WORD_LENGTH+1], const int separation)
{
    char b[250][MAX_WORD_LENGTH+1]; 
    char c[MAX_WORD_LENGTH+1] = "";
    char d[MAX_WORD_LENGTH+1] = "";
    for(int j = 0; j < 250; j++){
        for(int k = 0; k < MAX_WORD_LENGTH+1; k++){
            b[j][k] = '\0';
        }
    }
    strcpy(c, a1);
    strcpy(d, a2);
    documentWords(document, b);
    int k = documentWords(document, b);
    for(int i = 0; i<=k ; i++){
        if(fuzzyStrCmp(b[i], c)){
            for(int g = 0; g <= separation + 1; g++){
                if(i + g <= k && fuzzyStrCmp(b[i + g], d)){
                   return 1;
                }
                if(i - g >= 0 && fuzzyStrCmp(b[i - g], d)){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int rate(const char document[], const char word1[][MAX_WORD_LENGTH+1], const char word2[][MAX_WORD_LENGTH+1], const int separation[], int nPatterns)
{
    int k = 0;
    for(int i = 0; i < nPatterns; i++)
        k += ratePattern(document, word1[i], word2[i], separation[i]);
    return k;
}

int main(){
    char a5[250] = "The k'illiam william illiam the illest";
    assert(ratePattern(a5, "Killiam", "The", 0) == 1);
    assert(ratePattern(a5, "Illest", "The", 0) == 1);
    assert(ratePattern(a5, "The", "Illest", 5) == 1);
    assert(ratePattern(a5, "Brosephine", "The", 0) == 0);
    assert(ratePattern(a5, "The", "Killiam", 0) == 1);
    assert(ratePattern(a5, "The", "illiam", 2) == 1);
    char b7[250] = "Friends friend's frenemiss-johansson aaaaaaaaaaaaaaaaaaa is";
    assert(ratePattern("My friend's friends' friends killed Bronson", "friends", "Bronson", 3) == 1);
    assert(ratePattern(b7, "is", "aaaaaaaaaaaaaaaaaaa", 0) == 1);
    assert(ratePattern(b7, "aaaaaaaaaaaaaaaaaaa", "is", 0) == 1);
    assert(ratePattern("This project took me over 24 32 ---- hours", "over", "hours", 0) == 1);
    assert(ratePattern("This project took me ov33er hours", "over", "hours", 0) == 1);
    const int TEST1_NRULES = 4;
    char test1w1[TEST1_NRULES][MAX_WORD_LENGTH+1] = {
        "mad",       "deranged", "nefarious", "have"
    };
    char test1w2[TEST1_NRULES][MAX_WORD_LENGTH+1] = {
        "scientist", "robot",    "plot",      "mad"
    };
    int test1dist[TEST1_NRULES] = {
        1,           3,          0,           12
    };
    assert(rate("The mad UCLA scientist unleashed a deranged evil giant robot.",
	test1w1, test1w2, test1dist, TEST1_NRULES) == 2);
    assert(rate("The mad UCLA scientist unleashed      have  a deranged robot.",
	test1w1, test1w2, test1dist, TEST1_NRULES) == 3);
    assert(rate("**** 2018 ****",
	test1w1, test1w2, test1dist, TEST1_NRULES) == 0);
    assert(rate("  That plot: NEFARIOUS!",
	test1w1, test1w2, test1dist, TEST1_NRULES) == 1);
    assert(rate("deranged deranged robot deranged robot robot",
	test1w1, test1w2, test1dist, TEST1_NRULES) == 1);
    assert(rate("That scientist said two mad scientists suffer from deranged-robot fever.",
	test1w1, test1w2, test1dist, TEST1_NRULES) == 0);
    cout << "All tests succeeded!" << endl;
}