#ifndef TETRISGAME_HPP
#define TETRISGAME_HPP

#include <SFML/Graphics.hpp>
#include "GameClock.hpp"
#include "Event_Listener.hpp"

struct point {
  int x;
  int y;
};

class TetrisGame: public Event_Listener {
 public:
  TetrisGame();
  ~TetrisGame();

  void GameLoop();
  bool check();
  sf::RenderWindow* GetWindow() { return window; }

  void on_key_press(sf::Event e) override 
  {
	  if (e.key.code == sf::Keyboard::Space)
		  rotate = 1;
	  else if (e.key.code == sf::Keyboard::Left)
		  dx += -1;
	  else if (e.key.code == sf::Keyboard::Right)
		  dx += 1;
	  else if (e.key.code == sf::Keyboard::Up)
		  dy += -1;
	  else if (e.key.code == sf::Keyboard::Down)
		  dy += 1;
  }
  void on_close() override { window->close(); }

 private:
  GameClock GameClock_,TurnClock_;
  int figures[7][4] = {
      1, 3, 5, 7,  // I
      2, 4, 5, 7,  // Z
      3, 5, 4, 6,  // S
      3, 5, 4, 7,  // T
      2, 3, 5, 7,  // L
      3, 5, 7, 6,  // J
      2, 3, 4, 5,  // O
  };

  point PlayerTetromino_[4], PlaceHolderTetromino_[4];
  sf::RenderWindow* window;
  sf::Texture t1, t2, t3;
  sf::Sprite s, background, frame;

  const static int M = 20;
  const static int N = 20;

  int dx,dy = 0;
  bool rotate = 0;
  int colorNum = 1;

  int field[M][N] = {0};
};
#endif