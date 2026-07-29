# 도전 실습 1
# 직원 등록 화면에 다음 항목을 추가해 보자
# 이메일
# 전화번호
# 주소
# 직급
# 연봉

# 도전 실습 2
# 다음 화면을 만들어 보자
# 제품 등록 화면
# 제품명
# 제품번호
# 생산일
# 제품 종류
# 사용 가능한 설비
# 품질 등급
# 재고 여부

# 도전 실습 3
# 고객 등록 화면을 만들어 보자
# 입력 항목
# 고객명
# 전화번호
# 주소
# 거래 시작일
# 거래 상태
# 구매 제품
# 거래 등급

import streamlit as st

st.header("직원 등록")

name = st.text_input("이름 입력")
st.write(name)

Email = st.text_input("이메일 입력")
st.write(Email)

num = st.text_input("전화 번호 입력")
st.write(num)

text = st.text_input("주소입력")
st.write(text)

dept = st.selectbox("직급", ["사장", "부사장", "부장", "차장", "과장", "대리", "사원"])
st.write(dept)

salary = st.number_input("연봉", step=100)

st.header("제품 등록")

product = st.text_input("제품명")
st.write(product)

prod_num = st.text_input("제품번호")
st.write(prod_num)

prod_day = st.date_input("생산일")
st.write(prod_day)

dept = st.selectbox("제품종류", ["pipe", "valve", "flange", "nut", "bolt"])
st.write(dept)

skills = st.multiselect(
    "사용 가능한 설비",
    ["골리앗 크래인", "CO2 용접기", "특수(sus) 용접기", "main pump", "portable radder"],
)
st.write(skills)

grade = st.selectbox("품질등급", ["S", "A", "B", "C", "D", "E", "F"])
st.write(grade)

stock = st.radio("재고여부", ["있음", "없음"])
st.write(stock)