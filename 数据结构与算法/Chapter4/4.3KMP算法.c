// KMP算法
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLEN 255
typedef struct{
    char ch[MAXLEN + 1];
    int length;
}SString;

void InitString(SString *S){
    // 初始化空串S
    S->ch[0] = '\0';
    S->length = 0;
}
SString CreateString(char* str){
    SString s;
    int len = strlen(str);
    s.length = len;

    if (len <= MAXLEN){
        strcpy(s.ch + 1, str);
    }
    else{
    printf("字符串太长");
    }
    return s;
}
void get_next(SString T, int next[]){
    int i = 1;
    int j = 0;
    next[1] = 0;
    while(i < T.length){
        if(j == 0 || T.ch[i] == T.ch[j]){
            ++i;
            ++j;
            next[i] = j;
        }else{
            j = next[j];
        }
    }
}

// KMP算法
int Index_KMP(SString S,SString T,int pos){
    // 初始条件：串S和T存在，T是非空串，1<=pos<=StrLength(S)
    // 返回值：若主串S中存在和串T值相同的子串，则返回它在主串S中第pos个字符之后第一次出现的位置，否则返回0
    int i = pos; // i用于主串S中当前位置下标，若pos不为1，则从pos位置开始匹配
    int j = 1; // j用于子串T中当前位置下标值
    int next[255];
    get_next(T, next);

    while(i <= S.length && j <= T.length){
        if(j == 0 || S.ch[i] == T.ch[j]){ // 两字母相等则继续
            ++i;
            ++j;
        }else{ // 指针后退重新开始匹配
            j = next[j];
        }
    }
    if(j > T.length){
        return i - T.length;
    }else{
        return 0;
    }
}


int main(){
    char* str1 = "ababcabcacbab";
    SString s = CreateString(str1);
    char* str2 = "abcac";
    SString t = CreateString(str2);
    int pos = Index_KMP(s, t, 1);
    printf("%d", pos);
}

