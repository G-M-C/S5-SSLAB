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

PID=[]
BT=[]
WT=[]
TAT=[]
n = int(input("No:of processes ? "))
p = []
for i in range(0,n):
    p.append(Process())
p.sort(key=operator.attrgetter('bt'))
for i in range(0, n):
    if i==0:
        p[i].get_tat(p[i].bt)
    else:
        p[i].get_tat(p[i-1].tat+p[i].bt)
    p[i].get_wt(p[i].tat-p[i].bt)
    PID.append(p[i].pid)
    BT.append(p[i].bt)
    WT.append(p[i].wt)
    TAT.append(p[i].tat)
    
print("\n\nSJF Scheduling")
for item in PID:
    print("< {} >".format(item),end=" ")

d={'Process #':PID,'Burst Time':BT,'Turn-around Time':TAT,'Waiting Time':WT}
ptable=pd.DataFrame(d)
display(ptable)
avw=float(sum(WT)/n)
avt=float(sum(TAT)/n)
print("Average Turnaround Time : ",avt)
print("Average Waiting Time : “,avw)
