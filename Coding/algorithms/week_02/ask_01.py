import random
a = [] 
for i in range(20):
	a.append(random.randint(1,10))

b= 5 
flag = 0 

for i in range(len(a)):
	if a[i]==b:
		flag = 1 	
		break 
		
if flag:
	print(f"Found number: {b} in list: ",a)
else:
	print("Did not found in list: ",a)

	
if b in a : 
	print("found")
else: 
	print("Not")