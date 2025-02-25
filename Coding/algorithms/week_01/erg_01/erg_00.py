from random import *
a = []
b = []
c=[]
min = 100
max =150
len_list = 10 

for i in range(len_list):
	a.append(randint(min,max))

i = 0 
while i<len_list:
	b.append(randint(min,max))
	c.append(a[i]%b[i])
	i +=1 


print(a)
print(b)
print(c)