# Object-Oriented Programming 1 Projects

This repository contains projects and assignments completed as part of the Object-Oriented Programming 1 course at Łódź University of Technology. The course aimed to master the basics of object-oriented programming and apply its principles in various projects.

## Contents

The repository includes the following projects:

### Project 1: Custom String Concatenation Function in C

Implementation of a function in C that takes two strings, allocates memory, and returns the concatenation of these strings without using functions from the `<string.h>` library.

### Project 2: Stack with Dynamic Memory Allocation

Implementation of a `Stack` class using dynamic memory allocation.

### Project 3: Complex Numbers

Implementation of a `Complex` class with one constructor, operators, and methods `abs()` to return the modulus of the complex number, `phase()` to return the phase of the complex number, and `conj()` to return the conjugate of the complex number.

### Project 4: Polynomials

Implementation of a `Polynomials` class. This project was realized without using standard library containers and with dynamic memory allocation.

### Project 5: Associative Array Pattern

Custom implementation of the `std::map` pattern. Examples of its use include:
- `Library.h` for creating a book database, where the key is the book title (`std::string`) and the value contains information about the book.
- `Employee.h` for storing employee information.

### Project 6: Snake game 🐍

#### Features:
- Classic Gameplay: Navigate the snake, eat apples, and grow longer while avoiding collisions with the snake's body.
- Dynamic Levels: Difficulty increases as the snake grows and collects more apples.
- Pause & Restart: Game can be paused and restarted at any time using keyboard shortcuts.
- Interactive HUD: Displays current level, score, and helpful tips during gameplay.
- Boundary Wrapping: The snake can move seamlessly through the edges of the game window.
  
#### Controls utilised in the game:
- Arrow Keys: Control the direction of the snake.
- `p`: Pause or resume the game.
- `r`: Restart the game.
- `h`: Toggle the help menu.

#### How It Works:
The game begins with a small snake and a randomly placed apple.
Eating an apple increases the snake's size and score. For every 5 apples, the game level increases, and the snake's movement speed accelerates.
The game ends when the snake collides with itself.


