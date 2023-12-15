#include <stdio.h>

void print_score(int score, int td_2pt, int td_fg, int td, int fg, int safety) {
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_2pt, td_fg, td, fg, safety);
}

void calculate_score(int score) {
    for (int td_2pt = 0; td_2pt <= score / 8; td_2pt++) {
        for (int td_fg = 0; td_fg <= (score - td_2pt * 8) / 7; td_fg++) {
            for (int td = 0; td <= (score - td_2pt * 8 - td_fg * 7) / 6; td++) {
                for (int fg = 0; fg <= (score - td_2pt * 8 - td_fg * 7 - td * 6) / 3; fg++) {
                    int safety = (score - td_2pt * 8 - td_fg * 7 - td * 6 - fg * 3) / 2;
                    if (td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2 == score)
                        print_score(score, td_2pt, td_fg, td, fg, safety);
                }
            }
        }
    }
}

int main() {
    int score;
    do {
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &score);
        if (score > 1) {
            printf("Possible combinations of scoring plays:\n");
            calculate_score(score);
        }
    } while (score > 1);
    return 0;
}
