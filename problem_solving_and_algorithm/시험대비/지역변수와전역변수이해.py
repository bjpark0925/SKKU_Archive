a=2
def test():
    global a
    print('result: %d'%a)
    a=3
test()
print('result: %d'%a)
