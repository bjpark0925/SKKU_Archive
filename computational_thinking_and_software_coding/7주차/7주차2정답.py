receiver = input('생일을 맞이한 사람의 이름은?' )
old = int(input('몇 번째 생일인가요? '))
sender = input('보내는 사람의 이름을 입력하세요: ')

text = "생일 축하 합니다!"
song = "%s 사랑하는 %s님 %s" %(text*2, receiver, text)

print(song, '\n', '='*30)
message = '%s님의 %d번째 생일을 진심으로 축하합니다!\n%s 보냄'%(receiver, old, sender)
print(message)
