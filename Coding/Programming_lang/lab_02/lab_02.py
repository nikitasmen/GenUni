import re

class ParagraphCheck: 
    def __init__(self): 
        self.text = ""  
        self.tap = ["just english", "numbers", "greek"] 
        self.index= 0 
        
    def add(self): 
        self.text = input(f"Enter a paragraph with {self.tap[self.index]}: ")
        self.index += 1
        return self.text
    
  
            
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
    
    for i in range(3): 
        paragraph.add()
        print(paragraph.simpleCheck())
        print(paragraph.checkWithNumbers())
        print(paragraph.checkWithGreek())