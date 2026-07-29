#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct
{
    char name[50];
    int price;
    int quantity;
} Product;

int main()
{
    Product main_arr[MAX_PRODUCTS];
    int count = 0;
    int menu;

    while (1)
    {
        printf("\n===== 재고 관리 프로그램 =====\n");
        printf("1. 제품 추가\n");
        printf("2. 제품 조회\n");
        printf("0. 종료\n");
        printf("메뉴 선택 : ");
        scanf("%d", &menu);

        getchar();

        if (menu == 0)
        {
            printf("프로그램 종료.\n");
            break;
        }

        switch (menu)
        {
        case 1:
            if (count >= MAX_PRODUCTS)
            {
                printf("추가 불가. (최대 %d개)\n", MAX_PRODUCTS);
                break;
            }

            printf("\n--- 제품 추가 ---\n");
            printf("제품 이름: ");
            fgets(main_arr[count].name, sizeof(main_arr[count].name), stdin);
            main_arr[count].name[strcspn(main_arr[count].name, "\n")] = '\0';

            printf("제품 가격: ");
            scanf("%d", &main_arr[count].price);

            printf("제품 수량: ");
            scanf("%d", &main_arr[count].quantity);

            count++;
            printf("추가 완료.\n");
            break;

        case 2:
            printf("\n--- 제품 목록 (총 %d개) ---\n", count);
            if (count == 0)
            {
                printf("제품이 없습니다.\n");
                break;
            }

            for (int i = 0; i < count; i++)
            {
                printf("[%d] 제품명: %s | 가격: %d원 | 수량: %d개\n",
                       i + 1, main_arr[i].name, main_arr[i].price, main_arr[i].quantity);
            }
            break;

        default:
            printf("잘못된 선택입니다.\n");
            break;
        }
    }

    return 0;
}