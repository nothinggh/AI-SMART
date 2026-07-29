#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>

int main()
{
    sqlite3 *db;
    char *errMsg = NULL;

    if (sqlite3_open("/home/smart/work/dbfiles/person.db", &db) != SQLITE_OK)
    {
        printf("테이블 생성 실패\n ");
        exit(1);
    }

    const char *sql =
        "CREATE TABLE IF NOT EXISTS person ("
        "id INTEGER PRIMARY KEY,"
        "name TEXT NOT NULL,"
        "phone TEXT"
        ");";

    if (sqlite3_exec(db, sql, NULL, NULL, &errMsg) != SQLITE_OK)
    {
        printf("테이블 생성 실패\n");
    }
    else
    {
        printf("테이블 생성 성공\n");
    }

    return 0;
}