import re

class ParagraphCheck: 
    
 
    def simpleCheck(self):
        sentence_pattern = r'([A-Z][a-z,\s]+[.!?])'    
        sentences = re.findall(sentence_pattern, self.text)
        return " ".join(sentences) == self.text

    def checkWithNumbers(self): 
        sentence_pattern = r'([A-Z0-9][a-z0-9,\s]+[.!?])'  
        sentences = re.findall(sentence_pattern, self.text)
        return " ".join(sentences) == self. text

    def checkWithGreek(self): 
        sentence_pattern = r'([A-Z\u0386-\u03AB\u0391-\u03A9][a-z\u03AC-\u03CE\u03B1-\u03C9,\s]+[.!?;])'
        sentences = re.findall(sentence_pattern, self.text)
        return " ".join(sentences) == self.text



if __name__ == "__main__":

    paragraph = ParagraphCheck(); 
    paragraph.text = input("Enter a simple paragraph: ")
    print(paragraph.simpleCheck())
    
    paragraph.text = input("Enter a paragraph with numbers: ")
    print(paragraph.checkWithNumbers())
    
    paragraph.text = input("Enter a paragraph with greek: ")
    print(paragraph.checkWithGreek())