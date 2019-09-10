# 2048 Game

This is my personal approach of the popular game [_2048_](https://2048game.com/). The implementation is realized in C and I also used some features from the ncurses library for the interface.

When you start the game a menu with 3 choices appears:

- `New Game`-> you will find a 4x4 grid with only 2 cells filled with a value of either 2 or 4. You start with score 0.
- `Resume`-> you have the option to resume the last game you played in case you haven't lost until then.
- `Exit`-> Bye, bye! :relaxed:

## Features
You will also find a __Control Panel__ beneath the game with a few simple *Instructions* in case you never played this game, a *Date/Time bar* so that you don't end up playing for the entire day and a *Highscore* to see your progress.

## HOW TO PLAY: 

Use your arrow keys to move the tiles. Tiles slide as far as possible in the chosen direction until they are stopped by either another tile or the edge of the grid. If two tiles of the same number collide while moving, they will merge into a tile with the total value of the two tiles that collided.The resulting tile cannot merge with another tile again in the same move.

The game is won when a tile with a value of 2048 appears on the board. After reaching the 2048 tile, players can continue to play (beyond the 2048 tile) to reach higher scores. When the player has no legal moves (there are no empty spaces and no adjacent tiles with the same value), the game ends.

<p align="center">
  <img src="https://i.imgur.com/odSLwpp.png"/>
  <img src="https://i.imgur.com/8kfBtkR.png"/>
</p>
