#include "TetrisGame.hpp"
#include <SFML/Graphics.hpp>

TetrisGame::TetrisGame() {
  t1.loadFromFile("images/tiles.png");
  t2.loadFromFile("images/background.png");
  t3.loadFromFile("images/frame.png");
  s = sf::Sprite(t1);
  background = sf::Sprite(t2);
  frame = sf::Sprite(t3);

  window = new sf::RenderWindow(sf::VideoMode(360, 360), "The Game!");

  TurnClock_.delay = 5.0f;

  int n = rand() % 7;
  for (int i = 0; i < 4; i++) {
    PlayerTetromino_[i].x = figures[n][i] % 2 + 9;
    PlayerTetromino_[i].y = figures[n][i] / 2 + 8;
  }
}

TetrisGame::~TetrisGame() { delete window; }

void TetrisGame::GameLoop() {
  GameClock_.Update();
  TurnClock_.Update();

  sf::Event e;
  dx = 0;
  dy = 0;
  while (window->pollEvent(e)) {
    if (e.type == sf::Event::Closed) window->close();

    if (e.type == sf::Event::KeyPressed) {
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
  }

  //// <- Move -> ///
  for (int i = 0; i < 4; i++) {
    PlaceHolderTetromino_[i] = PlayerTetromino_[i];
    PlayerTetromino_[i].x += dx;
	PlayerTetromino_[i].y += dy;
  }
  if (!check())
    for (int i = 0; i < 4; i++) PlayerTetromino_[i] = PlaceHolderTetromino_[i];

  //////Rotate//////
  if (rotate) {
    point p = PlayerTetromino_[1];  // center of rotation
    for (int i = 0; i < 4; i++) {
      int x = PlayerTetromino_[i].y - p.y;
      int y = PlayerTetromino_[i].x - p.x;
      PlayerTetromino_[i].x = p.x - x;
      PlayerTetromino_[i].y = p.y + y;
    }
    if (!check())
      for (int i = 0; i < 4; i++)
        PlayerTetromino_[i] = PlaceHolderTetromino_[i];
  }

  ///////Tick//////
  if (GameClock_.timer > GameClock_.delay) {
    for (int i = 0; i < 4; i++) {
      PlaceHolderTetromino_[i] = PlayerTetromino_[i];    }

    if (TurnClock_.timer > TurnClock_.delay) {
		TurnClock_.timer = 0;
      for (int i = 0; i < 4; i++)
        field[PlaceHolderTetromino_[i].y][PlaceHolderTetromino_[i].x] =
            colorNum;

      colorNum = 1 + rand() % 7;
      int n = rand() % 7;
      for (int i = 0; i < 4; i++) {
        PlayerTetromino_[i].x = figures[n][i] % 2+9;
        PlayerTetromino_[i].y = figures[n][i] / 2+7;
		//If you lose, u lose *sad face*
		if (field[PlayerTetromino_[i].y][PlayerTetromino_[i].x])
		{
			window->close();
		}
      }
    }

    GameClock_.timer = 0;
  }

  ///////check lines//////////
  int k = M - 1;
  int i;
  for (i = M - 1; i > M/2; i--) {
    int count = 0;
    for (int j = 0; j < N; j++) {
      if (field[i][j]) count++;
      field[k][j] = field[i][j];
    }
    if (count < N) k--;
  }
  
  for (k; k > M/2; --k)
  {
	  for (int j = 0; j < N; j++) {
		  field[k][j] = 0;
	  }
  }
  k = 0;
  for (i = 0; i < M / 2; i++) {
	  int count = 0;
	  for (int j = 0; j < N; j++) {
		  if (field[i][j]) count++;
		  field[k][j] = field[i][j];
	  }
	  if (count < N) k++;
  }
  
  for (k; k < M/2; ++k)
  {
	  for (int j = 0; j < N; j++) {
		  field[k][j] = 0;
	  }
  }
  k = N-1;
  for (i = M - 1; i > M / 2; i--) {
	  int count = 0;
	  for (int j = 0; j < N; j++) {
		  if (field[j][i]) count++;
		  field[j][k] = field[j][i];
	  }
	  if (count < N) k--;
  }
  
  for (k; k > M/2; --k)
  {
	  for (int j = 0; j < N; j++) {
		  field[j][k] = 0;
	  }
  }
  k = 0;
  for (int i = 0; i < M / 2; i++) {
	  int count = 0;
	  for (int j = 0; j < N; j++) {
		  if (field[j][i]) count++;
		  field[j][k] = field[j][i];
	  }
	  if (count < N) k++;
  }
  
  for (k; k < M / 2; ++k)
  {
	  for (int j = 0; j < N; j++) {
		  field[j][k] = 0;
	  }
  }

  dx = 0;
  rotate = 0;
  GameClock_.delay = 0.3;

  /////////draw//////////
  window->clear(sf::Color::White);
  //window->draw(background);

  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++) {
      if (field[i][j] == 0) continue;
      s.setTextureRect(sf::IntRect(field[i][j] * 18, 0, 18, 18));
      s.setPosition(j * 18, i * 18);
      window->draw(s);
    }

  for (int i = 0; i < 4; i++) {
    s.setTextureRect(sf::IntRect(colorNum * 18, 0, 18, 18));
    s.setPosition(PlayerTetromino_[i].x * 18, PlayerTetromino_[i].y * 18);
    window->draw(s);
  }

  //window->draw(frame);
  window->display();
}
bool TetrisGame::check() {
  for (int i = 0; i < 4; i++)
    if (PlayerTetromino_[i].x < 0 || PlayerTetromino_[i].x >= N ||
        PlayerTetromino_[i].y >= M || PlayerTetromino_[i].y < 0)
      return 0;
    else if (field[PlayerTetromino_[i].y][PlayerTetromino_[i].x])
      return 0;

  return 1;
};