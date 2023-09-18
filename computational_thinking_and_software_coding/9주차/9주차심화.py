num_list1=[]
num_list2=[]
num_list3=[]

for i in range(1,51,1):
    if (i%2==0) and(i%3==0):
        num_list1.append(i)
    if (i%3==0) or (i%7==0):
        num_list2.append(i)
    if (i%5!=0):
        num_list3.append(i)

print(num_list1)
print(num_list2)
print(num_list3)
