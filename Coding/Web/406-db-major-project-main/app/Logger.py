

class Logger: 
    __file_path =  'data/log.txt'
    
    def __init__(self): 
        self.__file = open(self.__file_path, 'a')
       
    
    def log(self, message):
        try: 
            self.__file = open(self.__file_path, 'a')
            
            self.__file.write(message + '\n')
            self.__file.flush()
            self.__file.close()
            print (f"Καταγράφηκε: {message}")
        except Exception as e:
            print(f"Σφάλμα κατά την καταγραφή: {e}")