from random import *
a = []
b = []
c=[]
len_list = 10 

for i in range(len_list):
	a.append(randint(1,20))

i = 0 
while i<len_list:
	b.append(randint(1,20))
	c.append(a[i]*b[i])
	i +=1 


print(a)
print(b)
print(c)