#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>

int lcs( const char* s,const char* t)  
{ 
    //len保存公共子串的最大长度，index1保存s公共子串的最后一个元素的位置 
    if(s==NULL || t==NULL) return -1;  
    int len1,len2,i,k,len=1,index1=0;  
    int **matrix;  
    len1=strlen(s);  
    len2=strlen(t);  
    if(len1< 1 || len2 < 1) return -1;  
    matrix=malloc(sizeof(int*)*len1);  
    for(i=0;i<len1;i++)  
    {  
        matrix[i]=(int *)malloc(len2*sizeof(int));  
        memset(matrix[i],0,len2*sizeof(int));  
    }  
  
    for(i=0;i<len1;i++)  
    {  
        for(k=0;k<len2;k++)  
        {  
            if(i==0 || k==0)  
            {  
                if(s[i]==t[k]) matrix[i][k]=1;  
                else matrix[i][k]=0;  
            }  
            else  
            {  
                if (s[i] == t[k])  
                {  
                    matrix[i][k] = matrix[i - 1][k - 1] + 1;  
                    if (len < matrix[i][k])  
                    {  
                        len = matrix[i][k];  
                        index1 = i;  
                    }  
                }  
            }  
        }  
    }  
  
    for(i=0;i<len;i++)  
    {  
        printf("%c",*(s+index1-len+1+i));  
    }  
 
    for(i=0;i<len1;i++)  
        free(matrix[i]);  
    free(matrix);  
    return len;  
  
}  


int main(int argc, char *argv[]) {  
    //char a[]="abcgooglecba";  
    //char b[]="cbagoogleABVC";  
    printf("\nlcs = %d\n",lcs(argv[1],argv[2]));  
    return 0;  
}  
