import streamlit as st
import sqlite3
import pandas as pd

from src import queries
from src.ui import setup_page, page_title,show_database_status,DB_PATH, metric_row
# conn = sqlite3.connect("./sql/customer.db")

setup_page("MES 소개")

page_title(
    "Mini MES 교육 앱",
    "MES의 기본 개념과 품목, LOT, 생산실적, 원자재 투입 이력의 관계를 확인합니다.",
    "item, lot, production, production_material",
    "DB 연결 상태와 테이블 구성을 확인한 뒤 왼쪽 메뉴에서 실습 화면으로 이동합니다.",
)

# DB파일 연결여부 상태조회
show_database_status()

st.subheader("Mini MES에서 다루는 현장 질문")
st.markdown(
    """
    - 오늘 어떤 제품을 얼마나 생산했는가?
    - 특정 완제품 LOT는 언제 만들어졌는가?
    - 생산에 어떤 원자재 LOT가 사용되었는가?
    - 문제가 생긴 원자재 LOT를 사용한 완제품 LOT는 무엇인가?
    - 완제품 품질 문제가 발생했을 때 어떤 원자재 LOT를 확인해야 하는가?
    """
)

try:
    counts = queries.table_counts()
    count_map = dict(zip(counts["table_name"], counts["row_count"]))
    metric_row(
        [
            ("품목 수", count_map.get("item", 0)),
            ("LOT 수", count_map.get("lot", 0)),
            ("생산실적 수", count_map.get("production", 0)),
            ("원자재 투입 행 수", count_map.get("production_material", 0)),
        ]
    )
except Exception as exc:
    st.error("데이터베이스 구조를 확인하는 중 오류가 발생했습니다.")
    st.exception(exc)