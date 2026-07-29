import sqlite3

conn = sqlite3.connect('/home/smart/work/dbfiles/person.db')
c = conn.cursor()

cursor = conn.cursor()

#student 테이블 생성
sql = """
CREATE TABLE IF NOT EXISTS student (
    id INTEGER PRIMARY KEY,
    name TEXT NOT NULL,
    phone TEXT
);
"""
#sql실행
cursor.execute(sql)
#파일저장
conn.commit()

print("student 테이블 생성 완료")

conn.close()