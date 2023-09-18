from pygame import mixer
import time

mixer.init()
mixer.music.load("가끔이러다.mp3")
mixer.music.play()
time.sleep(10)

fp=open('펀치.txt')

fpList=fp.readlines()

for i in fpList:
    print(i,end='')
    time.sleep(3.5)
    



