#include <stdio.h>
#include <stdlib.h>
int main(){
    char cur;
    int am[50], j = 0;
    scanf("%d\n");
    while (cur != '\n'){
        scanf("%c" , &cur);
        if(cur == 'B'){
            j++;
            while(cur == 'B'){
                am[j]++;
                scanf("%c" , &cur);
            }
        }
    }
    printf("%d\n", j);
    for(int i = 0; i < j; i++)
        printf("%d ", am[i]);
}
