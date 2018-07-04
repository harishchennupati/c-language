import os
import random
import math
import turtle
import time
import Tkinter
import tkMessageBox
colors = ["DarkGreen","Pink","DarkBlue","DarkOrange","DarkRed","DarkViolet","black","green"]
turtle.speed(0) # draw as fast as possible
# it does not mean movement speed it means
#speed of animation 0 is maximum speed
turtle.bgcolor(random.choice(colors))
time.sleep(5)
         # change the background image
turtle.title("pachon")

turtle.ht() #hide turtle that is created when window is created
turtle.setundobuffer(1)# limits the amount of memory
#turtle module uses we can undo turtle actions but
#it builds up so much memory and slows down program

turtle.tracer(0)#speeds up drawing for every one frame it updates the screen if 3 for every 3 times it updates the screen



turtle.register_shape("enemy.gif")
turtle.register_shape("ally.gif")


class Sprite(turtle.Turtle):# we are inheriting from  Turtle class to make our game objects
    #from turtle module inherits evrything from turtle module and Turtle class
    # that means for sprites we can use all the Turtle metehods
    def __init__(self,spriteshape,color,startx,starty):  #starting point x on screen and y on screen
      turtle.Turtle.__init__(self,shape=spriteshape)
      # this constructor is a part of turtle module we cant see it
      #every sprite has same animation speed
      self.speed(0)
      self.penup()#not drawing anything on screen
      self.color(color)
      self.fd(0)# it just appears
      self.goto(startx,starty)#move it into starting point

      self.speed=1
      # all sprites have all these attributes when
      # we start the gamef
      #speed() is an animation speed speed attribute is turtle speed
      
    def move(self):
        self.fd(self.speed)

        #Boundary detection
        if self.xcor() > 900: # as the player inherits from sprite class
                              # for player also boundary checking is done
           self.setx(900)
           self.rt(60)
        
        if self.xcor() < -900:
           self.setx(-900)
           self.rt(60)

        if self.ycor() > 450:
           self.sety(450)
           self.rt(60)

        if self.ycor() < -450:
           self.sety(-450)
           self.rt(120)

    def is_collison(self,other):
      distance=math.sqrt((self.xcor()-other.xcor())**2 + (self.ycor()-other.ycor())**2)
      if distance<=30: 
        return True
      else:
       return False
    
#creating sprites

class Player(Sprite):# we implemented this bcz functionality
  #of player is differennt that of the all other sprites
  def __init__(self,spriteshape,color,startx,starty):  #starting point x on screen and y on screen
      Sprite.__init__(self,spriteshape,color,startx,starty)
      self.speed=2 # player spped is deefault 4
      self.lives=3
      self.shapesize(2,2,outline=None)
  def turn_left(self):
     self.lt(45)

  def turn_right(self):
     self.rt(45)

  def accelerate(self):
    self.speed=self.speed + 0.5


  def decelerate(self):
    self.speed=self.speed-0.5


class Enemy(Sprite):# we implemented this bcz functionality
  #of player is differennt that of the all other sprites
  def __init__(self,spriteshape,color,startx,starty):  #starting point x on screen and y on screen
      Sprite.__init__(self,spriteshape,color,startx,starty)
      self.speed=2 # player spped is deefault 4
      self.setheading(random.randint(0,360))
  
      # sets the angle for our enemy turtle

class Ally(Sprite):# we implemented this bcz functionality
  #of player is differennt that of the all other sprites
  def __init__(self,spriteshape,color,startx,starty):  #starting point x on screen and y on screen
      Sprite.__init__(self,spriteshape,color,startx,starty)
      self.speed=4 # player spped is deefault 4
      self.setheading(random.randint(0,360))


  def move(self):
        self.fd(self.speed)

        #Boundary detection
        if self.xcor() > 900: # as the player inherits from sprite class
                              # for player also boundary checking is done
           self.setx(900)
           self.lt(120)
        
        if self.xcor() < -900:
           self.setx(-900)
           self.lt(120)

        if self.ycor() > 450:
           self.sety(450)
           self.lt(120)

        if self.ycor() < -450:
           self.sety(-450)
           self.lt(180)

class Particle(Sprite):#this is particle class
  def __init__(self,spriteshape,color,startx,starty):  
      Sprite.__init__(self,spriteshape,color,startx,starty)
      self.shapesize(stretch_wid=0.1,stretch_len=0.1,outline=None)
      self.goto(-10000,10000) # it does not matter where we start whether x or y
       # each particle we start on frame


  def explode(self,startx,starty):# we want to change the position of the exploding particle when we creating
     self.goto(startx,starty)
     self.setheading(random.randint(0,360))

  def move(self):
    # when there is a collison i have to move all the particles there if missile shoots the enemy

   # if self.frame > 0:
     self.fd(12)
     #self.frame=self.frame+1

   # if self.frame > 20:
     # self.frame=0
     # self.goto(-10000,10000) # goto off the screen'''
      


    

    




