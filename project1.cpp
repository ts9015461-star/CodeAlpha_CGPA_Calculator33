#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    double grade, credits;
    double totalCredits = 0.0;
    double totalGradePoints = 0.0;

    double previousCGPA, previousCredits;
    double previousGradePoints;
    double semesterGPA, overallCGPA;

    cout << "=====================================\n";
    cout << "          CGPA CALCULATOR\n";
    cout << "=====================================\n";

    cout << "Enter your previous CGPA (0-10): ";
    cin >> previousCGPA;

    cout << "Enter your previous total credits: ";
    cin >> previousCredits;

    if (previousCGPA < 0 || previousCGPA > 10 || previousCredits < 0)
    {
        cout << "Invalid previous CGPA or credits.\n";
        return 1;
    }

    cout << "Enter the number of courses in this semester: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Number of courses must be greater than zero.\n";
        return 1;
    }

    // Convert previous CGPA into previous total grade points.
    previousGradePoints = previousCGPA * previousCredits;

    // Input details for each course.
    for (int i = 1; i <= n; i++)
    {
        cout << "\nEnter details for Course " << i << ":\n";

        cout << "Enter grade point (0-10): ";
        cin >> grade;

        cout << "Enter credit hours: ";
        cin >> credits;

        if (grade < 0 || grade > 10 || credits <= 0)
        {
            cout << "Invalid grade or credits. Please run the program again.\n";
            return 1;
        }

        totalCredits += credits;
        totalGradePoints += grade * credits;
    }

    // Semester GPA = total semester grade points / total semester credits.
    semesterGPA = totalGradePoints / totalCredits;

    // Overall CGPA = all grade points / all credits.
    overallCGPA = (previousGradePoints + totalGradePoints) /
                  (previousCredits + totalCredits);

    cout << fixed << setprecision(2);

    cout << "\n=====================================\n";
    cout << "         CGPA CALCULATION RESULT\n";
    cout << "=====================================\n";

    cout << "Total Semester Credits: " << totalCredits << '\n';
    cout << "Total Semester Grade Points: " << totalGradePoints << '\n';
    cout << "Semester GPA: " << semesterGPA << '\n';
    cout << "Overall CGPA: " << overallCGPA << '\n';

    cout << "=====================================\n";

    return 0;
}
