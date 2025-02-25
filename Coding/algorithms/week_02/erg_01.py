from random import * 
#arxikopoiish listas a 
a = []
for i in range(30): 
	a.append(randint(1,20))
print("Lista : ",a)

#erotima a 
counter = 0 
for i in range(len(a)-1):
	j = i+1 
	while j < len(a):
		if a[i] == a[j]:
			counter+=1 
		j+=1


#erotima b 
b = {}
j= 0 
for i in range(len(a)-1): 
	j = i+1 
	while j<len(a):
		if a[i] == a[j]: 
			if (a[i] in b) : 
				b[a[i]] +=1 
			else :
				b.update({a[i]: 2})
		j+=1 
#if key[value]>2 key[value]-=1 


c = []
for i in range(21):
	c.append(0)
j= 0
for i in range(len(a)-1): 
	j = i+1 
	while j<len(a):
		if a[i] == a[j]: 
			if(c[a[j]] == 0):
				c[a[j]] =2
			else:
				c[a[j]] +=1 
		i+=1 

#erotima c 
for i in range(len(a)-1):
	for j in range(i+1,len(a)):
		if a[j]<a[i]: 
			a[j],a[i] = a[i],a[j]

#emfanisi apotelesmaton 
print("\nPlithos diplotipon : ", counter,"\n")

for key,value in b.items():
	print(f"O arithmos {key} yparxei {value} fores")

for i in range(len(c)):
	if c[i]>0:
		print(f"O arithmos {i} yparxei {c[i]} fores")

print("\nH lista meta tin fisalida: \n",a)
