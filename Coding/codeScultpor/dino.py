import simplegui
import random

# Constants
WIDTH = 600
HEIGHT = 300
GRAVITY = 1
JUMP_STRENGTH = -15
OBSTACLE_SPEED = 5
DINO_WIDTH = 40
DINO_HEIGHT = 50
OBSTACLE_WIDTH = 30
OBSTACLE_HEIGHT = 40

class GameObject:
    def __init__(self, x, y, width, height, color):
        self.x = x
        self.y = y
        self.width = width
        self.height = height
        self.color = color

    def draw(self, canvas):
        canvas.draw_polygon([(self.x, self.y), (self.x + self.width, self.y),
                             (self.x + self.width, self.y - self.height), (self.x, self.y - self.height)], 
                             1, "Black", self.color)

class Dino(GameObject):
    def __init__(self):
        GameObject.__init__(self, 50, HEIGHT - DINO_HEIGHT - 10, DINO_WIDTH, DINO_HEIGHT, "Green")
        self.vel_y = 0
        self.is_jumping = False

    def jump(self):
        if not self.is_jumping:
            self.vel_y = JUMP_STRENGTH
            self.is_jumping = True

    def update(self):
        self.y += self.vel_y
        self.vel_y += GRAVITY

        if self.y >= HEIGHT - DINO_HEIGHT - 10:
            self.y = HEIGHT - DINO_HEIGHT - 10
            self.is_jumping = False

class Obstacle(GameObject):
    def __init__(self):
        GameObject.__init__(self, WIDTH, HEIGHT - OBSTACLE_HEIGHT - 10, OBSTACLE_WIDTH, OBSTACLE_HEIGHT, "Red")

    def update(self):
        self.x -= OBSTACLE_SPEED
        if self.x < -self.width:
            self.x = WIDTH + random.randint(100, 300)

class Game:
    def __init__(self):
        self.dino = Dino()
        self.obstacle = Obstacle()
        self.running = True

    def update(self):
        if self.running:
            self.dino.update()
            self.obstacle.update()
            self.check_collision()

    def check_collision(self):
        if (self.dino.x + self.dino.width > self.obstacle.x and self.dino.x < self.obstacle.x + self.obstacle.width and
                self.dino.y + self.dino.height > self.obstacle.y):
            self.running = False

    def draw(self, canvas):
        canvas.draw_text("Press SPACE to Jump", (150, 30), 20, "Black")
        canvas.draw_line((0, HEIGHT - 10), (WIDTH, HEIGHT - 10), 2, "Black")
        
        if self.running:
            self.dino.draw(canvas)
            self.obstacle.draw(canvas)
        else:
            canvas.draw_text("Game Over! Press SPACE to Restart", (120, 150), 20, "Red")

    def keydown(self, key):
        if key == simplegui.KEY_MAP['space']:
            if not self.running:
                self.__init__()  # Restart game on space press
            self.dino.jump()

# Create game instance
game = Game()

def draw(canvas):
    game.update()
    game.draw(canvas)

def keydown(key):
    game.keydown(key)

frame = simplegui.create_frame("Dino Game", WIDTH, HEIGHT)
frame.set_draw_handler(draw)
frame.set_keydown_handler(keydown)
frame.start()