class Missile(Sprite):
  def __init__(self,spriteshape,color,startx,starty):  
      Sprite.__init__(self,spriteshape,color,startx,starty)
      self.shapesize(stretch_wid=0.3,stretch_len=0.4,outline=None)
      self.speed=20 #speed of missile is greater
      self.status="ready" #missile is ready to be used
      # we want it to be there but not visible
      #self.ht() we can hide the turtle or we can move off the screen
      self.goto(-10000,10000)

  def is_collision(self,other):
      if (self.xcor() >= (other.xcor() - 30)) and \
        (self.xcor() <= (other.xcor() + 30)) and \
        (self.ycor() >= (other.ycor() - 30)) and \
        (self.ycor() <= (other.ycor() + 30)):
        return True
      else:
        return False


  def fire(self):
    os.system('aplay laser.wav&')
    if self.status=="ready":
      self.goto(player.xcor(),player.ycor())
      self.setheading(player.heading())# missiles heading is set to
      # players heading
      self.status="firing"   


  
  def move(self): # here we are overriding the move method in class Sprite
     
     if self.status == "ready":
       self.goto(-10000,10000)
      
     if self.status=="firing":
        self.fd(self.speed)


    #border  check
     if self.xcor() > 900 or self.xcor() <-900 or self.ycor() >450 or self.ycor()< -450 :
      self.status="ready"
      self.goto(-10000,10000)




     
    

class Game():
  def __init__(self):
    self.level=1
    self.score=0
    self.state = "splash"
    self.status="playing" # status of the 
    #game that indicates whether playing or not
    # we use the game object to display i/media/harish/programs/pong.pynformation
    # on screen
    self.pen=turtle.Turtle()#new turtle for pen to draw things
    self.lives=5

    #draw border

  def draw_border(self):
     self.pen.speed(0);# animation speed
     self.pen.color("orange")
     self.pen.pensize(6)
     # turtles always start at 0,0
     #self.pen.pendown()
     self.pen.penup()
     self.pen.goto(-900,-400)
     self.pen.pendown()
     self.pen.left(90)
     self.pen.forward(900)
     self.pen.right(90)
     self.pen.forward(1800)
     self.pen.right(90)
     self.pen.forward(950)
     self.pen.right(90)
     self.pen.forward(1800)
     self.pen.right(90)
     self.pen.forward(50)

     self.pen.penup()
     self.pen.ht() # hides the turtle
     self.pen.pendown()
     

  def show_status(self):
      self.pen.undo()
      if game.lives>0:
        msg="Level: %s Lives: %s Score: %s" %(self.level, self.lives, self.score)		
      else: 
        msg="Game Over Score: %s" %(self.score)
      self.pen.penup()
      self.pen.goto(0,-475)
      self.pen.write(msg,font=("Arial",16,"normal"))
  
  def fire_weapon(self):
    for missile in missiles:
      if missile.status=="ready":
        missile.fire()
        break
  
  
  #def fire():
  #  for bullet in bullets:
    #  if bullet.status
  def show_splash(self):

		turtle.bgpic('newq.gif')   
		turtle.update()
		time.sleep(20)
		turtle.bgpic("new1.gif")
		self.state = "setup"
  

  def set_state(self, state):
		states = ["splash", "setup", "playing", "restart", "gameover"]
		if state in states:
			self.state = state
		else:
			state = "splash" 

   #create a game object

game=Game()

#Draw the game border
game.draw_border()

#show game status

if game.state == "splash":
	game.show_splash()

game.show_status()
#print("game status",game.state)
if game.state=="setup":
    game.set_state("playing")
    player=Player("turtle","palegoldenrod",0,0)
      #enemy=Enemy("circle","green",-400,0)
    #missiles=[]
   
    missiles=[]
    for i in range(3):
      missiles.append(Missile("triangle",random.choice(colors),0,0))
      #ally=Ally("square","Black",0,0)
      #keyboard bindings
    enemies=[]
    for i in range(6):
        enemies.append(Enemy("enemy.gif","green",-400,0))

    allies=[]
    for i in range(6):
        allies.append(Ally("ally.gif","Pink",400,0))

    particles = []

    for p in range(30):
        particles.append(Particle("circle", random.choice(colors), -1000, -1000))
      # doesnot matter where they start


