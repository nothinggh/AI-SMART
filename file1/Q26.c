#include <stdio.h>

typedef struct
{
    int id;
    char name[50];
    int qty;
    int price;
    char lot[30];
} Product;

int main()
{
    FILE *fp;
    Product p;

    printf("제품번호 입력 : ");
    scanf("%d", &p.id);
    printf("제품명 입력 : ");
    scanf("%s", p.name);
    printf("수량 입력 : ");
    scanf("%d", &p.qty);
    printf("가격 입력 : ");
    scanf("%d", &p.price);
    printf("LOT 입력 : ");
    scanf("%s", p.lot);

    fp = fopen("products.txt", "a");

    fprintf(fp, "%d,%s,%d,%d,%s", p.id, p.name, p.qty, p.price, p.lot);
    fclose(fp);

    printf("완료\n");
    return 0;
}