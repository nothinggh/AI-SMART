scores = []
for i in range(5):
    score = float(input(f'학생 {i+1}의 성적을 입력하세요: '))
    scores.append(score)

avg = sum(scores) / len(scores)
max_score = max(scores)
min_score = min(scores)
above_80 = sum(1 for score in scores if score >= 80)

print('평균:', avg)
print('최대 점수:',max_score)
print('최소 점수:', min_score)
print('80점 이상인 학생 수:명',above_80)



""" scores = [10, 20, 60, 70, 80]

total = sum(scores)
avg = total / len(scores)
max_score = max(scores)
min_score = min(scores)
above_80 = len([score for score in scores if score >= 80])

print("평균 점수 : ", avg)
print("최대 점수 : ", max_score)
print("최소 점수 : ", min_score)
print("80점 이상인 수 : ", above_80)
 """