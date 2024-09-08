#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CHOICE_KEEP 0
#define CHOICE_SWITCH 1

int main() {
    srand(time(NULL));
    unsigned int total_keep_wins = 0;
    unsigned int total_switch_wins = 0;
    for (int j = 0; j < 100000; j++) {
        unsigned int choices_made[2] = {0};
        for (int k = 0; k < 1000; k++) {
            // Choice by showman
            unsigned int door_showman_choice = rand() % 3;
            unsigned int door_prize;
            // Looking for door to put prize behind randomly
            while (true) {
                door_prize = rand() % 3;
                if (door_prize == door_showman_choice) {
                    // Invalid choice, try again
                    continue;
                }
                // Found valid door to put prize behind
                break;
            }
            // Your first door choice
            unsigned int door_first_choice = 0;
            while (true) {
                door_first_choice = rand() % 3;
                if (door_first_choice != door_showman_choice) {
                    // Made a valid choice, not the showman door
                    break;
                }
            }
            // Decide if you'll switch
            bool do_switch = rand() % 2;
            // You've won if the switch value doesn't equal your choice
            bool won = do_switch != (door_first_choice == door_prize);
            choices_made[do_switch] += won;
        }
        if (choices_made[CHOICE_SWITCH] == choices_made[CHOICE_KEEP]) {
            continue;
        }
        printf("Win switch: %d, win keep: %d: %s\n",
               choices_made[CHOICE_SWITCH], choices_made[CHOICE_KEEP],
               choices_made[CHOICE_SWITCH] > choices_made[CHOICE_KEEP]
                   ? "switch won"
                   : "keep won");

        if (choices_made[CHOICE_SWITCH] > choices_made[CHOICE_KEEP]) {
            total_switch_wins++;
        } else {
            total_keep_wins++;
        }
    }
    printf("Switch wins :%d Keep wins: %d\n", total_switch_wins,
           total_keep_wins);
    printf("Conclusion: %s by a margin of %d/%d times.\n",
           total_switch_wins > total_keep_wins ? "switching is best choice"
                                               : "keeping is best choice",
           total_switch_wins > total_keep_wins
               ? total_switch_wins - total_keep_wins
               : total_keep_wins - total_switch_wins,
           total_switch_wins + total_keep_wins);
}