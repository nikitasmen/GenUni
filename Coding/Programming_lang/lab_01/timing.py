import time

N = 1000  # Μέγεθος πίνακα

def initialize_by_rows(matrix):
    for i in range(N):
        for j in range(N):
            matrix[i][j] = 0

def initialize_by_columns(matrix):
    for j in range(N):
        for i in range(N):
            matrix[i][j] = 0

def main():
    matrix = [[0] * N for _ in range(N)]  # Δημιουργία πίνακα

    # Αρχικοποίηση κατά γραμμές
    start = time.time()
    initialize_by_rows(matrix)
    end = time.time()
    print(f"Time taken for row-wise initialization: {end - start:.6f} seconds")

    # Αρχικοποίηση κατά στήλες
    start = time.time()
    initialize_by_columns(matrix)
    end = time.time()
    print(f"Time taken for column-wise initialization: {end - start:.6f} seconds")

if __name__ == "__main__":
    main()
