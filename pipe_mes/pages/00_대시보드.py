import pandas as pd  # type: ignore
import streamlit as st

from src.queries import (
    bom_summary_by_ship,
    load_drawing_status,
    load_insp_status,
    load_ydp_status,
)

# PAGE
st.set_page_config(page_title="대시보드", layout="wide")  # page_icon="🚢"

# CSS
st.markdown(
    """
<style>

/* =====================================================
   기본
===================================================== */

.title{
    font-size:34px;
    font-weight:800;
    color:#0f172a;
}


/* =====================================================
   Ship Card
===================================================== */

.ship-card{
    background:#ffffff;
    color:#0f172a;
    border:1px solid #cbd5e1;
    border-radius:18px;
    padding:20px;
    box-shadow: 0 4px 12px rgba(0,0,0,0.08);
}

.total-header-container {
    display: flex;
    justify-content: space-around;
    align-items: center;
    margin-top: 15px;
    text-align: center;
}

.total-item {
    flex: 1;
}

/* =====================================================
   전체 진행률 & 이슈
===================================================== */

.total-progress{
    font-size:48px;
    font-weight:900;
    color:#2563eb;
}

.total-issues{
    font-size:48px;
    font-weight:900;
    color:#dc2626;
}

.total-label {
    font-size: 15px;
    font-weight: 700;
    color: #64748b;
    margin-top: 4px;
}


/* =====================================================
   Process Card
===================================================== */

.process-card{
    color:#0f172a;
    border-radius:15px;
    padding:15px;
    border:1px solid #cbd5e1;
    text-align:center;
}


/* 완료 */

.complete{
    background:#dcfce7;
    border:2px solid #16a34a;
}


/* 진행 */

.running{
    background:#dbeafe;
    border:2px solid #2563eb;
}


/* 이슈 */

.issue{
    background:#fee2e2;
    border:2px solid #dc2626;
}


/* 대기 */

.wait{
    background:#f1f5f9;
    border:2px solid #94a3b8;
}


.value{
    font-size:28px;
    font-weight:900;
}


.rate{
    font-size:22px;
    font-weight:900;
    color:#2563eb;
}


.card-footer{
    display:flex;
    justify-content:space-between;
    align-items:center;
    margin-top:8px;
    font-size:13px;
    font-weight:600;
    color:#475569;
}

.card-footer .issue-ok{
    color:#64748b;
}

.card-footer .issue-bad{
    color:#dc2626;
    font-weight:800;
}



/* =====================================================
   Badge
===================================================== */

.badge{
    display:inline-block;
    padding:7px 12px;
    margin:4px;
    border-radius:20px;
    font-size:13px;
    font-weight:700;
}


.badge-green{
    background:#dcfce7;
    color:#166534;
}


.badge-blue{
    background:#dbeafe;
    color:#1e40af;
}


.badge-red{
    background:#fee2e2;
    color:#991b1b;
}



/* =====================================================
   DARK MODE
===================================================== */


@media (prefers-color-scheme: dark) {


.title{
    color:#f8fafc;
}


.ship-card{
    background:#1e293b;
    color:#f8fafc;
    border:1px solid #475569;
    box-shadow: 0 4px 16px rgba(0,0,0,0.5);
}


.process-card{
    color:#f8fafc;
    border-color:#475569;
}


/* 완료 */

.complete{
    background:#064e3b;
    border-color:#22c55e;
}



/* 진행 */

.running{
    background:#1e3a8a;
    border-color:#3b82f6;
}



/* 이슈 */

.issue{
    background:#7f1d1d;
    border-color:#ef4444;
}



/* 대기 */

.wait{
    background:#334155;
    border-color:#64748b;
}


.rate{
    color:#60a5fa;
}

.card-footer{
    color:#cbd5e1;
}

.card-footer .issue-ok{
    color:#94a3b8;
}

.card-footer .issue-bad{
    color:#f87171;
}

.total-issues {
    color: #f87171;
}

.total-label {
    color: #94a3b8;
}


/* badge */


.badge-green{
    background:#14532d;
    color:#bbf7d0;
}



.badge-blue{
    background:#1e3a8a;
    color:#bfdbfe;
}



.badge-red{
    background:#7f1d1d;
    color:#fecaca;
}


}

</style>
""",
    unsafe_allow_html=True,
)


