import sqlite3

try:
    # student.db 열기
    conn = sqlite3.connect("/home/smart/work/dbfiles/test1.db")

    # 커서 생성
    cursor = conn.cursor()

    # 데이터 삽입 SQL
    sql = """
INSERT INTO Order_Items VALUES
(1,1,'Keyboard'),
(2,2,'Mouse'),
(3,3,'Monitor');
    """

    # SQL 실행
    cursor.execute(sql)

    # 저장
    conn.commit()

    print("데이터 삽입 완료")

except sqlite3.Error as e:
    print("데이터 삽입 실패 :", e)

finally:
    # 데이터베이스 닫기
    conn.close()