grade=int(input("몇점?"))
if grade>=90:
    score='A'
elif grade>=80:
    score='B'
elif grade>=70:
    score='C'
elif grade>=60:
    score='D'
else:
    score='F'
print("%d에 대한 학점은 %s입니다."%(grade,score))
    
