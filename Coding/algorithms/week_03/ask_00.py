from random import * 
from time import * 

#erotima 4.a 
def bubblesort(array):
    for i in range(len(array)):
        for j in range(0, len(array)-i-1):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
    return array
#erotima 4.b
def countunorder(array):
	counter = 0 
	for i in range(0,len(array)-1):
		j = i+1 
		while j < len(array):
			if array[i] == array[j]:
				counter+=1 
			j+=1
	return counter

def countorder(array):
	counter = 0 
	i=0 
	while i<len(array)-1:
		counter+=1 
		i+=1 
		if array[i]!=array[i+1]:
			counter=0
	return counter

a = []
b = [] 
c = []  

for i in range(1000): 
	if i<100:
		if i < 10 : 
			a.append(randint(1,9))
		b.append(randint(1,999))
	c.append(randint(1,999))
# print(f"O pinakas a einai: {a}")
# print(f"O pinakas b einai: {b}")
# print(f"O pinakas c einai: {c}")

#erotima 3g 
length = len(a)
for i in range(length-1):
	for j in range(0, length-i-1):
		 if a[j] > a[j + 1]:
		 	a[j],a[j+1] = a[j+1], a[j]
print(a)

start = time()
a=bubblesort(a)
stop = time()
ta = stop - start


start = time()
b=bubblesort(b)
stop = time()
tb = stop - start 

start = time()
c=bubblesort(c)
stop = time()
tc = stop - start 

print(f"O pinakas a meta thn taksinomisi einai : {a} se xrono: {ta} ")
print(f"O pinakas b meta thn taksinomisi einai : {b} se xrono: {tb} ")
print(f"O pinakas c meta thn taksinomisi einai : {c} se xrono: {tc} ")

pin = []
for i in range(1000): 
 	pin.append(randint(1,50))

start=time()
a1 = countunorder(pin)
stop = time()
taun = stop - start
a = bubblesort(pin)
start = time()
a2 = countorder(pin)
stop = time()
taor = stop - start 
print(f"O pinakas exei {a1}  {a2} se xrono {taun} prin tin taksinomisi kai meta {taor}")
