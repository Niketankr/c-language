#include <stdio.h>
#include <unistd.h>   // for usleep() on Unix/Linux
// Use #include <windows.h> and Sleep() if you're on Windows

int main() {
    int i;

    // Clear the screen
    printf("\033[2J"); // ANSI escape code to clear screen

    for(i = 0; i < 60; i++) {
        // Move cursor to top-left
        printf("\033[H");  // ANSI escape code to move cursor to top-left

        // Print spaces to simulate movement
        for(int j = 0; j < i; j++) {
            printf(" ");
        }

        // Draw a simple "car"
        printf("   ______\n");
        for(int j = 0; j < i; j++) printf(" ");
        printf(" _/[] [] \\_\n");
        for(int j = 0; j < i; j++) printf(" ");
        printf("|_CAR_____| \n");
        for(int j = 0; j < i; j++) printf(" ");
        printf(" O       O\n");

        // Pause for a moment to simulate animation
        usleep(100000);  // 100,000 microseconds = 0.1 second
    }

    return 0;
}
  ______
 _/[] [] \_
|_CAR_____| 
 O       O
    ______
  _/[] [] \_
 |_CAR_____| 
  O       O
     ______
   _/[] [] \_
  |_CAR_____| 
   O       O
      ______
    _/[] [] \_
   |_CAR_____| 
    O       O
       ______
     _/[] [] \_
    |_CAR_____| 
     O       O
        ______
      _/[] [] \_
     |_CAR_____| 
      O       O
         ______
       _/[] [] \_
      |_CAR_____| 
       O       O
          ______
        _/[] [] \_
       |_CAR_____| 
        O       O
           ______
         _/[] [] \_
        |_CAR_____| 
         O       O
            ______
          _/[] [] \_
         |_CAR_____| 
          O       O
             ______
           _/[] [] \_
          |_CAR_____| 
           O       O
              ______
            _/[] [] \_
           |_CAR_____| 
            O       O
               ______
             _/[] [] \_
            |_CAR_____| 
             O       O
                ______
              _/[] [] \_
             |_CAR_____| 
              O       O
                 ______
               _/[] [] \_
              |_CAR_____| 
               O       O
                  ______
                _/[] [] \_
               |_CAR_____| 
                O       O
                   ______
                 _/[] [] \_
                |_CAR_____| 
                 O       O
                    ______
                  _/[] [] \_
                 |_CAR_____| 
                  O       O
                     ______
                   _/[] [] \_
                  |_CAR_____| 
                   O       O
                      ______
                    _/[] [] \_
                   |_CAR_____| 
                    O       O
                       ______
                     _/[] [] \_
                    |_CAR_____| 
                     O       O
                        ______
                      _/[] [] \_
                     |_CAR_____| 
                      O       O
                         ______
                       _/[] [] \_
                      |_CAR_____| 
                       O       O
                          ______
                        _/[] [] \_
                       |_CAR_____| 
                        O       O
                           ______
                         _/[] [] \_
                        |_CAR_____| 
                         O       O
                            ______
                          _/[] [] \_
                         |_CAR_____| 
                          O       O
                             ______
                           _/[] [] \_
                          |_CAR_____| 
                           O       O
                              ______
                            _/[] [] \_
                           |_CAR_____| 
                            O       O
                               ______
                             _/[] [] \_
                            |_CAR_____| 
                             O       O
                                ______
                              _/[] [] \_
                             |_CAR_____| 
                              O       O
                                 ______
                               _/[] [] \_
                              |_CAR_____| 
                               O       O
                                  ______
                                _/[] [] \_
                               |_CAR_____| 
                                O       O
                                   ______
                                 _/[] [] \_
                                |_CAR_____| 
                                 O       O
                                    ______
                                  _/[] [] \_
                                 |_CAR_____| 
                                  O       O
                                     ______
                                   _/[] [] \_
                                  |_CAR_____| 
                                   O       O
                                      ______
                                    _/[] [] \_
                                   |_CAR_____| 
                                    O       O
                                       ______
                                     _/[] [] \_
                                    |_CAR_____| 
                                     O       O
                                        ______
                                      _/[] [] \_
                                     |_CAR_____| 
                                      O       O
                                         ______
                                       _/[] [] \_
                                      |_CAR_____| 
                                       O       O
                                          ______
                                        _/[] [] \_
                                       |_CAR_____| 
                                        O       O
                                           ______
                                         _/[] [] \_
                                        |_CAR_____| 
                                         O       O
                                            ______
                                          _/[] [] \_
                                         |_CAR_____| 
                                          O       O
                                             ______
                                           _/[] [] \_
                                          |_CAR_____| 
                                           O       O
                                              ______
                                            _/[] [] \_
                                           |_CAR_____| 
                                            O       O
                                               ______
                                             _/[] [] \_
                                            |_CAR_____| 
                                             O       O
                                                ______
                                              _/[] [] \_
                                             |_CAR_____| 
                                              O       O
                                                 ______
                                               _/[] [] \_
                                              |_CAR_____| 
                                               O       O
                                                  ______
                                                _/[] [] \_
                                               |_CAR_____| 
                                                O       O
                                                   ______
                                                 _/[] [] \_
                                                |_CAR_____| 
                                                 O       O
                                                    ______
                                                  _/[] [] \_
                                                 |_CAR_____| 
                                                  O       O
                                                     ______
                                                   _/[] [] \_
                                                  |_CAR_____| 
                                                   O       O
                                                      ______
                                                    _/[] [] \_
                                                   |_CAR_____| 
                                                    O       O
                                                       ______
                                                     _/[] [] \_
                                                    |_CAR_____| 
                                                     O       O
                                                        ______
                                                      _/[] [] \_
                                                     |_CAR_____| 
                                                      O       O
                                                         ______
                                                       _/[] [] \_
                                                      |_CAR_____| 
                                                       O       O
                                                          ______
                                                        _/[] [] \_
                                                       |_CAR_____| 
                                                        O       O
                                                           ______
                                                         _/[] [] \_
                                                        |_CAR_____| 
                                                         O       O
                                                            ______
                                                          _/[] [] \_
                                                         |_CAR_____| 
                                                          O       O
                                                             ______
                                                           _/[] [] \_
                                                          |_CAR_____| 
                                                           O       O
                                                              ______
                                                            _/[] [] \_
                                                           |_CAR_____| 
                                                            O       O

