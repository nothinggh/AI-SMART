#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>

void init_menu()
{
   printf("================================\n");
   printf("     직원 근태관리 프로그램     \n");
   printf("================================\n");
   printf("1. 신규 직원 등록\n");
   printf("2. 출근\n");
   printf("3. 퇴근\n");
   printf("4. 결근\n");
   printf("5. 외출\n");
   printf("6. 조퇴\n");
   printf("7. 병가\n");
   printf("8. 휴가\n");
   printf("9. 기타\n");
   printf("10. 특정 직원 상태 조회(출근/퇴근/휴가 등)\n");
   printf("11. 전체 직원 상태 조회\n");
   printf("12. 직원 정보 삭제\n");
   printf("0. 프로그램 종료\n");
   printf("--------------------------------\n");
   printf("메뉴 선택 : ");
}

int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
   for (int i = 0; i < argc; i++)
   {
       printf("%s: %s | ", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

void update_status(sqlite3 *db, int emp_id, const char *status)
{
   char sql[300];
   char *errMsg = NULL;

   sprintf(sql,
           "UPDATE employee "
           "SET status = '%s', updated_at = CURRENT_TIMESTAMP "
           "WHERE emp_id = %d;",
           status, emp_id);

   if (sqlite3_exec(db, sql, NULL, NULL, &errMsg) == SQLITE_OK)
   {
       printf("[%s] 처리가 완료되었습니다.\n", status);
   }
   else
   {
       printf("오류 : %s\n", errMsg != NULL ? errMsg : sqlite3_errmsg(db));
       if (errMsg != NULL)
           sqlite3_free(errMsg);
   }
}

int main()
{
   sqlite3 *db;
   char sql[500];
   char *errMsg = NULL;
   int choice = 0;

   if (sqlite3_open("/home/smart/work/dbfiles/person.db", &db) != SQLITE_OK)
   {
       printf("DB 연결 실패!\n");
       printf("오류 내용 : %s\n", sqlite3_errmsg(db));
       sqlite3_close(db);
       return 1;
   }

   sqlite3_exec(db,
                "CREATE TABLE IF NOT EXISTS employee ("
                "emp_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                "name TEXT, "
                "department TEXT, "
                "status TEXT, "
                "updated_at DATETIME);",
                NULL, NULL, NULL);

   while (1)
   {
       init_menu();
       if (scanf("%d", &choice) != 1)
       {
           printf("잘못된 입력입니다. 숫자를 입력해주세요.\n");
           while (getchar() != '\n')
               ;
           continue;
       }
       printf("\n");

       int emp_id;

       switch (choice)
       {
       case 0:
           printf("프로그램을 종료합니다.\n");
           sqlite3_close(db);
           exit(0);

       case 1:
       {
           char name[20];
           char dept[30];
           printf("[직원 등록]\n");
           printf("직원 이름 입력 : ");
           scanf("%s", name);
           printf("부서 입력 : ");
           scanf("%s", dept);

           sprintf(sql, "INSERT INTO employee (name, department, status, updated_at) "
                        "VALUES ('%s', '%s', NULL, NULL);",
                   name, dept);

           if (sqlite3_exec(db, sql, NULL, NULL, &errMsg) == SQLITE_OK)
           {
               sqlite3_int64 last_id = sqlite3_last_insert_rowid(db);
               printf("직원 등록이 완료되었습니다. (발급된 직원 번호: %lld)\n", last_id);
           }
           else
           {
               printf("오류 : %s\n", errMsg != NULL ? errMsg : sqlite3_errmsg(db));
               if (errMsg != NULL)
                   sqlite3_free(errMsg);
           }
       }
       break;

       case 2:
           printf("[출근]\n직원 번호 입력 : ");
           scanf("%d", &emp_id);
           update_status(db, emp_id, "출근");
           break;

       case 3:
           printf("[퇴근]\n직원 번호 입력 : ");
           scanf("%d", &emp_id);
           update_status(db, emp_id, "퇴근");
           break;

       case 4:
           printf("[결근]\n직원 번호 입력 : ");
           scanf("%d", &emp_id);
           update_status(db, emp_id, "결근");
           break;

       case 5:
           printf("[외출]\n직원 번호 입력 : ");
           scanf("%d", &emp_id);
           update_status(db, emp_id, "외출");
           break;

       case 6:
           printf("[조퇴]\n직원 번호 입력 : ");
           scanf("%d", &emp_id);
           update_status(db, emp_id, "조퇴");
           break;

       case 7:
           printf("[병가]\n직원 번호 입력 : ");
           scanf("%d", &emp_id);
           update_status(db, emp_id, "병가");
           break;

       case 8:
           printf("[휴가]\n직원 번호 입력 : ");
           scanf("%d", &emp_id);
           update_status(db, emp_id, "휴가");
           break;

       case 9:
           printf("[기타]\n직원 번호 입력 : ");
           scanf("%d", &emp_id);
           update_status(db, emp_id, "기타");
           break;

       case 10:
       {
           char search_status[20];
           printf("[특정 직원 상태 조회]\n조회할 상태 입력 (출근/퇴근/결근/외출/조퇴/병가/휴가/기타) : ");
           scanf("%s", search_status);

           sprintf(sql, "SELECT emp_id, name, department, status, datetime(updated_at, 'localtime') AS 변경시간 "
                        "FROM employee WHERE status = '%s';",
                   search_status);
           sqlite3_exec(db, sql, callback, NULL, NULL);
       }
       break;

       case 11:
           printf("[전체 직원 상태 조회]\n");
           sprintf(sql, "SELECT emp_id, name, department, status, datetime(updated_at, 'localtime') AS 변경시간 FROM employee;");
           sqlite3_exec(db, sql, callback, NULL, NULL);
           break;

       case 12:
       {
           printf("[직원 정보 삭제]\n삭제할 직원 번호 입력 : ");
           scanf("%d", &emp_id);

           sprintf(sql, "DELETE FROM employee WHERE emp_id = %d;", emp_id);

           if (sqlite3_exec(db, sql, NULL, NULL, &errMsg) == SQLITE_OK)
           {
               printf("직원 번호 %d번의 정보가 삭제되었습니다.\n", emp_id);
           }
           else
           {
               printf("오류 : %s\n", errMsg != NULL ? errMsg : sqlite3_errmsg(db));
               if (errMsg != NULL)
                   sqlite3_free(errMsg);
           }
       }
       break;

       default:
           printf("잘못된 입력입니다. 0~12 사이의 숫자를 입력해주세요.\n");
           break;
       }
       printf("\n");
   }

   sqlite3_close(db);
   return 0;
}