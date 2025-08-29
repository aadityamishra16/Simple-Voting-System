#include <stdio.h>
#include <string.h>

int main() {
    int num_candidates, total_votes, i, j, choice;
    
    printf("\n\t\tWelcome to the voting program. \n");
    printf("\n");
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    char candidates[num_candidates][50];
    int votes[num_candidates];           

    for (i = 0; i < num_candidates; i++) {
        votes[i] = 0;
    }

    printf("\nEnter the names of the candidates: \n");
    for (i = 0; i < num_candidates; i++) {
        printf("Candidate %d: ", i + 1);
        scanf("%s", candidates[i]);
    }

    printf("\nHow many voters are going to vote? ");
    scanf("%d", &total_votes);

    for (i = 1; i <= total_votes; i++) {
        printf("\n\t\tWelcome to the voting system (Voter %d)\n", i);
        for (j = 0; j < num_candidates; j++) {
            printf("Enter %d to vote for %s\n", j + 1, candidates[j]);
        }
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= num_candidates) {
            votes[choice - 1]++; 
        } else {
            printf("Invalid vote\n");
        }
    }

    printf("\n\t\tVoting Results: \n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s got %d votes\n", candidates[i], votes[i]);
    }

    int max_votes = votes[0];
    int winner_index = 0;
    int tie = 0;

    for (i = 1; i < num_candidates; i++) {
        if (votes[i] > max_votes) {
            max_votes = votes[i];
            winner_index = i;
            tie = 0;
        } else if (votes[i] == max_votes) {
            tie = 1;
        }
    }

    if (tie) {
        printf("\nThe voting result is tied.\n");
    } else {
        printf("\n%s wins the election with %d votes! Congratulations!\n", candidates[winner_index], max_votes);
    }

    printf("\nThe voting program has ended.\n");

    return 0;
}
