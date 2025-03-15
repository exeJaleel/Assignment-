#include <iostream>
#include <iomanip>
using namespace std;

double calculateAverage(int scores[], int numScores) {
    double sum = 0;
    for (int i = 0; i < numScores; i++) {
        sum += scores[i];
    }
    return sum / numScores;
}
void displayResults(string names[], double averages[], char grades[], int numStudents) {
    cout << "\nResults:\n";
    cout << "--------------------------------\n";
    cout << left << setw(10) << "Student" << " | " << setw(8) << "Average" << " | " << "Grade" << endl;
    cout << "--------------------------------\n";
    
    for (int i = 0; i < numStudents; i++) {
        cout << left << setw(10) << names[i] << " | " << setw(8) << fixed << setprecision(2) << averages[i] << " | " << grades[i] << endl;
    }
    cout << "--------------------------------\n";
}

char determineGrade(double average) {
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else return 'F';
}


int main(){

   
int numStudents;

cout << "Enter the number of students: ";
cin >> numStudents;

string names[numStudents];
    double averages[numStudents];
    char grades[numStudents];

for (int i = 0; i < numStudents; i++){
    cout << "\nEnter name for student " << i + 1 << ": ";
     cin >> names[i];

int numScores;
cout << "Enter the number of test scores for " << names[i] << ": ";
cin >> numScores;

int scores[numScores];

for (int j = 0; j < numScores; j++){
    do{
        cout << "enter test score " << j + 1 << " (0-100): ";
        cin >> scores[j];

        if(scores[j] < 0 || scores[j] > 100 )
          cout << "Invalid score! Please enter a value between 0 and 100.\n";

            } while (scores[j] < 0 || scores[j] > 100);
        }

        // Calculate average and determine grade
        averages[i] = calculateAverage(scores, numScores);
        grades[i] = determineGrade(averages[i]);
    }

    // Display results using the given function
    displayResults(names, averages, grades, numStudents);

    return 0;
}
        

