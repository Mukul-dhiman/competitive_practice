
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


print(funWithAnagrams(strArr))