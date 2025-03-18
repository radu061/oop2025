#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<cstring>
using namespace std;
int main()
{
    char text[105],s[105][105];
    int n=0;
    scanf("%[^\n]s",text);
    char *p=strtok(text," ");
    while(p)
    {
        strcpy(s[n++],p);
        p=strtok(0," ");
    }
    bool ok=0;
    while(!ok)
    {
        ok=1;
        for(int i=0; i<n-1; i++)
        {
            int lg1=strlen(s[i]);
            int lg2=strlen(s[i+1]);
            if(lg1<lg2)
            {
                ok=0;
                swap(s[i],s[i+1]);
            }
            else if(lg1==lg2&&strcmp(s[i],s[i+1])>0)
            {
                ok=0;
                swap(s[i],s[i+1]);
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<s[i]<<'\n';
    return 0;
}
