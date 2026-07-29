import sqlite3

db_path = '절대 경로 지정'

def main():

    while True:
        print('\n-lyk company-')
        print('관리 프로그램')
        print('1.조회')
        print('2.추가')
        print('3.수정')
        print('4.삭제')
        print('5.종료')

        choice=input('번호를 입력하세요:')

        if choice =='1':
            print('아직 미구현')#조회()
        elif choice =='2':
            print('아직 미구현')#추가()
        elif choice =='3':
            print('아직 미구현')#수정()
        elif choice =='4':
            print('아직 미구현')#삭제()
        elif choice =='5':
            print('프로그램 종료.')
            break
        else:
            print('항목이 없습니다. 1~5번 사이의 숫자를 입력하세요.')

if __name__ == '__main__': main()

## dd



