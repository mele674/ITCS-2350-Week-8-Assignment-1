// ITCS 2350 Week 8 Assignment
// Marc Melendez
// any example usage or helpful command line arguments go here
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
// Add any other header files here

using namespace std;


const int Bowlers = 10;
const int TotalGames = 4;

class BowlingScores {
private:
    string filename;

    struct Bowler {
        string name;
        int scores[TotalGames];
        int average;
    };

    Bowler bowlers[Bowlers];

public:
    BowlingScores(const string& inputFile) {
        filename = inputFile;
    }


    bool readdata() {
        ifstream infile(filename);
        for (int i = 0; i < Bowlers; ++i) {
            if (!(infile >> bowlers[i].name)) return false;
            for (int j = 0; j < TotalGames; ++j) {
                if (!(infile >> bowlers[i].scores[j])) return false;
            }
        }
        infile.close();
        return true;
    }

    void calculateAverage() {
        for (int i = 0; i < Bowlers; ++i) {
            int sum = 0;

            for (int j = 0; j < TotalGames; ++j) {
                sum += bowlers[i].scores[j];
            }
            bowlers[i].average = (sum) / TotalGames;
        }
    }

    void printresults() {
        ofstream outfile("scores.dat");

        for (int i = 0; i < Bowlers; ++i) {
            cout << left << setfill('.') << setw(25) << bowlers[i].name;
            outfile << left << setfill('.') << setw(25) << bowlers[i].name;

            for (int j = 0; j < TotalGames; ++j) {
                cout << right << setfill('.') << setw(3) << bowlers[i].scores[j];
                cout << setfill('.') << setw(7) << "";
                outfile << right << setfill('.') << setw(3) << bowlers[i].scores[j];
                outfile << setfill('.') << setw(7) << "";
            }
            cout << fixed << setprecision(2) << setw(8) << bowlers[i].average << endl;
            outfile << fixed << setprecision(2) << setw(8) << bowlers[i].average << endl;
        }
        outfile.close();
    }
};

int main()
{
    BowlingScores bowling("Bowlingscores.txt");

    if (!bowling.readdata()) {
        return 1;
    }
    bowling.calculateAverage();
    bowling.printresults();

    // Return 0 to indicate sucess
    return 0;
}


// Place any unused code here so that the instructor can follow your problem solving thoughts.