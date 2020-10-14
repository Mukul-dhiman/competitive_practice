for t in range(int(input())):
	n,k=map(int,input().split())
	s=str(input())
	ans=0
	v=1
	wp=False
	for i in range(len(s)):
		if(s[i]=='W'):
            wp=True
            ans+=v
            v=2
        else:
            v=1
    if(wp==False):
        ans+=1
        ans+=(n-1)*2
        continue
	l=0
	slist = s.split('W')
	length=len(slist)
	l=len(slist[length-1])
	del slist[length-1]
	f=0
	if(len(slist)):
         f = len(slist[0])
         del slist[0]
	while("" in slist):
		slist.remove("")
	slist.sort()
	for i in range(len(slist)):
		if(k>=len(slist[i])):
			ans+=2*(len(slist[i])-1)+3
			k-=len(slist[i])
		else:
			ans=ans+(2*k)
			k-=k
			break
	ans+=min(k,l)*2
	k-=min(k,l)
	if(k>0 and f):
	    ans+=min(k,f)*2
	print(ans)


