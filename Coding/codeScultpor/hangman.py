import random
words = ["Kalhmera", "kalinyxta", "petra", "papagalos", "kolokithi"]


def handle_out():
    temp = [] 
    for i in range(0,len(arr)):
        if(arr[i] in used):
            temp.append(arr[i])  
        else:
            temp.append('_')
    print temp
    if(not ('_' in temp)):
        print "you Won"
        tries = -1
        return tries
    return -2 
    
word =  random.choice(words)
arr = list(word)
tries =  10
used = [] 
while(tries>0): 
    found = False
    choice = input("Enter a letter") 
    
    while(choice in used): 
        print "Exeis dosei to gramma ksana"
        choice = input("Enter a letter")
        
    for i in range(0,len(arr)):
        if(arr[i] == choice): 
            found = True
        
    if(not found): 
        tries -=1 
    
    if(choice == "exit"):
        break
        
    used.append(choice)
    tmp = handle_out()
    if(tmp==-1):
        tries=-1 
      