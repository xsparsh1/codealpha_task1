#include<bits/stdc++.h>
using namespace std;

int convertgradepoints(int mark)
{
    if(mark>=90) return 10;
    else if(mark>=80) return 9;
    else if(mark>=70) return 8;
    else if(mark>=60) return 7;
    else if(mark>=50) return 6;
    else if(mark>=40) return 5;
    else return 0;
}
string getgrade(float marks)
 {
    if(marks>=90) return "A+";
    else if(marks>=80) return "A";
    else if(marks>=70) return "B";
    else if(marks>=60) return "C";
    else if(marks>=50) return "D";
    else return "F";
 }

int main()
{
    int ncourse;
    float totalgpoints=0;
    int ncomp;
    float totalcredits=0;

    cout<<"Calculate your CGPA\nEnter the number of courses: \n";
    cin>>ncourse;
    for(int i=1;i<=ncourse;i++)
    {
        cout<<"\n"<<i<<". Course No. "<<i<<"\n";
        float credit;
        cout<<"Enter Credit for this course:\n";
        cin>>credit;
        cout<<"Enter Number of Components e.g - 3 (assignments, mid-term, final) :\n";
        cin>>ncomp;
        float overallgrade=0,total=0;
        for(int k=1;k<=ncomp;k++){
                float mark,weight;
            cout<< "Enter mark and weightage of component "<<k<<"\nMarks: ";
            cin>>mark;
            cout<<"Weightage: ";
            cin>>weight;cout<<"\n";
            overallgrade+=mark*(weight/100);
            total+=weight;
        }
        if (total!=100.0) {
            cout << "Total weight for course is not 100%, please check your input.\n";
            return 1;
        }

        int gp=convertgradepoints(overallgrade);
        string grade=getgrade(overallgrade);
        totalgpoints+=gp*credit;
        totalcredits+=credit;

        cout<<"Course "<<i<<" Average Marks :"<<overallgrade;
        cout<<"\nGrade points :"<<gp;
        cout<<"\nLetter Grade :"<<grade<<"\n";
    }
    float cgpa = totalgpoints / totalcredits;
    cout << "\nYour final CGPA: " << cgpa<<"CGPA";
    return 0;
}
