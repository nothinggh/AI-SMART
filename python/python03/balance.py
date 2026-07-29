class BankAccount:
    def __init__(self, balance=0):
        self.__balance = balance

    def deposit(self, amount):
        if amount > 0:
            self.__balance += amount
            print(f"{amount}원이 입금되었습니다.")
        else:
            print("입금 금액은 0보다 커야 합니다.")

    def withdraw(self, amount):
        if amount > 0 and amount <= self.__balance:
            self.__balance -= amount
            print(f"{amount}원이 출금되었습니다.")
        else:
            print("출금할 수 없습니다.")

    def get_balance(self):
        return self.__balance


if __name__ == "__main__":
    account = BankAccount(100)
    account.deposit(10)
    account.withdraw(100)
    print("현재 잔액:", account.get_balance())
