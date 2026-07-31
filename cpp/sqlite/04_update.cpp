#include <sqlite3.h>
#include <iostream>
#include <string>

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
    int age = 0;
    std::string name;
    std::string email;

    std::cout << "ID 입력: ";
    std::cin >> id;

    std::cout << "이름 입력: ";
    std::cin >> name;

    std::cout << "이메일 입력: ";
    std::cin >> email;

    std::cout << "나이 입력: ";
    std::cin >> age;

    const char *sql = "UPDATE student SET name = ?, email = ?, age = ? WHERE id = ?";

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL 문 준비 실패: " << sqlite3_errmsg(db) << '\n';
        sqlite3_close(db);
        return 1;
    }

    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, email.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 3, age);
    sqlite3_bind_int(stmt, 4, id);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        std::cerr << "업데이트 실패: " << sqlite3_errmsg(db) << '\n';
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    std::cout << "업데이트 성공\n";
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}