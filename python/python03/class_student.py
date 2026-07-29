class Student:
    def __init__(self):
        self.id = 0
        self.name = "학생"
        self.major = "컴퓨터공학"

    def my_print(self):
        print(f"id : {self.id}, name : {self.name},major:{self.major}")


hong = Student()
hong.id = 1
hong.name = "홍길동"  # update
hong.major = "전자공학"  # update
hong.my_print()