@st.cache_data(ttl=300)
def _load_bom():
    return bom_summary_by_ship()


@st.cache_data(ttl=300)
def _load_mfp():
    return load_drawing_status()


@st.cache_data(ttl=300)
def _load_insp():
    return load_insp_status()


@st.cache_data(ttl=300)
def _load_ydp():
    return load_ydp_status()


def _safe_load(loader, label):
    try:
        return loader()
    except Exception as e:
        st.error(f"{label} 데이터를 불러오지 못했습니다: {e}")
        return pd.DataFrame()


target_hulls = ["SN101", "SN201", "SN301"]

df_bom = _safe_load(_load_bom, "BOM")
df_mfp = _safe_load(_load_mfp, "MFP(도면)")
df_insp = _safe_load(_load_insp, "INSP(설치)")
df_ydp = _safe_load(_load_ydp, "YDP(YARD)")


if st.button("🔄 새로고침"):
    _load_bom.clear()
    _load_mfp.clear()
    _load_insp.clear()
    _load_ydp.clear()
    st.rerun()


# FUNCTION
def rate(done, total):
    if total == 0:
        return 0
    return int(done / total * 100)


def state_class(percent, issues=0):
    if issues > 0:
        return "issue"
    if percent >= 100:
        return "complete"
    if percent > 0:
        return "running"
    return "wait"


def state_icon(percent, issues=0):
    if issues > 0:
        return "🔴"
    if percent >= 100:
        return "🟢"
    if percent > 0:
        return "🔵"
    return "⚪"


# TITLE
st.title("📌 진행호선 🚢SN101/201/301")
st.divider()

