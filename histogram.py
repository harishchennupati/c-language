def histogram(l):
    l.sort()
    print(l)
    k=[]
    cnt=0
    for i in range(0,len(l)-1):
        if(l[i] ==l[i+1]):
            cnt=cnt+1
        else:
         if i==len(l)-1:
             k.append((l[i],cnt+1))
         else:
          k.append((l[i],cnt+1))
         cnt=0
    g=lambda x: x[1]
    k.sort(key=g,reverse=False)
    return(k)
print(histogram([13,12,11,13,14,13,7,7,13,14,12]))


