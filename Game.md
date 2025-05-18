# Create a Game.md

## Game Overview

This project is a 2D platformer game implemented using C++ and the Raylib library.
The game features multiple levels, animated collectibles, enemies, a timer system, and a fully customized visual and audio experience.
It was developed as a refactoring and enhancement of a previously procedural codebase.

---

## Implementation and Refactoring Process

### Initial Code State

The initial version of the game was written in procedural C++, with significant use of global variables and hardcoded level logic.
There was minimal encapsulation, and rendering, input handling, and game logic were tightly coupled.

### Refactoring Strategy

The refactoring was approached incrementally and systematically. Key improvements include:

#### 1. **Object-Oriented Structure**

* Introduced a singleton-based `Player` class to encapsulate movement, position, animation, and physics logic.
* Created an `EnemiesController` singleton to manage enemy spawning, updating, drawing, and collisions.
* Refactored level logic into a `LevelController` class that handles dynamic level loading, parsing, and rendering.

#### 2. **Level Loading and RLE Support**

* Added a `parseLevelRLE()` function and `loadLevelsFromFile()` method to support compact level storage in RLE format.
* Replaced static inline arrays with dynamic loading of levels from external `.rll` files.

#### 3. **Separation of Concerns**

* Separated rendering into `graphics.h`, which handles all drawing (UI, parallax backgrounds, menus, victory screen, etc).
* Kept logic for assets, utilities, and game state transitions modular and minimal.

#### 4. **Animation System**

* Implemented a `sprite` structure to handle frame-based animations.

---

## Visual and Audio Enhancements

### Background and Theme

* Switched from daytime to nighttime theme
* Replaced original layers with custom pixel art:

  * **Background**: Dense pine forest under starry sky
  * **Middleground**: silhouettes of Christmas trees
  * **Foreground**: Atmospheric volumetric clouds

### Tiles and Collectibles

* Replaced walls with earthy soil tiles
* Spikes transformed into dark swamp algae
* Coins replaced by animated glowing rubies (3-frame loop with shimmer effect)

### Sound

* Background music added via `.wav` file
* Played in a loop using Raylib's `PlaySound()`

---

## Challenges and Solutions

| Challenge                  | Solution                                                                                   |
| -------------------------- | ------------------------------------------------------------------------------------------ |
| Global state entanglement  | Singleton pattern for Player and LevelController                                           |
| Procedural rendering logic | Created `draw_level()` in LevelController and moved graphics logic out of `platformer.cpp` |
| Level size limitations     | Used dynamic memory and vectors to support varying level sizes                             |
| Animation layering issues  | Refined sprite rendering order and frame skipping                                          |
| Visual inconsistencies     | Iteratively generated and tested custom pixel assets                                       |
| Missing resources          | Debugged asset loading paths and ensured files were 32-bit PNGs of correct dimensions      |

---

## Setup and Running Instructions

### Requirements

* **C++ Compiler** with C++17 support
* **CMake 3.15+**
* **Raylib** installed or included in the project
* **CLion** (recommended) or any CMake-compatible IDE

### Controls

* `A/D` or `←/→` — move left/right
* `W`, `↑`, or `Space` — jump
* `ESC` — pause
* `Enter` — interact/menu navigation

---

## Conclusion

This game demonstrates a full transition from procedural to object-oriented architecture, 
implementation of RLE-level parsing, 
visual and audio enhancements, 
and structured modular design. 
