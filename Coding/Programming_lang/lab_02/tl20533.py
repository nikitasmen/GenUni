import re

def word_check(text):#Αγγλικά
    checker = r'([A-Z][a-z,\s]+[.!?])'
    check_paragraph = re.findall(checker,text)
    print(check_paragraph)
    if " ".join(check_paragraph)==text:
        print('\nΕίναι σωστή η πρόταση!')
    else:
        print('\nΕίναι λάθος η πρόταση!')

def num_check(text):#Αγγλικά και αριθμούς
    checker = r'([A-Z0-9][a-z0-9,\s]+[.!?])'
    check_paragraph = re.findall(checker,text)
    print(check_paragraph)
    if " ".join(check_paragraph)==text:
        print('\nΕίναι σωστή η πρόταση!')
    else:
        print('\nΕίναι λάθος η πρόταση!')

def greek_check(text):#Ελληνικά με αριθμούς και Αγγλικά
    checker = r'([\u0386-\u03ABA-Z0-9][\u03AC-\u03CEa-z0-9,\s]+[.!?;])'
    check_paragraph = re.findall(checker,text)
    print(check_paragraph)
    if " ".join(check_paragraph)==text:
        print('\nΕίναι σωστή η πρόταση!')
    else:
        print('\nΕίναι λάθος η πρόταση!')
        
counter = [0,0,0]#Για νε ξέρει η while αν έχουν γίνει όλα τα παραδείγματα.
while(counter[0]!=1 or counter[1]!=1 or counter[2]!=1 ):
    paragrafos = input('Πληκτρολογήστε μία παράγραφο :')
    checker = r'([\u03B1-\u03C9])'
    if re.search(checker,paragrafos):#Έχει ελληνικά και ίσως και αριθμούς
        if counter[0]==0:
            greek_check(paragrafos)
            counter[0]=1
        else:
            greek_check(paragrafos)
    elif re.search("\d",paragrafos):#Έχει αριθμούς και Αγγλικά
        if counter[1]==0:
            num_check(paragrafos)
            counter[1]=1
        else:
            num_check(paragrafos)
    else:#Έχει αγγλικά
        if counter[2]==0:
            word_check(paragrafos)
            counter[2]=1
        else:
            word_check(paragrafos)
