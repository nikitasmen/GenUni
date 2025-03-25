import re

class ParagraphCheck: 
    
    @staticmethod
    def simpleCheck(text):
        sentence_pattern = r'([A-Z][a-z,\s]+[.!?]$)'    
        sentences = re.findall(sentence_pattern, text)
        return " ".join(sentences) == text

    @staticmethod
    def checkWithNumbers(text): 
        sentence_pattern = r'([A-Z0-9][a-z0-9,\s]+[.!?]$)'  
        sentences = re.findall(sentence_pattern, text)
        return " ".join(sentences) == text

    @staticmethod
    def checkWithGreek(text): 
        sentence_pattern = r'([A-Z\u0386-\u03AB\u0391-\u03A9][a-z\u03AC-\u03CE\u03B1-\u03C9,\s]+[.!?])'
        sentences = re.findall(sentence_pattern, text)
        return " ".join(sentences) == text



if __name__ == "__main__":

    paragraph = input("Εισάγετε μια παράγραφο: ")
    if ParagraphCheck.simpleCheck(paragraph):
        print("Η παράγραφος είναι σωστή.")
    else:
        print("Η παράγραφος δεν είναι σωστή.")
        
    
    paragraph = input("Εισάγετε μια παράγραφο: ")
    if ParagraphCheck.checkWithNumbers(paragraph):
        print("Η παράγραφος είναι σωστή.")
    else:
        print("Η παράγραφος δεν είναι σωστή.")
        
        
    paragraph = input("Εισάγετε μια παράγραφο: ")
    if ParagraphCheck.checkWithGreek(paragraph): 
        print("Η παράγραφος είναι σωστή.")  
    else:
        print("Η παράγραφος δεν είναι σωστή.")
