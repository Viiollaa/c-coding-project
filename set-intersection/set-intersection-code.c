#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    char s[150],k[150];
    int n;

    scanf("%s",s);
    scanf("%d",&n);
    scanf("%s",k);

    int lenk = strlen(k);
    int part = lenk/n;

    bool target[26] = {false};
    for (int i = 0;s[i]!='\0';i++){
        target[s[i]-'A'] = true;
    }
    bool data[part][26];
    memset(data,false,sizeof(data));

    for(int i = 0;i<part;i++){
        for(int j = 0;j<n;j++){
            char curr = k[i*n+j];
            data[i][curr -'A']=true;
        }
    }

    int count = 0;
    for (int i = 0; i<part;i++){
        for (int j =i+1;j<part;j++){
            bool match = true;
            for(int o = 0;o<26;o++){
                bool inter = (data[i][o] && data[j][o]);

                if (inter != target[o]){
                    match = false;
                    break;
                }
            }
            if (match){
                count++;
            }
        }
    }
    printf("%d\n",count);
    return 0;
}
