#include <iostream>
#include <string>
using namespace std;

const int NUM_TEAMS = 16;
const int NUM_GAMES = 15;

struct MatchResult {
    int scored;
    int conceded;
};

struct TeamStats {
    string name;
    int wins;
    int draws;
    int losses;
    int total_points;
};

int main() {
    string team_names[NUM_TEAMS] = {
        "Динамо", "Шахтар", "Зоря", "Дніпро-1", "Ворскла", "Олександрія", 
        "Колос", "Рух", "Полісся", "Кривбас", "ЛНЗ", "Оболонь", 
        "Металіст", "Минай", "Верес", "Чорноморець"
    };

    MatchResult tournament_matrix[NUM_TEAMS][NUM_GAMES];

    for (int i = 0; i < NUM_TEAMS; ++i) {
        for (int j = 0; j < NUM_GAMES; ++j) {
            tournament_matrix[i][j].scored = (i + j) % 4;
            tournament_matrix[i][j].conceded = (i * j) % 4;
        }
    }

    cout << "=== 1) Таблиця результатів ігор ===" << endl;
    cout << "Команда\t\t| Результати ігор" << endl;
    cout << "--------------------------------------------------" << endl;
    for (int i = 0; i < NUM_TEAMS; ++i) {
        cout << team_names[i] << "\t| ";
        if (team_names[i].length() < 8) cout << "\t"; 
        for (int j = 0; j < NUM_GAMES; ++j) {
            cout << tournament_matrix[i][j].scored << ":" << tournament_matrix[i][j].conceded << " ";
        }
        cout << endl;
    }
    cout << endl;

    int total_draws = 0;
    for (int i = 0; i < NUM_TEAMS; ++i) {
        for (int j = 0; j < NUM_GAMES; ++j) {
            if (tournament_matrix[i][j].scored == tournament_matrix[i][j].conceded) {
                total_draws++;
            }
        }
    }
    cout << "=== 2) Кількість нічиїх у всьому турнірі: " << total_draws / 2 << endl << endl;

    int big_difference_matches = 0;
    for (int i = 0; i < NUM_TEAMS; ++i) {
        for (int j = 0; j < NUM_GAMES; ++j) {
            int diff = tournament_matrix[i][j].scored - tournament_matrix[i][j].conceded;
            if (diff >= 3 || diff <= -3) {
                big_difference_matches++;
            }
        }
    }
    cout << "=== 3) Кількість ігор з різницею м'ячів >= 3: " << big_difference_matches / 2 << endl << endl;

    TeamStats stats[NUM_TEAMS];
    for (int i = 0; i < NUM_TEAMS; ++i) {
        stats[i].name = team_names[i];
        stats[i].wins = 0;
        stats[i].draws = 0;
        stats[i].losses = 0;
        stats[i].total_points = 0;

        for (int j = 0; j < NUM_GAMES; ++j) {
            int s = tournament_matrix[i][j].scored;
            int c = tournament_matrix[i][j].conceded;

            if (s > c) {
                stats[i].wins++;
                stats[i].total_points += 3;
            } else if (s == c) {
                stats[i].draws++;
                stats[i].total_points += 1;
            } else {
                stats[i].losses++;
            }
        }
    }

    cout << "=== 4) та 5) Статистика команд та набрані очки ===" << endl;
    cout << "Команда\t\t| В\t| Н\t| П\t| Очки" << endl;
    cout << "----------------------------------------------" << endl;
    for (int i = 0; i < NUM_TEAMS; ++i) {
        cout << stats[i].name << "\t| " 
             << stats[i].wins << "\t| " 
             << stats[i].draws << "\t| " 
             << stats[i].losses << "\t| " 
             << stats[i].total_points << endl;
    }
    cout << endl;

    int champ_idx = 0;
    for (int i = 1; i < NUM_TEAMS; ++i) {
        if (stats[i].total_points > stats[champ_idx].total_points) {
            champ_idx = i;
        }
    }

    cout << "=== 6) Чемпіон турніру ===" << endl;
    cout << "Команда \"" << stats[champ_idx].name << "\" стала чемпіоном з рахунком " 
         << stats[champ_idx].total_points << " очок!" << endl;

    return 0;
}
