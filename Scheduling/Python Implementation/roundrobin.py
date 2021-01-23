import pandas as pd
import operator

class Process:
    def __init__(self):
        self.pid=input("Enter Process ID : ")
        self.bt=int(input("Enter Burst time : "))
    def get_wt(self,x):
        self.wt=x
    def get_tat(self,x):
        self.tat=x
        

def wait_time(p,qtm,n):
    rbt=[]
    t=0
    for item in p:
        rbt.append(item.bt)
    
    while(1):
        finished=True
        for i in range(0,n):
            if rbt[i]>0:
                finished=False
            
                if rbt[i]>qtm:
                    t+=qtm
                    rbt[i]-=qtm
                    
                else:
                    t=t+rbt[i]
                    wait=t-p[i].bt
                    p[i].get_wt(wait)
                    rbt[i]=0
        
        
        if finished==True:
            break
            

def turnaround_time(p,n):
    for i in range(0,n):
        turn=p[i].wt+p[i].bt
        p[i].get_tat(turn)
                
                
PID=[]
BT=[]
WT=[]
TAT=[]
n = int(input("No:of processes ? "))
p = []
for i in range(0, n):
    p.append(Process())
    PID.append(p[i].pid)
    BT.append(p[i].bt)
qtm=int(input("Time Quantum ? "))
wait_time(p,qtm,n)
turnaround_time(p,n)

for item in p:
    WT.append(item.wt)
    TAT.append(item.tat)

d={'Process #':PID,'Burst Time':BT,'Turn-around Time':TAT,'Waiting Time':WT}
ptable=pd.DataFrame(d)
s=ptable.sort_values(by=['Waiting Time','Turn-around Time'])

    
print("\n\nRound Robin Scheduling")
l=s['Process #'].tolist()
for item in l:
    print("< {} >".format(item),end=" ")
    
display(ptable)
avw=float(sum(WT)/n)
avt=float(sum(TAT)/n)
print("Average Turnaround Time : ",avt)
print("Average Waiting Time : ",avw)
