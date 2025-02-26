a  = [] 
c = 100 
for i in range(c): 
	a.append(i+1)
b = [] 
for i in range(len(a)):
	b.append(a[i]**2)

print(b)