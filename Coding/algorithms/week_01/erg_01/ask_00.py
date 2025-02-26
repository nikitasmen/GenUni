import random 
a = [] 
b = []
len_list = 20
min = 1 
max = 6 

for i in range(len_list): 
	a.append(random.randint(min,max))
print(a)

#next ex 

j= 0 
while j<len_list:
	b.append(random.randint(min,max))
	j +=1 

print(b)
print(len(a),len(b))

c = [random.randint(min,max) for _ in range(len_list)] 
print(c)