turtle.onkey(player.turn_left,"Left")#methods Re bounded i want bind a method to key
    #to turn that when user presses left key
    #once u create binding keyboard should listen

turtle.onkey(player.turn_right,"Right")
turtle.onkey(player.accelerate,"Up")
turtle.onkey(player.decelerate,"Down")
turtle.onkey(game.fire_weapon,"space")
    # we are going to set the space bar key for missile
turtle.listen()# listens for keyboard presses

#main game loop

while True:

      turtle.update()
  
      time.sleep(0.02)
  
     # if game.status=="restart":
      #  game.lives = 3
      #  game.score = 0
      #  player.speed = 0
      #  player.goto(0,0)
      #  player.setheading(0)
        
        #enemies=[]
        #for i in range(6):
          #enemies.append(Enemy("enemy.gif","green",-400,0))

        #allies=[]
        #for i in range(6):
          #allies.append(Ally("ally.gif","Pink",400,0))


        #for ally in allies:
          #ally.goto(-300,300)

        #for enemy in enemies:
          #enemy.goto(300,-300)


        #game.set_state="playing"
  
      if game.state=="playing":


        player.move() # turtle moves through one
        #each time through loop
        #player.turn_left() # we connect this turn left to
        # keyboard with the help of keyboard bindings 
        #enemy.move()
        for enemy in enemies:
          enemy.move()

          if player.is_collison(enemy):
          #if player collides with enemy

            os.system('aplay /home/harish/Downloads/explosion.wav&')
            

            x=random.randint(-449,+449)
            y=random.randint(-900,+900)
            enemy.goto(x,y)
            game.score-=100
            game.lives-=1
            if game.lives<1:
              game.set_state("gameover")
            game.show_status()
            player.color(random.choice(colors))
          
        for missile in missiles:
          missile.move()
  
        for missile in missiles:
          for enemy in enemies:
            if missile.is_collison(enemy):
                  os.system('aplay /home/harish/Downloads/laser.wav&')
                  x=random.randint(-449,+449)
                  y=random.randint(-900,+900)
                  enemy.goto(x,y)
                  missile.status="ready"
                  game.score=game.score+100
                  game.show_status()
                  enemy.speed+=2
                  
                  for particle in particles:
                    particle.explode(missile.xcor(),missile.ycor())
              
        

        for ally in allies:
          ally.move()

        for particle in particles:
          particle.move()

          '''if missile.is_collison(ally):
            os.system('aplay /home/harish/Downloads/explosion.wav&')
            x=random.randint(-900,900)
            y=random.randint(-450,450)
            ally.goto(x,y)
            missile.status="ready"
            game.score=game.score-50
            game.show_status()''' 
        
        #check for a collision with the player
        '''if player.is_collison(enemy):
          #if player collides with enemy

          os.system('aplay /home/harish/Downloads/explosion.wav&')
          

          x=random.randint(-449,+449)
          y=random.randint(-900,+900)
          enemy.goto(x,y)
          game.score-=100
          game.show_status()'''

      # check for a collision between missile and enemy
        '''if missile.is_collison(enemy):
          os.system('aplay /home/harish/Downloads/explosion.wav&')
          x=random.randint(-449,+449)
          y=random.randint(-900,+900)
          enemy.goto(x,y)
          missile.status="ready"
          game.score=game.score+100
          game.show_status()'''
        for missile in missiles:
          for ally in allies:
            if missile.is_collison(ally):
              os.system('aplay /home/harish/Downloads/explosion.wav&')
              x=random.randint(-900,900)
              y=random.randint(-450,450)
              ally.goto(x,y)
              missile.status="ready"
              game.score=game.score-50
              game.show_status()

        if game.state=="gameover":
              os.system('aplay /home/harish/Downloads/final.wav&')
              tkMessageBox.askyesno("Game Over", "THANK U FOR PLAYING")
              
              
              time.sleep(4)
              exit()
             # game.set_state("restart")
             # game.level = 1
              #game.score = 0
              #ogame.show_status()

              
              #for enemy in enemies:
                #enemy.ht()
                #enemy.clear()
                #del enemy
            
            
              '''for ally in allies:
                ally.ht()
                ally.clear()
                del ally'''

            
               


        if game.score / (game.level) > 300:
          game.level += 1

          for i in range (3):
            enemies.append(Enemy("enemy.gif", "red", -300,300))
            enemies[i].speed+=6
           
            allies.append(Ally("ally.gif", "blue",-300,300))
            allies[i].speed+=6
          
          for k in enemies:
              k.speed+=2
           
          for k in allies:
             k.speed+=2
          

      


      

delay=input("press enter to finish")
