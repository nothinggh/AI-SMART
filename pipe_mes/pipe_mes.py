import streamlit as st
import sqlite3
import pandas as pd

from src import queries
from src.ui import setup_page, page_title,show_database_status,DB_PATH, metric_row
# conn = sqlite3.connect("./sql/customer.db")

setup_page("pipe_mes")

page_title("배관 관리시스템(PWPMS)",
           "Piping Work Process Management System",
           "BOM / MFP",)

# DB파일 연결여부 상태조회
show_database_status()

st.subheader("개발 목적")
st.markdown(
    """
    - 자재 및 설치공정 실시간 관리 
    - 공장별 공정 추적 관리 및 현장 작업자 역량 체크
    - 작업 시간 및 불량률 최소화
    - 불량률 최소화 직원 휴가 및 보너스 지급
    - 직원 작업 능률 향상과 오작 및 불량률 0% 달성 실현 추구
    """
)
