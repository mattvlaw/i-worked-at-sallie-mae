//test test
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <utility>
#include <vector>

using namespace std;


//student class
class StudentTranscript{
private:
   string name;
   double credits;
   double cumulative;
       
   
   double convertGrade(char g)
{
switch(g)
{
case 'A':
case 'a':
return 4;
break;
case  'B':
case 'b':
return 3;
break;
case 'C':
case 'c':
return 2;
break;
case 'D':
case 'd':
return 1;
break;
case 'E':
case 'e':
return 0;
break;
}
}

public:
   StudentTranscript(){
name="nemo";
credits=0;
cumulative=0;
       
   }
   
   StudentTranscript(string nm){
       name = nm;
credits = 0;
cumulative = 0;
   }
   
   void insert(char grd, int crd){
       credits += crd;
       cumulative += (convertGrade(grd)*crd);

       

   }
   
   double getGPA(){
       return cumulative/credits;
   }
   
   string getName(){
       return name;
   }
   
};

int main()
{
   multimap<double, string> Students;
   int credits;
char grade, inner, outer;
   double GPA;
   string name;
   vector <StudentTranscript> Student;
   
   do{

       cout << "What is the Student's name? ";
       cin >> name;
       StudentTranscript temp(name);   
       
      do
  {
           cout << "How many credits is the class?" << endl;
           cin >> credits;
           
           cout << "What is the student's grade for the class?" << endl;
           cout << "Enter A, B, C, D or E" << endl;
           cin >> grade;
           
           temp.insert(grade,credits);
           
           
           cout << "Press n to quit or any other letter to enter another grade: ";
           cin >> inner;
           
       }while(inner!='n');
Student.push_back(temp);

       cout << "Press n to quit or any other letter to enter another student: ";
       cin >> outer;

}while(outer!='n'); 

   
   

for(int i=0; i<Student.size(); i++)
{
cout<<setprecision(2)<<fixed<<showpoint<<"\nStudent: "<<Student[i].getName()<<" GPA: "<<Student[i].getGPA();
}
   /////////////////Separating non-map part from map part
   
   //assignment Student elements to the map
//   for (int i = 0; i < Student.size(); i++){
//       Students.insert(pair<double, string>(Student[i].getGPA(), Student[i].getName()));        
//   }
//   
//   
//   cout << "Map size: " << Students.size() << endl << endl;
//   
//   cout << "What GPA do you want to search for? ";
//   cin >> GPA;
//   
//   if (Students.count(GPA)==1){
//       cout << Students.count(GPA) << " student has a GPA of " << GPA <<
//       fixed << showpoint << setprecision(2) << endl << endl; //if statement for grammar
//       
//   }
//   else{
//       cout << Students.count(GPA) << " students have a GPA of " <<
//       fixed << showpoint << setprecision(2) << GPA << endl << endl;
//   }
//   
//   cout << "Here are GPA's of students in chronological order: " << endl << endl;
//map<double, string>::iterator i;
//   for(i=Students.begin(); i!=Students.end(); ++i)
//   {
//       cout << fixed << showpoint << setprecision(2) << (*i).second << " has a GPA of: " << (*i).first << endl;
//   }

   
   system("pause");
   return 0;
}
