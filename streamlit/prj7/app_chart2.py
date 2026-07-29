import streamlit as st
import pandas as pd
import plotly.express as px

st.title('Chart 연습')

data = pd.DataFrame(
{
'날짜':[1,2,3,4,5],
'생산량':[100, 150, 110, 130, 160]
}
)

st.line_chart(data, x='날짜', y='생산량')
st.area_chart(data, x='날짜', y='생산량', color='red')
st.bar_chart(data, x='날짜', y='생산량', color='yellow')

fig=px.bar(
    data,x='날짜',y='생산량',
    color='날짜',
    
)
st.plotly_chart(fig)