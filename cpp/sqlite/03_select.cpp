#include <sqlite3.h>
#include <iostream>

int main()
{
    sqlite3 *db = nullptr;
    sqlite3_stmt *stmt = nullptr;
    char *error = nullptr;

    // 1. 데이터베이스 열기
    int rc = sqlite3_open("student.db", &db);

    if (rc != SQLITE_OK)
    {
        std::cerr << "데이터베이스 연결 실패: "
                  << sqlite3_errmsg(db) << '\n';

        sqlite3_close(db);
        return 1;
    }

    std::cout << "데이터베이스 연결 성공\n";
    rc = sqlite3_prepare_v2(db,
                            "SELECT id, name, age, email FROM student ORDER BY id",
                            -1, &stmt, nullptr);

    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL 문 준비 실패: " << sqlite3_errmsg(db) << '\n';
        sqlite3_close(db);
        return 1;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *name = sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        bool emailNull = sqlite3_column_type(stmt, 3) == SQLITE_NULL;

        std::cout << id << ", " << reinterpret_cast<const char *>(name) << ", " << age << ", "
                  << (emailNull ? "(없음)" : reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3)))
                  << '\n';
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}