import time
start = time.time()

def funWithAnagrams(s):
	dict = {}

	ans = []

	for string in s:
    		
			original = string
			string = ''.join(sorted(string))
			

			if string not in dict:
    				dict[string] = 1
    				ans.append(original)
					
	ans.sort()
	return ans
    	


strArr = ['code','doce','ecod','framer','frame']

i=0
while(i<1000000):
	u = funWithAnagrams(strArr) 
	i+=1

end = time.time()
print((end-start)*1000,"ms")