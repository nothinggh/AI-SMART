#include<stdio.h>

int main()
{
    int menu;

    while (1)
    {
        printf("\n===== 재고 관리 프로그램 =====\n");
        printf("1. 제품 추가\n");
        printf("2. 제품 조회\n");
        printf("3. 제품 수정\n");
        printf("4. 제품 삭제\n");
        printf("0. 종료\n");
        printf("메뉴 선택 : ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 메뉴입니다.\n");
            break;
        }
    }

    return 0;
}