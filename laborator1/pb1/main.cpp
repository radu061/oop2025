#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<cstring>
using namespace std;
int main()
{
    int s = 0;
    FILE *f=fopen("in.txt","r");
    char nr[105];
    while (fgets(nr, 105, f))
    {
        int nrc=0,n=strlen(nr)-1;
        nr[n] = 0;
        for (int i = 0; nr[i]; i++)
            nrc = nrc * 10+nr[i]-'0';
        s += nrc;
    }
    fclose(f);
    printf("%d", s);
    return 0;
}
