#include<iostream>
#include<string>
using namespace std;

struct Student{
    string name;
    int rollno;
    float marks;
    Student* next;
};
Student* head=NULL;

void addStudent()
{
   Student* newStudent = new Student();
   cout<<"enter student name :";
   cin.ignore();
   getline(cin,newStudent->name);
   cout<<"Enter roll no: ";
   cin>>newStudent->rollno;
   cout<<"enter marks: ";
   cin>>newStudent->marks;
   newStudent->next=NULL;
   if(head==NULL){
    head=newStudent;
   }else{
    Student* temp=head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next=newStudent;
}
cout<<"STUDENT ADDED SUCCESSFULLY!\n";
}
void DisplayStudents(){
    if(head==NULL){
        cout<<"no student record found";
        return;
    }else{
        Student* temp=head;
        cout<<"\n Student Records :\n";
        while(temp!=NULL){
            cout<<"roll no:"<<temp->rollno <<endl<<"name:\n"<<temp->name<<endl<<"marks:\n"<<temp->marks;
            temp=temp->next;

        }

    }
}
    void searchStudent(){
        if(head==NULL){

            cout<<"no student records found \n";
            return;

        }
        int roll;
        cout<<"enter the roll number ro Serch :";
        cin>>roll;
        Student* temp = head;
        while(temp!=NULL){
            if(temp->rollno==roll){
                cout<<"STUDENT FOUND:"<<endl;
                cout<<"Roll no:"<<temp->rollno<<"name:"<<temp->name<<"marks:"<<temp->marks<<endl;
                return;
            }
            temp=temp->next;
        }
        cout<<"STUDENT NOT FOUND";
    }
    void deleteStudent(){
        if(head==NULL){
            cout<<"no student record found:";
            return;

        }
        int roll;
        cout<<" Enter the roll number :";
        cin>>roll;
        Student* temp=head;
        Student* prev=NULL;
        if(temp!=NULL && temp->rollno==roll){
            head = temp->next;
            delete temp;
        cout<<"student deleted successfully.\n";
        return;
    }
    while(temp!=NULL && temp->rollno!=roll){
        prev=temp;
        temp->next;
    }
    if(temp==NULL){
        cout<<"Student not found.\n";
        return;
    }
    prev->next=temp->next;
    delete temp;
    cout<<"student deleted successfully.\n";
}
int main(){
    int choice;
    do{
        cout<<"\n --- STUDENT RECORD MANAGEMENT SYSTEM ---\n";
        cout<<"1. ADD STUDENT\n";
        cout<<"2. DISPLAY ALL STUDENTS\n";
        cout<<"3. Search Student\n";
        cout<<"4. Delete Student\n";
        cout<<"5. exit\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice){
            case 1: addStudent();break;
            case 2: DisplayStudents();break;
            case 3: searchStudent();break;
            case 4: deleteStudent();break;
            case 5: cout<< "Existing Program. GOODBYE!\n";break;
            default:cout<<"INVALID CHOICE. Please Try Again.\n";
        }
     } while(choice!=5);
        return 0;

        
        }
        
        
    




   








