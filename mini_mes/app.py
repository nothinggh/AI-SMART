import streamlit as st
import sqlite3
import pandas as pd

conn = sqlite3.connect("./sql/mini_mes.db")

query1 = 'select *from item'
query2 = 'select *from lot'
query3 = 'select *from production'
query4 = 'select *from production_material'
query5 = 'select p.production_id,i.item_name from production as p JOIN item i ON p.item_id=i.item_id'

df1 = pd.read_sql(query1, conn)
df2 = pd.read_sql(query2, conn)
df3 = pd.read_sql(query3, conn)
df4 = pd.read_sql(query4, conn)
df5 = pd.read_sql(query5, conn)

st.title("테스트 화면")

st.write("item table")
st.dataframe(df1)
st.write("lot table")
st.dataframe(df2)
st.write("production table")
st.dataframe(df3)
st.write("production_material table")
st.dataframe(df4)\
st.write("part")
st.dataframe(df5)

# production_id에 해당하는 상품의 이름은?
# 상품 id 상품이름
# tesT123
