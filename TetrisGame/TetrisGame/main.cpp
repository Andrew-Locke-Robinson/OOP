#include <time.h>
#include <SFML/Graphics.hpp>
#include "TetrisGame.hpp"
#include "Event_Receiver.hpp"

int main() {
  srand(time(0));
  
  TetrisGame main_tetris_game;
  Event_Receiver main_event_receiver(main_tetris_game.GetWindow());
  main_event_receiver.listen(main_tetris_game);

  while (main_tetris_game.GetWindow()->isOpen()) {
    main_event_receiver.poll();
    main_tetris_game.GameLoop();
  }

  return 0;
}