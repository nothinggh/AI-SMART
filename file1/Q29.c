#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char size[20];
    int quantity;
    char date[11];
} Material;

void createMaterial();
void readMaterials();
void updateMaterial();
void deleteMaterial();
int getNextId();

int main() {
    int choice;

    while (1) {
        printf("\n- 배관 자재 관리 시스템 -\n");
        printf("1. 자재 추가 (Create)\n");
        printf("2. 자재 목록 조회 (Read)\n");
        printf("3. 자재 정보 수정 (Update)\n");
        printf("4. 자재 삭제 (Delete)\n");
        printf("5. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: createMaterial(); break;
            case 2: readMaterials(); break;
            case 3: updateMaterial(); break;
            case 4: deleteMaterial(); break;
            case 5: printf("프로그램 종료.\n"); exit(0);
            default: printf("잘못된 선택입니다.\n");
        }
    }
    return 0;
}

int getNextId() {
    FILE *file = fopen("inventory.txt", "r");
    if (file == NULL) return 1;

    Material m;
    int lastId = 0;
    while (fscanf(file, "%d %[^\n]s", &m.id, m.name) != EOF) {
        fscanf(file, "%s %d %s", m.size, &m.quantity, m.date);
        lastId = m.id;
    }
    fclose(file);
    return lastId + 1;
}

void createMaterial() {
    FILE *file = fopen("inventory.txt", "a");
    if (file == NULL) {
        printf("파일을 열수 없습니다.\n");
        return;
    }

    Material m;
    m.id = getNextId();

    printf("자재명: ");
    fgets(m.name, sizeof(m.name), stdin);
    m.name[strcspn(m.name, "\n")] = 0;

    printf("규격(예: 15A, 20A): ");
    scanf("%s", m.size);

    printf("수량: ");
    scanf("%d", &m.quantity);

    printf("입고날짜(YYYY-MM-DD): ");
    scanf("%s", m.date);

    fprintf(file, "%d\n%s\n%s\n%d\n%s\n", m.id, m.name, m.size, m.quantity, m.date);
    fclose(file);

    printf("자재가 추가되었습니다. (ID: %d)\n", m.id);
}

void readMaterials() {
    FILE *file = fopen("inventory.txt", "r");
    if (file == NULL) {
        printf("찾을 수 없습니다.\n");
        return;
    }

    Material m;
    printf("\n==================================================\n");
    printf("ID\t자재명\t\t규격\t수량\t입고날짜\n");
    printf("==================================================\n");

    while (fscanf(file, "%d", &m.id) != EOF) {
        fgetc(file); 
        fgets(m.name, sizeof(m.name), file);
        m.name[strcspn(m.name, "\n")] = 0;
        fscanf(file, "%s %d %s", m.size, &m.quantity, m.date);

        printf("%d\t%-12s\t%s\t%d\t%s\n", m.id, m.name, m.size, m.quantity, m.date);
    }
    printf("==================================================\n");
    fclose(file);
}

void updateMaterial() {
    FILE *file = fopen("inventory.txt", "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    int targetId, found = 0;
    printf("수정할 자재의 ID를 입력하세요: ");
    scanf("%d", &targetId);
    getchar();

    FILE *tempFile = fopen("temp.txt", "w");
    Material m;

    while (fscanf(file, "%d", &m.id) != EOF) {
        fgetc(file);
        fgets(m.name, sizeof(m.name), file);
        m.name[strcspn(m.name, "\n")] = 0;
        fscanf(file, "%s %d %s", m.size, &m.quantity, m.date);

        if (m.id == targetId) {
            found = 1;
            printf("[현재 정보] 자재명: %s, 규격: %s, 수량: %d, 입고날짜: %s\n", m.name, m.size, m.quantity, m.date);
            
            printf("새 자재명: ");
            fgets(m.name, sizeof(m.name), stdin);
            m.name[strcspn(m.name, "\n")] = 0;

            printf("새 규격: ");
            scanf("%s", m.size);

            printf("새 수량: ");
            scanf("%d", &m.quantity);

            printf("새 입고날짜(YYYY-MM-DD): ");
            scanf("%s", m.date);
        }
        fprintf(tempFile, "%d\n%s\n%s\n%d\n%s\n", m.id, m.name, m.size, m.quantity, m.date);
    }

    fclose(file);
    fclose(tempFile);

    remove("inventory.txt");
    rename("temp.txt", "inventory.txt");

    if (found) {
        printf("수정되었습니다.\n");
    } else {
        printf("찾을 수 없습니다.\n");
    }
}

void deleteMaterial() {
    FILE *file = fopen("inventory.txt", "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    int targetId, found = 0;
    printf("삭제할 자재의 ID를 입력하세요: ");
    scanf("%d", &targetId);

    FILE *tempFile = fopen("temp.txt", "w");
    Material m;

    while (fscanf(file, "%d", &m.id) != EOF) {
        fgetc(file);
        fgets(m.name, sizeof(m.name), file);
        m.name[strcspn(m.name, "\n")] = 0;
        fscanf(file, "%s %d %s", m.size, &m.quantity, m.date);

        if (m.id == targetId) {
            found = 1;
            continue;
        }
        fprintf(tempFile, "%d\n%s\n%s\n%d\n%s\n", m.id, m.name, m.size, m.quantity, m.date);
    }

    fclose(file);
    fclose(tempFile);

    remove("inventory.txt");
    rename("temp.txt", "inventory.txt");

    if (found) {
        printf("삭제되었습니다.\n");
    } else {
        printf("찾을 수 없습니다.\n");
    }
}