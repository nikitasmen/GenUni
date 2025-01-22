import random
import simplegui

words = ["hello", "world", "education", "snake"]
tries = 7 

def new_game():
    global secret_word, tries, guesses, used_letters
    secret_word = random.choice(words)
    tries = 7
    guesses = [""] * len(secret_word)  # Initialize with empty strings for each letter in the word
    used_letters = []
    print("New game started! Word has", len(secret_word), "letters.")
    update_display(None)

def guess(letter):
    global secret_word, tries, guesses, used_letters    
    if letter in used_letters:
        return
    
    used_letters.append(letter)
    
    if letter in secret_word:
        for i in range(len(secret_word)):
            if secret_word[i] == letter:
                guesses[i] = letter
        print("Good guess: ", letter)
    else:
        tries -= 1
        print("Bad guess: ", letter)
        if tries == 0:
            print("You lose! The word was:", secret_word)
            new_game()
            return

    # Check if the player has won
    if "".join(guesses) == secret_word:
        print("Congratulations! You guessed the word:", secret_word)
        new_game()
    else:
        update_display(None)

def update_display(canvas):
    global secret_word, guesses, tries, used_letters
    display = ""
    for i in range(len(secret_word)):
        if guesses[i]:
            display += guesses[i]
        else:
            display += "_"
    if canvas:
        canvas.draw_text(display, [50, 50], 24, "White")
        canvas.draw_text("Tries left: " + str(tries), [50, 100], 24, "White")
        canvas.draw_text("Used letters: " + str(used_letters), [50, 150], 24, "White")
    else:
        print("Word:", display)
        print("Tries left:", tries)
        print("Used letters:", used_letters)

# Create the frame and set up event handlers
frame = simplegui.create_frame("Hangman", 400, 300)
frame.add_input("Enter a letter", guess, 100)
frame.add_button("New game", new_game, 100)
frame.set_draw_handler(update_display)

# Start the game
new_game()
frame.start()
