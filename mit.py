mac=0
end=0
cnt=0
l=[]
s=input()
for i in range(0,len(s)-1):
 if s[i]<=s[i+1]:
  cnt=cnt+1
 else:
  cnt=cnt+1
  if cnt>mac:
     mac=cnt
     end=i
     start=i-cnt+1
     l.insert(0,(start,end))
     print(mac,start,end)
  cnt=0
if mac==0:
   print(s[0:len(l)])
print(s[l[0][0]:l[0][1]+1])
   


   
   
   
  

   
  

   
   