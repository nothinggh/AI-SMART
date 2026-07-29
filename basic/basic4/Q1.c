#include <stdio.h>

int main() 
{
    for (int i = 1; i <= 100; i++) 
    {
        
        if (i % 3 == 0 || i % 7 == 0) 
        {
            printf("%d ", i);
        }
    }
    
    printf("\n"); // 줄바꿈
    return 0;
}