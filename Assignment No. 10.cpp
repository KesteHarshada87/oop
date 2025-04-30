#include<iostream>
#include<map>
#include<vector>
#include<numeric> 
#include<string>
using namespace std;

int main() {
    map<string,vector<int> >studentMarks;
    int choice;

    while (true) {
        cout<<"\n1.Add student record\n";
        cout<<"2.Display all student records\n";
        cout<<"3.Show topper\n";
        cout<<"4.Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        if(choice==1){
            string name;
            vector<int> marks(3);
            cout<<"Enter student name: ";
            cin>>name;

            cout<<"Enter 3 marks: ";
            for(int i=0;i<3;++i){
                cin>>marks[i];
            }

            studentMarks[name]=marks;

        } else if(choice==2){
            if(studentMarks.empty()){
                cout<<"No student records available.\n";
            } 
			else{
                for(map<string,vector<int> >::iterator it = studentMarks.begin(); it != studentMarks.end(); ++it) {
                    string name=it->first;
                    vector<int>marks=it->second;
                    int total=accumulate(marks.begin(),marks.end(),0);
                    float average=(float)total/marks.size();

                    cout<<"Student: "<<name<<",Marks: ";
                    for(int i=0; i<marks.size(); ++i) {
                        cout<<marks[i]<<" ";
                    }
                    cout<<", Average: "<<average<<endl;
                }
            }

        } else if(choice==3) {
            if(studentMarks.empty()) {
                cout<<"No student records available.\n";
            } else{
                string topper;
                float highestAvg=0.0;

                for(map<string,vector<int> >::iterator it=studentMarks.begin();it!=studentMarks.end();++it) {
                    string name=it->first;
                    vector<int> marks=it->second;
                    float avg=(float)accumulate(marks.begin(),marks.end(),0)/marks.size();

                    if(avg>highestAvg) {
                        highestAvg=avg;
                        topper=name;
                    }
                }

                cout<<"Topper: "<<topper<<" with average "<<highestAvg<<endl;
            }

        } else if(choice==4){
            cout<<"Exit"<<endl;
            break;
        } else{
            cout<<"Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