# SHIP
for ship in target_hulls:

    bom = df_bom[df_bom.ship_no == ship] if not df_bom.empty else pd.DataFrame()
    mfp = df_mfp[df_mfp.ship_no == ship] if not df_mfp.empty else pd.DataFrame()
    insp = df_insp[df_insp.ship_no == ship] if not df_insp.empty else pd.DataFrame()
    ydp = df_ydp[df_ydp.ship_no == ship] if not df_ydp.empty else pd.DataFrame()

    rates = []
    total_issues = 0  

    # BOM
    bom_qty = 0
    bom_weight_ton = 0.0
    bom_issues = 0

    if not bom.empty:
        bom_qty = int(bom["total_quantity"].sum())
        bom_weight_ton = round(bom["total_weight"].sum() / 1000, 1)
        if "issues" in bom.columns:
            bom_issues = int(bom["issues"].sum())

    total_issues += bom_issues

    # MFP
    mfp_done = 0
    mfp_total = 0
    mfp_issues = 0

    if not mfp.empty:
        mfp_done = int(mfp["완료건수"].sum())
        mfp_total = int(mfp["도면건수"].sum())

    if "이슈건수" in mfp.columns:
        mfp_issues = int(mfp["이슈건수"].sum())

    total_issues += mfp_issues
    mfp_rate = rate(mfp_done, mfp_total)
    rates.append(mfp_rate)

    # INSP
    insp_done = 0
    insp_total = 0
    insp_issues = 0

    if not insp.empty:
        insp_done = int(insp["completed"].sum())
        insp_total = int(insp["cnt"].sum())
        if "issues" in insp.columns:
            insp_issues = int(insp["issues"].sum())
            total_issues += insp_issues

    insp_rate = rate(insp_done, insp_total)
    rates.append(insp_rate)

    # YDP
    ydp_done = 0
    ydp_total = 0
    ydp_issues = 0

    if not ydp.empty:
        ydp_total = int(ydp["total_cnt"].sum())

        if "issues" in ydp.columns:
            ydp_issues = int(ydp["issues"].sum())
            total_issues += ydp_issues

        if "completed_cnt" in ydp.columns:
            ydp_done = int(ydp["completed_cnt"].sum())
        elif "completed" in ydp.columns:
            ydp_done = int(ydp["completed"].sum())
        else:
            ydp_done = ydp_total - ydp_issues

    ydp_rate = rate(ydp_done, ydp_total)
    rates.append(ydp_rate)

    total_rate = int(sum(rates) / len(rates)) if rates else 0

    # HEADER
    st.markdown(
        f"""
<div class="ship-card">
    <h2>🚢 {ship}</h2>
    <div class="total-header-container">
        <div class="total-item">
            <div class="total-progress">{total_rate}%</div>
            <div class="total-label">전체 진행률</div>
        </div>
        <div style="border-left: 1px solid #cbd5e1; height: 50px;"></div>
        <div class="total-item">
            <div class="total-issues">{total_issues:,}</div>
            <div class="total-label">전체 이슈 건수</div>
        </div>
    </div>
</div>
""",
        unsafe_allow_html=True,
    )

    st.write("")

    cols = st.columns(4)

    # 카드
    def footer_html(label, issues):
        cls = "issue-bad" if issues > 0 else "issue-ok"
        mark = "⚠️ " if issues > 0 else ""
        return (
            f'<div class="card-footer">'
            f"<span>{label}</span>"
            f'<span class="{cls}">{mark}이슈 {issues}건</span>'
            f"</div>"
        )


    # BOM 
    with cols[0]:
        qty = 0
        weight_ton = 0.0
        bom_issues = 0

        if not bom.empty:
            qty = int(bom["total_quantity"].sum())
            weight_ton = round(bom["total_weight"].sum() / 1000, 1)
            if "issues" in bom.columns:
                bom_issues = int(bom["issues"].sum())

        total_issues += bom_issues

        st.markdown(
            f"""
<div class="process-card {state_class(100, bom_issues)}">
    <h3>📦 BOM</h3>
    <div class="value">{bom_qty:,} EA</div>
    <div class="rate">{bom_weight_ton:,.1f} ton</div>
    {footer_html("자재 주문", bom_issues)}
</div>
""",
            unsafe_allow_html=True,
        )


    # MFP
    with cols[1]:
        st.markdown(
            f"""
<div class="process-card {state_class(mfp_rate, mfp_issues)}">
    <h3>🔧 MFP</h3>
    <div class="value">{mfp_done}/{mfp_total}</div>
    <div class="rate">진행률 {mfp_rate}%</div>
    {footer_html("제작 공정", mfp_issues)}
</div>
""",
            unsafe_allow_html=True,
        )

    # INSP
    with cols[2]:
        st.markdown(
            f"""
<div class="process-card {state_class(insp_rate, insp_issues)}">
    <h3>🔩 INSP</h3>
    <div class="value">{insp_done}/{insp_total}</div>
    <div class="rate">진행률 {insp_rate}%</div>
    {footer_html("설치 공정", insp_issues)}
</div>
""",
            unsafe_allow_html=True,
        )

    # YDP
    with cols[3]:
        st.markdown(
            f"""
<div class="process-card {state_class(ydp_rate, ydp_issues)}">
    <h3>🏗 YDP</h3>
    <div class="value">{ydp_done}/{ydp_total}</div>
    <div class="rate">진행률 {ydp_rate}%</div>
    {footer_html("YARD 공정", ydp_issues)}
</div>
""",
            unsafe_allow_html=True,
        )

    # BLOCK
    st.markdown("### 🧩 BLOCK 현황")

    if not ydp.empty:
        html = ""

        for _, row in ydp.iterrows():
            total = row["total_cnt"]

            if "completed_cnt" in ydp.columns:
                done = row["completed_cnt"]
            elif "completed" in ydp.columns:
                done = row["completed"]
            else:
                done = total - row["issues"]

            p = rate(done, total)
            issue = int(row.get("issues", 0))

            if issue > 0:
                badge = "badge-red"
            elif p >= 100:
                badge = "badge-green"
            else:
                badge = "badge-blue"

            html += f"""
<span class="badge {badge}">
{state_icon(p, issue)}
{row['block_no']}
{p}%
"""

            if issue > 0:
                html += f" ⚠️{issue}"

            html += """
</span>
"""

        st.markdown(html, unsafe_allow_html=True)

    st.divider()
