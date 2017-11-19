from voting import Voting
import socket
class Node():
    def __init__(self):
        self.flag = 0 ## 0 is give_vot 1 is request_vot
        self.status = 0 ### 0 is followers 1 is candidate  2 is leader 
    
    @property
    def flag(self):
        return self.__flag

    @flag.setter
    def flag(self, flag):
        if flag == 0:
            self.__flag = 0
            self.__status = 0
            print("You are follower ")

        elif flag == 1:
            print("You request vote")
            self.__flag = 1 ##candidate 
        elif flag == None :
            print("You are leader")
            self.__flag = 2 ##leader
    

