#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include<algorithm>
#include<limits>
using namespace std;
int main()
{
    float grade;
    string name;
    string Apluse = "A+";
    string Apluse_ = "a+";
    string A = "A";
    string A_ = "a";
    string Amin = "A-";
    string Amin_ = "a-";
    string Bplus = "B+";
    string Bplus_ = "b+";
    string B = "B";
    string B_ = "b";
    string Bmin = "B-";
    string Bmin_ = "b-";
    string Cpluse = "C+";
    string Cpluse_ = "c+";
    string C = "C";
    string C_ = "c";
    string Cmin = "C-";
    string Cmin_ = "c-";
    vector<tuple<string, int, string>> vec;
    int num_courses;
    cout << "Enter number of courses: ";
    cin >> num_courses;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vec.resize(num_courses);
    int SumCreditHrs = 0;
    float what = 0;
    for (int i = 0; i < num_courses; ++i)
    {
        string name, grade;
        int hours;
        cout << "\nCourse " << i + 1 << ":\n";
        cout << "Enter course name: ";
        getline(cin, name);
        get<0>(vec[i]) = name;
        cout << "Enter number of hours: ";
        cin >> hours;
        get<1>(vec[i]) = hours;
        cout << "Enter grade: ";
        cin >> grade;
        get<2>(vec[i]) = grade;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        SumCreditHrs += hours;
        float numgrades = 0;
        if (grade == Apluse || grade == Apluse_)numgrades = 4;
        else if (grade == A || grade == A_) numgrades = 4;
        else if (grade == Amin || grade == Amin_) numgrades = 3.7;
        else if (grade == Bplus || grade == Bplus_) numgrades = 3.3;
        else if (grade == B || grade == B_) numgrades = 3;
        else if (grade == Bmin || grade == Bmin_) numgrades = 2.7;
        else if (grade == Cpluse || grade == Cpluse_) numgrades = 2.3;
        else if (grade == C || grade == C_) numgrades = 2;
        else if (grade == Cmin || grade == Cmin_) numgrades = 1.7;
        else { cout << "Warning: Invalid grade entered - counting as 0 points\n"; numgrades = 0; }
        cout << "Total credit points of this course = " << hours * numgrades << "\n";
        what += hours * numgrades;
    }
    cout << "\ntotal credit hours = " << SumCreditHrs << endl;
    cout << "\n\nYOUR CGPA = " << what / SumCreditHrs << "\n\n";
    return 0;
}