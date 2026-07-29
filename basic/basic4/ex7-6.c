#include <stdio.h>

void fruit(int count){
    printf("apple\n");
    if(count ==3) return;
    fruit(count +1);
    printf("jam\n");
}

int main()
{
    fruit(1);
    return 0;
}