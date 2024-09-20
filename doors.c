#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    PLAYER_WON_BY_SWITHCHING = 1,
    PLAYER_LOST_BY_SWITCHING,
    PLAYER_WON_BY_STAYING,
    PLAYER_LOST_BY_STAYING
} MONTY_HALL_RESULT;

MONTY_HALL_RESULT monty_hall() {
    int door_with_prize = rand() % 3;
    int door_choice = rand() % 3;

    int door_showman;
    while (true) {
        door_showman = rand() % 3;
        if (door_showman != door_choice && door_showman != door_with_prize)
            break;
    }

    bool do_switch = rand() % 2;

    if (door_choice != door_with_prize && do_switch) {
        // Switch and got prize because of it
        return PLAYER_WON_BY_SWITHCHING;
    } else if (door_choice == door_with_prize && do_switch) {
        // Switched and lost prize, aww
        return PLAYER_LOST_BY_SWITCHING;
    } else if (!do_switch && door_choice == door_with_prize) {
        // Stayed with prize, congrats
        return PLAYER_WON_BY_STAYING;
    } else if (!do_switch && door_choice != door_with_prize) {
        // Didn't switch and didn't get prize
        return PLAYER_LOST_BY_STAYING;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int times_game = 100;
    int times_switch_positive = 0;
    int times_switch_negative = 0;
    int results[5] = {0};
    for (int i = 0; i < times_game; i++) {
        int result = monty_hall();
        results[result]++;
        if (result == PLAYER_WON_BY_SWITHCHING ||
            result == PLAYER_LOST_BY_STAYING) {
            times_switch_positive++;
        } else {
            times_switch_negative++;
        }
    }
    printf("%d successful switches / should've switched. %d unsuccesful "
           "switches. %.2f%% in favor of switch.\n",
           times_switch_positive, times_switch_negative,
           (double)(times_switch_positive) / (double)times_game * 100);
    return 0;
}