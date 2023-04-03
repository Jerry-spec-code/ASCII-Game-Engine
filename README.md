# ASCII Game Engine
Built a C++ game engine that supports the creation of ASCII art video games using Ncurses and the MVC design pattern, and created two mini games to illustrate the use of the engine’s game objects, movement types, and collision types.

## Game #1: Ice Cream Drop

<img width="461" alt="image" src="https://user-images.githubusercontent.com/78711575/229633312-da375f47-cfb3-4a7b-ba1e-5402aa6d210a.png">

In the first game, we begin with an ice cream (represented by an ‘O’ character) in the middle of the screen sitting on top of the first of a series of platforms, as shown in the screenshot above. The goal of the game is to fall through as many platforms as possible before the game ends. 

The player then controls whether the ice cream moves left or right, each keystroke corresponding to moving one ascii unit. If the ice cream is on top of a hole, it falls onto the next platform, and continues to fall through the platforms until it is no longer on top of a hole. At the same time, there may or may not be a fly (represented by a rectangle of three ‘X’s) near the hole on a particular platform, and after a certain number of clock “ticks” in the game, the platforms, flies, and ice cream will all shift up by one within the playing area, and a new platform (which may or may not have a fly) is generated near the bottom of the frame. 

Therefore, there are two ways that the game can end. First, if the ice cream disintegrates at the top by colliding with the top of the frame as a result of the game objects shifting up by one within the playing area, then the game ends. Second, if the ice cream collides with a fly, then it will bounce off of it, which will end the game as well. In addition, since the flies in the game happen to be stationary, the user could potentially fall through a previous platform such that the hole on the current platform is blocked by a fly. Therefore, the user will be able to pass through the border on the side via a wraparound, so when the ice cream leaves on one side of the screen, it will appear on the other side. 

Regarding the incorporation of the built-in game objects in the engine, Ice Cream Drop effectively utilizes the Character and Rectangle objects and showcases the flexibility of the way these classes were designed. Indeed, the ice cream was designed with its own class that inherited from the Character class, and the flies were designed to inherit from the Rectangle class (shown in the updated UML diagram). 

In addition, movement and collision types were also demonstrated. In particular, the ice cream is both player controlled and moves in a straight line path while being gravitated towards a specified border of the screen (in this case the bottom). The collision with the fly triggers a loss and demonstrates colliding via bouncing off one another, and the collision with the border leads to the ice cream passing through it, which is shown via the wraparound. Finally, objects colliding and stopping with one another is shown when the ice cream lands on another border. 

## Game #2: Space Invaders

<img width="424" alt="image" src="https://user-images.githubusercontent.com/78711575/229633447-30cfe9cd-7d23-4d2a-a788-3190d2802f70.png">

In the second game, we begin with a rocket ship in the middle of the screen shown above  (represented with a bitmap of ‘O’s) with a group of aliens on each side of the screen (each represented by an ‘X’). The rocket ship has the ability to shoot at the aliens via spawning bullets, and can rotate based on player input to enable the ability to shoot on both sides. In addition, the player can specify whether they want the rocket to move left or right relative to the direction that it is facing. Once again, each keystroke corresponds to one ascii unit. 

The new line of aliens will spawn after a certain number of clock “ticks” within the game, or if the player does not give input for a certain period of time. Shooting one bullet will either collide with an alien (which will destroy both the alien and the bullet) or collide with the border (which will destroy the bullet). The goal of the game is to shoot as many aliens as possible before the game ends, which can happen either when the rocket ship collides with the border (which can happen by moving left and right or via rotation), or with one of the other aliens. 

Regarding the implementation of the built-in features of the game engine, Space Invaders effectively utilizes the Bitmap class and shows how the Rocket Ship (which is its own class) can inherit many of the properties of the Bitmap due to the strength in the quality of the design of the engine. In addition, it demonstrates the engine’s ability to be adaptive to many different kinds of movement, such as being player controlled, moving in a straight line (when the bullet moves towards the aliens), and stationary and cycling through a periodic sequence based on user input. 

On top of that, collision types were also shown. With a bullet colliding with an alien, we have a collision where two items are destroyed. When the spaceship collides with the border, we have a collision triggering the ending of a game, where we have part of the spaceship passing through the border. 

## Project Setup

The following commands can be performed from the root directory

```sh
make (compiles the c++ code)
./game1 (Ice Cream Drop)
./game2 (Space Invaders)
make clean (removes object and executable files)
```
