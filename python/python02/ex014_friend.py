import os
import sqlite3

DB_PATH = "/home/smart/work/dbfiles/frd.db"


def init_db():
    dir_name = os.path.dirname(DB_PATH)
    if dir_name and not os.path.exists(dir_name):
        os.makedirs(dir_name)

    conn = sqlite3.connect(DB_PATH)
    cursor = conn.cursor()
    cursor.execute("""
        CREATE TABLE IF NOT EXISTS frd (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            phone_number TEXT
        )
    """)
    conn.commit()
    conn.close()


def add_friend():
    print("\n--- 친구 등록 ---")
    name = input("이름을 입력하세요: ").strip()
    phone = input("전화번호를 입력하세요: ").strip()

    if not name or not phone:
        print("이름과 전화번호는 필수 입력 사항입니다.")
        return

    conn = sqlite3.connect(DB_PATH)
    cursor = conn.cursor()
    cursor.execute("INSERT INTO frd (name, phone_number) VALUES (?, ?)", (name, phone))
    conn.commit()
    conn.close()
    print(f"{name}님이 등록되었습니다.")


def update_friend():
    print("\n--- 친구 수정 ---")
    friend_id = input("수정할 친구의 ID를 입력하세요: ").strip()

    conn = sqlite3.connect(DB_PATH)
    cursor = conn.cursor()

    cursor.execute("SELECT * FROM frd WHERE id = ?", (friend_id,))
    friend = cursor.fetchone()

    if not friend:
        print("⚠️ 해당 ID의 친구를 찾을 수 없습니다.")
        conn.close()
        return

    print(f"현재 정보 -> 이름: {friend[1]}, 전화번호: {friend[2]}")
    new_name = input("새로운 이름 (엔터 누르면 유지): ").strip()
    new_phone = input("새로운 전화번호 (엔터 누르면 유지): ").strip()

    final_name = new_name if new_name else friend[1]
    final_phone = new_phone if new_phone else friend[2]

    cursor.execute(
        "UPDATE frd SET name = ?, phone_number = ? WHERE id = ?",
        (final_name, final_phone, friend_id),
    )
    conn.commit()
    conn.close()
    print("친구 정보가 수정되었습니다.")


def delete_friend():
    print("\n--- 친구 삭제 ---")
    friend_id = input("삭제할 친구의 ID를 입력하세요: ").strip()

    conn = sqlite3.connect(DB_PATH)
    cursor = conn.cursor()

    cursor.execute("SELECT name FROM frd WHERE id = ?", (friend_id,))
    friend = cursor.fetchone()

    if not friend:
        print("해당 ID의 친구를 찾을 수 없습니다.")
        conn.close()
        return

    cursor.execute("DELETE FROM frd WHERE id = ?", (friend_id,))
    conn.commit()
    conn.close()
    print(f"{friend[0]}님의 정보가 삭제되었습니다.")


def view_all_friends():
    print("\n--- 전체 친구 목록 ---")
    conn = sqlite3.connect(DB_PATH)
    cursor = conn.cursor()
    cursor.execute("SELECT id, name, phone_number FROM frd")
    friends = cursor.fetchall()
    conn.close()

    if not friends:
        print("등록된 친구가 없습니다.")
        return

    print(f"{'ID':<5}{'이름':<10}{'전화번호':<15}")
    print("-" * 30)
    for f in friends:
        print(f"{f[0]:<5}{f[1]:<10}{f[2]:<15}")


def main():
    init_db()

    while True:
        print("\n--------------------")
        print("  친구 관리 프로그램")
        print("--------------------")
        print("1. 친구 등록")
        print("2. 친구 수정")
        print("3. 친구 삭제")
        print("4. 전체 친구 조회")
        print("0. 종료")
        print("--------------------")

        choice = input("원하는 메뉴 번호를 입력하세요: ").strip()

        if choice == "1":
            add_friend()
        elif choice == "2":
            update_friend()
        elif choice == "3":
            delete_friend()
        elif choice == "4":
            view_all_friends()
        elif choice == "0":
            print("프로그램 종료")
            break
        else:
            print("0~4 사이의 숫자를 입력해주세요.")


if __name__ == "__main__":
    main()
