import random # Για τη δημιουργία της τυχαίας λίστας και την κλήση της μεθόδου randint
import time # Για τη χρονομέτρηση της εκτέλεσης του script

# Δημιούργία της λίστας των τυχαίων αριθμών
start_time = time.time() # Καταγράφει από το σύστημα το timestamp έναρξης
random_numbers = [random.randint(1, 100) for _ in range(20)]


# Αρχικοποίηση των λιστών που θα περιέχουν τους άρτιους και τους περιττούς αριθμούς.
even_numbers = []
odd_numbers = []

# Διαχωρισμός της λίστας των τυχαίων αριθμών σε άρτιους και περιττούς
for number in random_numbers:
     if number % 2 == 0: # Ελέγχει αν ο αριθμός είναι άρτιος
          even_numbers.append(number)
     else:
          odd_numbers.append(number)

end_time = time.time() # Καταγράφει από το σύστημα το timestamp λήξης του αλγορίθμου


# Υπολογισμός χρόνου εκτέλεσης
execution_time = end_time - start_time

# Εκτύπωση της αρχικής λίστας
print("Η αρχική λίστα τυχαίων αριθμών:")
print(random_numbers)

# Εκτύπωση του πλήθους των περιττών αριθμών και της λίστας τους
print("\n\n\n\n Πλήθος περιττών αριθμών:", len(odd_numbers))
print("Περιττοί αριθμοί:", odd_numbers)

# Εκτύπωση του πλήθους των άρτιων αριθμών και της λίστας τους
print("\n\n\n\n\nΠλήθος άρτιων αριθμών:", len(even_numbers))
print("\nΆρτιοι αριθμοί:", even_numbers)

# Εκτύπωση του χρόνου εκτέλεσης
print(f"\nΧρόνος εκτέλεσης: {execution_time:.6f} seconds")