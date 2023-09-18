import random

location=["left_top", "center_top","right_top","left","center","right",
          "left_bottom","center_bottom","right_bottom"]

computer_choice=random.choice(location)
player_choice=input("막는 구역: ")
print(computer_choice)

if computer_choice==player_choice:
    print("막음")
else:
    print("뚫림")
