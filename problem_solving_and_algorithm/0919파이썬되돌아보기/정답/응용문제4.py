# 응용문제4

# 동전교환기 프로그램

money=int(input('money : '))
c500=money//500
change=money%500

c100=change//100

print('coin500 : %d개' % c500)
print('coin100 : %d개' % c100)
