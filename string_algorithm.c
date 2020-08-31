#include <stdio.h>
#include <string.h>

// 反转字符串
void reverse(char *s, int begin, int end){
    char temp;
    while(end > begin){
        temp = s[begin];
        s[begin] = s[end];
        s[end] = temp;
        begin ++;
        end --;
    }
}


// 暴力匹配字符串，p在s中的位置
int violentMatch(char* s, char* p)
{
    int sLen = strlen(s);
    int pLen = strlen(p);
 
    int i = 0;
    int j = 0;
    while (i < sLen && j < pLen)
    {
        if (s[i] == p[j])
        {
            //①如果当前字符匹配成功（即S[i] == P[j]），则i++，j++    
            i++;
            j++;
        }
        else
        {
            //②如果失配（即S[i]! = P[j]），令i = i - (j - 1)，j = 0    
            i = i - j + 1;
            j = 0;
        }
    }
    //匹配成功，返回模式串p在文本串s中的位置，否则返回-1
    if (j == pLen)
        return i - j;
    else
        return -1;
}



// 无重复字符的最长子串       char *s = "wuhaiweiiw";
int lengthOfLongestSubstring(char * s)
{
int i;                  /*    计数器    */
int count = 0;          /* 子串当前长度 */
int max = 0;            /* 子串最大长度 */
int start = 0;          /* 子串起始位置 */
int index[128] = {0};   /* 记录每个字符先后出现位置 */
for(i = 0; s[i] != '\0'; i++){
    // printf("%c\n",s[i] );
    // printf("%d\n", index[s[i]]);
    if(index[s[i]] > start){ /* 若为真，则说明字符s[i]在之前重复出现过 */
        count = i - start; /* 记录此时子串的长度 */
        if(count > max) /* 若当前子串大于先前记录的最大字串长度，则更新max */
            max = count;
        start = index[s[i]]; /* 更新新子串的起始位置 */
    }
    index[s[i]] = i + 1; /* 记录字符s[i]在整个字符串中出现的位置 */
}
  count = i - start; /* 计算最后一个子串的长度 */
  return count > max ? count : max;
}



int main () {

    
    // 字符串反转，单词反转
    // 先将字符串整个进行反转，再将单个单词进行反转
    // char s[100];
    // // 从终端接收输入字符串
    // gets(s);
    // reverse(s,0,strlen(s) - 1);
    // // 打印字符串
    // puts(s);

    // int a = 0;
    // int b = 0;
    // int i = 0;
    // while(i < strlen(s)){
    //     while(i < strlen(s) && s[i] == ' '){
    //         i ++;
    //     }
    //     a = i;
    //     while(i < strlen(s) && s[i] != ' '){
    //         i ++;
    //     }
    //     b = i - 1;
    //     reverse(s, a, b);
    // }
    // printf("%s\n", s);



    // 暴力匹配字符串，p在s中的位置
    // char *s = "I ama dagdagdaga dog";
    // char *p = "dog";
    // int index = violentMatch(s,p);
    // printf("%d\n", index);



    // 无重复字符的最长子串
    // char *s = "wuhaiweiiw";
    // int length = lengthOfLongestSubstring(s);
    // printf("%d\n",length );



    return 0;
}
