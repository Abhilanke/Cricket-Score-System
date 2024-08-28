#include <stdio.h>

#define MAX_PLAYERS 11

typedef struct {
    char name[50];
    int runs;
    int wickets;
} Player;

typedef struct {
    Player players[MAX_PLAYERS];
    int total_runs;
    int total_wickets;
    int overs;
} Team;

void initializeTeam(Team *team) {
    team->total_runs = 0;
    team->total_wickets = 0;
    team->overs = 0;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        team->players[i].runs = 0;
        team->players[i].wickets = 0;
    }
}

void inputScores(Team *team) {
    int numPlayers;
    printf("Enter the number of players in the team (max %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter player %d name: ", i + 1);
        scanf("%s", team->players[i].name);

        printf("Enter runs scored by %s: ", team->players[i].name);
        scanf("%d", &team->players[i].runs);
        team->total_runs += team->players[i].runs;

        printf("Enter wickets taken by %s: ", team->players[i].name);
        scanf("%d", &team->players[i].wickets);
        team->total_wickets += team->players[i].wickets;
    }

    printf("Enter total overs bowled: ");
    scanf("%d", &team->overs);
}

void displayStatistics(Team *team) {
    printf("\n--- Match Statistics ---\n");
    printf("Total Runs: %d\n", team->total_runs);
    printf("Total Wickets: %d\n", team->total_wickets);
    printf("Total Overs: %d\n", team->overs);

    printf("\nPlayer Performance:\n");
    for (int i = 0; i < MAX_PLAYERS && team->players[i].runs != 0; i++) {
        printf("%s: Runs = %d, Wickets = %d\n", team->players[i].name, team->players[i].runs, team->players[i].wickets);
    }
}

int main() {
    Team team;
    initializeTeam(&team);

    printf("Cricket Score System\n");
    inputScores(&team);
    displayStatistics(&team);

    return 0;
}
