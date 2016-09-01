import re
import sys
import string
###################################################
dp=0
sp=0
####################################################
def lcm(x,y):
    p=x
    q=y

    while x!=y:
        if x>y:
            x=x-y
        else:
            y=y-x


    return (p*q/x)
###################################################
N=input()
list=[]
for i in range(0,N,1):
    line=str(raw_input())
    list.append(line)
    
#######################################################
for i in range(0,N,2):
    cmp=list[i+1][2]
    j=i+1
    t1=map(int,re.findall(r'\d+',list[i]))
    if len(t1)==0:
        print("Invalid Input")
        sys.exit()
    else:
        print(list[i].replace(" ","'s question is: "))
        
        

    t2=map(int,re.findall(r'\d+',list[i+1]))
    
    LCM=1
    for i in t1:
        LCM=lcm(LCM,i)

    if len(t2)==0:
        print("Question is PASSed")
        print("Answer is: "+str(LCM))
        if cmp=='S':
            sp=sp+0
            print(list[j].replace(list[j],"Sally: ")+str(sp)+"points")          
        
        else:
            dp=dp+0
            print(list[j].replace(list[j],"Darrell: ")+str(dp)+"points")
                                
    else:
        if t2[0]==LCM:
            print("Correct Answer")
            if cmp=='S':
                sp=sp+10
                print(list[j].replace(list[j],"Sally: ")+str(sp)+"points")
            else:
                dp=dp+10
                print(list[j].replace(list[j],"Darrell: ")+str(dp)+"points")
                           
                
                

        else:
            print("Wrong Answer")
            if cmp=='S':
                sp=sp+0
                print(list[j].replace(list[j],"Sally: ")+str(sp)+"points")
            else:
                dp=dp+0
                print(list[j].replace(list[j],"Darrell: ")+str(dp)+"points")
                
###################################################################
print("Total Points:")
if list[0][0]=='S':
    print("Sally: "+str(sp)+"points")
    print("Darrell: "+str(dp)+"points")
    
else:
    print("Darrell: "+str(dp)+"points")
    print("Sally: "+str(sp)+"points")

if dp==sp:
    print("Game Result: Draw")
elif dp>sp:
    print("Game Result: Darrell is winner")
else:
    print("Game Result: Sally is winner")

        






