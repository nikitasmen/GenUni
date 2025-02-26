a = [] 
b = [] 
c = [] 

for i in range(20):
	a.append((i+1)**2)
	b.append(2*(1+i))
	c.append(a[i]+b[i])


print(a)
print(b)
print(c)
