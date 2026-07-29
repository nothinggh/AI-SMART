#include <stdio.h>

typedef struct
{
   int id;
   char name[50];
   int qty;
} Product;

int main()
{
   FILE *file = fopen("products.txt", "w");
   if (file == NULL) return 1;

   Product p;
   int count;

   printf("입력할 상품 개수: ");
   scanf("%d", &count);

   for (int i = 0; i < count; i++)
   {
       printf("\nID: ");
       scanf("%d", &p.id);
       printf("이름: ");
       scanf("%s", p.name);
       printf("수량: ");
       scanf("%d", &p.qty);

       fprintf(file, "%d %s %d\n", p.id, p.name, p.qty);
   }

   fclose(file);
   printf("\nproducts.txt 파일이 생성되었습니다.\n");
   return 0;
}