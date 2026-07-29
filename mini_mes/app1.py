import streamlit as st
import sqlite3
import pandas as pd

conn = sqlite3.connect("./sql/customer.db")
name = st.text_input("고객명")
phone = st.text_input("전화번호")

if st.button("등록"):

    conn.execute(
        """
        INSERT INTO customers
        (customer_name,phone)
        VALUES (?,?)
        """,
        (name, phone),
    )
    conn.commit()

query1 = 'SELECT * FROM customers ORDER BY customer_id'
df = pd.read_sql(query1, conn)

st.dataframe(df)
conn.close()
