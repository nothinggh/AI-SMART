#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main()
{
    sqlite3 *person_db;
    char *errMsg = NULL;
    sqlite3_stmt *stmt;

    char *path = "/home/smart/work/dbfiles/person.db";
    if (sqlite3_open(path, &person_db) != SQLITE_OK)
    {
        printf("DB 파일 열기 실패\n");
        exit(1);
    }
    char *query = "select id, name, phone from person";
    if (sqlite3_prepare_v2(person_db, query, -1, &stmt, NULL) != SQLITE_OK)
    {
        printf("데이터 조회 실패\n");
        sqlite3_close(person_db);
        return 1;
    }
    printf("ID\tNAME\t\tPHONE\n");
    printf("-------------------------------------------\n");

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *name = sqlite3_column_text(stmt, 1);
        const unsigned char *phone = sqlite3_column_text(stmt, 2);

        printf("%d\t%s\t%s\n", id, name, phone);
    }

    // 리소스 반환
    sqlite3_finalize(stmt);
    sqlite3_close(person_db);
    return 0;
}