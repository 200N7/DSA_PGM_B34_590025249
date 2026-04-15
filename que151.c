/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int n;
    scanf("%d", &n);

    char votes[MAX][50];
    int freq[MAX] = {0};
    int used[MAX] = {0};

    /* Input all votes */
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    /* Count frequency manually */
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;

        freq[i] = 1;
        used[i] = 1;

        for (int j = i + 1; j < n; j++) {
            if (strcmp(votes[i], votes[j]) == 0) {
                freq[i]++;
                used[j] = 1;
            }
        }
    }

    /* Find winner */
    char winner[50] = "";
    int maxVotes = 0;

    for (int i = 0; i < n; i++) {
        if (used[i]) {  // only unique names
            if (freq[i] > maxVotes) {
                maxVotes = freq[i];
                strcpy(winner, votes[i]);
            }
            else if (freq[i] == maxVotes) {
                if (strcmp(votes[i], winner) < 0) {
                    strcpy(winner, votes[i]);
                }
            }
        }
    }

    printf("%s %d", winner, maxVotes);

    return 0;
}