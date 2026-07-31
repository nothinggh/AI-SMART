#include <sqlite3.h>
#include <iostream>

int main()
{
    sqlite3 *db = nullptr;
    int rc = sqlite3_open("student.db", &db);
    if (rc != SQLITE_OK)
    {
        std::cerr << sqlite3_errmsg(db) << '\n';
        sqlite3_close(db);
        return 1;
    }
    std::cout << "연결 성공\n";
    // 삽입
    const char *sql = "INSERT INTO student(name, age, email) VALUES (?, ?, ?)";
    sqlite3_stmt *stmt = nullptr;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK)
    {
        std::cerr << sqlite3_errmsg(db) << '\n';
        return 1;
    }
    sqlite3_bind_text(stmt, 1, "김민수", -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 2, 20);
    sqlite3_bind_text(stmt, 3, "minsu@example.com", -1, SQLITE_TRANSIENT);
    sqlite3_step(stmt); // 첫 번째 행 삽입
    sqlite3_reset(stmt);

    sqlite3_bind_text(stmt, 1, "이영희", -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 2, 25);
    sqlite3_bind_text(stmt, 3, "younghee@example.com", -1, SQLITE_TRANSIENT);
    sqlite3_step(stmt); // 두 번째 행 삽입
    sqlite3_reset(stmt);

    sqlite3_bind_text(stmt, 1, "박철수", -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 2, 30);
    sqlite3_bind_text(stmt, 3, "chulsoo@example.com", -1, SQLITE_TRANSIENT);
    
    sqlite3_step(stmt); // 세 번째 행 삽입

    // 쿼리 동작
    if (sqlite3_step(stmt) != SQLITE_DONE)
        std::cerr << sqlite3_errmsg(db) << '\n';

    std::cout <<"삽입 쿼리 성공"<< std::endl;
    // 리소스 반환
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}