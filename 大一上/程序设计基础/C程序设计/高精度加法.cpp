#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sum(char *a, char *b, char *c) {
   int i, j, k;
   int len1 = strlen(a);
   int len2 = strlen(b);
   k = (len1 > len2) ? len1: len2;
   memset(c, '0', k);
   c[k+1] = '\0';
   int carry = 0, temp;
   for(i=len1-1, j=len2-1; i>=0 || j>=0; i--, j--, k--)
   {
      temp = carry;
      if(i>=0) temp += a[i] - '0';
      if(j>=0) temp += b[j] - '0';
      
      if (temp >= 10) {
         c[k] = temp - 10 + '0';
         carry = 1;
      } else {
         c[k] = temp + '0';
         carry = 0;
      }
   }
   c[k] = carry + '0';
}
int main()
{
    char a[200], b[200], c[200], *p;
    scanf("%s",a);
	scanf("%s", b);
    sum(a, b, c);
    p = c;
    if(*p == '0') p++;
    strcpy(a, p);
    printf("%s\n", a);
    return 0;
}
