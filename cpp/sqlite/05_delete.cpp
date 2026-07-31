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

// #################################################################

    int id = 0;

    std::cout << "ID 입력: ";
    std::cin >> id;

    char sql[256];
    std::snprintf(sql, sizeof(sql),
                  "DELETE FROM student WHERE id = %d",
                  id);

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL 문 준비 실패: " << sqlite3_errmsg(db) << '\n';
        sqlite3_close(db);
        return 1;
    }

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        std::cerr << "삭제 실패: " << sqlite3_errmsg(db) << '\n';
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    std::cout << "삭제 성공\n";
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}