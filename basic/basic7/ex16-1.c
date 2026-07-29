#include <stdio.h>
#include<stdlib.h> // (standard Library)
// 메모리 할당, 프로세스 제어, 자료형 변환, 난수 생성

int main()
{
    int *pi; //변수는 pi

    pi=(int *)malloc(sizeof(int));
    //heap 메모리에 4bytes 정수 공간이 만들어짐.
   *pi = 10;

    printf("%d\n", *pi);
    
    free(pi);

return 0;
}