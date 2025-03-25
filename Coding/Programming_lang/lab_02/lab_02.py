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
        sentence_pattern = r'([A-Z\u0386-\u03AB][a-z\u03AC-\u03CE,\s]*[.!?]$)'  
        sentences = re.findall(sentence_pattern, text)
        print(sentences)
        return " ".join(sentences) == text


if __name__ == "__main__":

    paragraph = input("Εισάγετε μια παράγραφο: ")
    if ParagraphCheck.simpleCheck(paragraph):
        print("Η παράγραφος είναι σωστή.")
    else:
        print("Η παράγραφος δεν είναι σωστή.")
        
    
    # paragraph = input("Εισάγετε μια παράγραφο: ")
    # if ParagraphCheck.checkWithNumbers(paragraph):
    #     print("Η παράγραφος είναι σωστή.")
    # else:
    #     print("Η παράγραφος δεν είναι σωστή.")
        
        
    paragraph = input("Εισάγετε μια παράγραφο: ")
    if ParagraphCheck.checkWithGreek(paragraph): 
        print("Η παράγραφος είναι σωστή.")  
    else:
        print("Η παράγραφος δεν είναι σωστή.")
