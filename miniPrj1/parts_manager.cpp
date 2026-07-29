#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // 출력 정렬(setw)을 위한 헤더

// 구조체 정의 (C++에서는 typedef 없이 구조체 이름만으로 타입 사용 가능)
struct Product {
    int id;
    std::string name; // char 배열 대신 std::string 사용
    int quantity;
    int price;
};

// 메뉴 출력 함수
void printMenu() {
    std::cout << "\n==== 자동차 부품 재고 관리 프로그램 ====\n";
    std::cout << "1. 전체 재고 조회\n";
    std::cout << "2. 부품 검색\n";
    std::cout << "3. 입고 처리\n";
    std::cout << "4. 출고 처리\n";
    std::cout << "5. 신규 부품 등록\n";
    std::cout << "0. 종료\n";
    std::cout << "메뉴 선택: ";
}

// 단일 부품 출력 함수
void printProduct(const Product& p) {
    // std::left와 std::setw를 이용해 탭(\t) 없이도 깔끔하게 열을 맞춥니다.
    std::cout << p.id << "\t" 
              << std::left << std::setw(15) << p.name << "\t" 
              << p.quantity << "개\t" 
              << p.price << "원\n";
}

// 전체 재고 조회 함수 (vector를 참조로 받아 복사 비용을 줄임)
void printAll(const std::vector<Product>& products) {
    std::cout << "\nID\t부품명\t\t수량\t가격\n";
    std::cout << "----------------------------------------\n";

    // C++의 범위 기반 for 루프 (Range-based for loop) 사용
    for (const auto& p : products) {
        printProduct(p);
    }
}

// 부품 인덱스 찾기 함수
int findProductIndex(const std::vector<Product>& products, int id) {
    for (size_t i = 0; i < products.size(); i++) {
        if (products[i].id == id) {
            return i; // 인덱스 반환
        }
    }
    return -1;
}

// 부품 검색 함수
void searchProduct(const std::vector<Product>& products) {
    int id;
    std::cout << "검색할 부품 ID 입력: ";
    std::cin >> id;

    int index = findProductIndex(products, id);

    if (index == -1) {
        std::cout << "해당 부품을 찾을 수 없습니다.\n";
    } else {
        std::cout << "\nID\t부품명\t\t수량\t가격\n";
        std::cout << "----------------------------------------\n";
        printProduct(products[index]);
    }
}

// 입고 처리 함수 (수정이 일어나므로 const를 붙이지 않음)
void stockIn(std::vector<Product>& products) {
    int id, amount;

    std::cout << "입고할 부품 ID 입력: ";
    std::cin >> id;

    int index = findProductIndex(products, id);

    if (index == -1) {
        std::cout << "해당 부품을 찾을 수 없습니다.\n";
        return;
    }

    std::cout << "입고 수량 입력: ";
    std::cin >> amount;

    if (amount <= 0) {
        std::cout << "입고 수량은 1개 이상이어야 합니다.\n";
        return;
    }

    products[index].quantity += amount;

    std::cout << "입고 처리가 완료되었습니다.\n";
    std::cout << "현재 재고: " << products[index].quantity << "개\n";
}

// 출고 처리 함수
void stockOut(std::vector<Product>& products) {
    int id, amount;

    std::cout << "출고할 부품 ID 입력: ";
    std::cin >> id;

    int index = findProductIndex(products, id);

    if (index == -1) {
        std::cout << "해당 부품을 찾을 수 없습니다.\n";
        return;
    }

    std::cout << "출고 수량 입력: ";
    std::cin >> amount;

    if (amount <= 0) {
        std::cout << "출고 수량은 1개 이상이어야 합니다.\n";
        return;
    }

    if (products[index].quantity < amount) {
        std::cout << "재고가 부족합니다.\n";
        std::cout << "현재 재고: " << products[index].quantity << "개\n";
        return;
    }

    products[index].quantity -= amount;

    std::cout << "출고 처리가 완료되었습니다.\n";
    std::cout << "현재 재고: " << products[index].quantity << "개\n";
}

// 신규 부품 등록 함수 (포인터 대신 C++ 참조 & 사용)
void addProduct(std::vector<Product>& products) {
    Product p;

    std::cout << "신규 부품 ID 입력: ";
    std::cin >> p.id;

    if (findProductIndex(products, p.id) != -1) {
        std::cout << "이미 존재하는 ID입니다.\n";
        return;
    }

    std::cout << "부품명 입력: ";
    std::cin >> p.name; // std::string이라 크기 제한 걱정 없이 입력 가능

    std::cout << "재고 수량 입력: ";
    std::cin >> p.quantity;

    std::cout << "가격 입력: ";
    std::cin >> p.price;

    // 벡터의 맨 뒤에 새 부품 추가 (배열 크기 한계인 MAX_ITEMS 개념이 필요 없어짐)
    products.push_back(p);

    std::cout << "신규 부품이 등록되었습니다.\n";
}

int main() {
    // std::vector를 사용하여 동적 배열 형태로 초기화
    std::vector<Product> products = {
        {1001, "타이어", 20, 120000},
        {1002, "와이퍼", 35, 15000},
        {1003, "엔진오일", 50, 35000},
        {1004, "배터리", 12, 90000},
        {1005, "브레이크패드", 25, 60000},
        {1006, "에어컨필터", 40, 18000},
        {1007, "전조등", 18, 45000}
    };

    int choice;

    while (true) {
        printMenu();
        std::cin >> choice;

        if (choice == 1) {
            printAll(products);
        } 
        else if (choice == 2) {
            searchProduct(products);
        } 
        else if (choice == 3) {
            stockIn(products);
        } 
        else if (choice == 4) {
            stockOut(products);
        } 
        else if (choice == 5) {
            addProduct(products);
        } 
        else if (choice == 0) {
            std::cout << "프로그램을 종료합니다.\n";
            break;
        } 
        else {
            std::cout << "잘못된 메뉴입니다.\n";
        }
    }

    return 0;
}