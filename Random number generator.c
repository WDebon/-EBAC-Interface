#include <stdio.h> 
#include <string.h> 

int main()
{
    int max; int min;
    
    int res;
    char ans[1];
    char ans2[1] = "N";
    int result = 1;

    printf("\n--Random number generator--\n"); printf("~by hdyly\n");

    while(result == 1)
    {
        printf("\nMin:"); scanf("%d", &min);
        printf("\n\nMax:"); scanf("%d", &max);
        res = (rand() % (min - max + 1)) + min;
        printf("\n--------------------\n\n-Result:[#");
        printf("%d", res); printf("]"); 
        printf("\n\nExit?\n"); printf("Y/N:"); scanf("%s", ans);
        result = strcmp(ans2, ans);
        printf("____________");
    }
    printf("\n");
    system("exit");
}
