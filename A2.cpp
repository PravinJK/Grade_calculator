#include<iostream>
#include<string.h>
using namespace std;
int counter=1;
class student 
{		protected:
	    string student_name;
		int roll_number;
        public:
		void print()
		{
		cout<<"\nStudent name : "<<student_name<<endl;
		cout<<"Roll_no :"<<roll_number<<endl;
		}
	
};
class T1:virtual public student
{		protected:
	int T1_marks;
     public:
	void print1()
	{
		cout<<"T1 marks : "<<T1_marks<<endl;
	}
};
class T2:virtual protected student
{		protected:
	int T2_marks;
     public:
	void print2()
	{
		cout<<"T2 marks : "<<T2_marks<<endl;
	}

};
class T3:virtual protected student
{		protected:
	int T3_marks;
     public:
	void print3()
	{
		cout<<"T3 marks : "<<T3_marks<<endl;
	}
	
};
class P1:virtual protected student
{		protected:
	int P1_marks;
     public:
	void print4()
	{
		cout<<"P1 marks :"<<P1_marks<<endl;
	}

};
class P2:virtual protected student
{		protected:
	int P2_marks;
     public:
	void print5()
	{
		cout<<"P2 marks :"<<P2_marks<<endl;
	}

};
class attendance:virtual protected student
{	protected:
	float attendance_percentage;
    public:
	void print6()
	{
		cout<<"Attendace percentage :"<<attendance_percentage<<endl;
	}
	
};
class total:public T1, public T2, public T3, public P1, public P2, public attendance
{		protected:
	int total_marks;
	char grade;
    public:
	void print7()
	{
		cout<<"Total marks : "<<total_marks<<endl<<"Grade : "<<grade<<endl;
	}
	friend class faculty;
	friend class administration;
    friend void fun1(total t[], int n);
    friend void fun2(total t[], int n);
    friend bool compare(total&,total&);
    friend bool compare1(total&t1,total&t2);
    friend void fun3(total t[], int n, string a);
};
class faculty
{	public:
	static void assign(total& ob)
	{	
		cout<<"Enter marks of T1 of student "<<counter<<":"<<endl;
		cin>>ob.T1_marks;
		cout<<"Enter marks of T2 of student "<<counter<<":"<<endl;
		cin>>ob.T2_marks;
		cout<<"Enter marks of T3 of student "<<counter<<":"<<endl;
		cin>>ob.T3_marks;
		cout<<"Enter marks of P1 of student "<<counter<<":"<<endl;
		cin>>ob.P1_marks;
		cout<<"Enter marks of P2 of student "<<counter<<":"<<endl;
		cin>>ob.P2_marks;
		cout<<"Enter attendacne percentage of student "<<counter<<":"<<endl;
		cin>>ob.attendance_percentage;
		}
};
class administration
{	public:
	static void take(total& ob)
	{
		cout<<"Enter name of student "<<counter<<":"<<endl;
		cin.ignore();
		getline(cin,ob.student_name);
        cout<<"Enter roll_number of student "<<counter<<":"<<endl;
        cin>>ob.roll_number;
	}
    static int tmarks(total&ob)
    {
        ob.total_marks=(ob.T1_marks+ob.T2_marks+ob.T3_marks+ob.P1_marks+ob.P2_marks);
        if(ob.attendance_percentage>=90)
            ob.total_marks+=5;
        if(ob.attendance_percentage>=88 && ob.attendance_percentage<=89)
            ob.total_marks+=4;
        if(ob.attendance_percentage>=86 && ob.attendance_percentage<=87)
            ob.total_marks+=3;
        if(ob.attendance_percentage>=84 && ob.attendance_percentage<=85)
            ob.total_marks+=2;
        if(ob.attendance_percentage>=81 && ob.attendance_percentage<=83)
            ob.total_marks+=1;
            return ob.total_marks;
    }
    static char grade(total&ob)
    {
        
        ob.total_marks=(ob.T1_marks+ob.T2_marks+ob.T3_marks+ob.P1_marks+ob.P2_marks);
        if(ob.attendance_percentage>=90)
            ob.total_marks+=5;
        if(ob.attendance_percentage>=88 && ob.attendance_percentage<=89)
            ob.total_marks+=4;
        if(ob.attendance_percentage>=86 && ob.attendance_percentage<=87)
            ob.total_marks+=3;
        if(ob.attendance_percentage>=84 && ob.attendance_percentage<=85)
            ob.total_marks+=2;
        if(ob.attendance_percentage>=81 && ob.attendance_percentage<=83)
            ob.total_marks+=1;
        if(ob.total_marks>80)
            ob.grade='A';
        if(ob.total_marks>70 && ob.total_marks<=80)
            ob.grade='B';
        if(ob.total_marks>60 && ob.total_marks<=70)
            ob.grade='C';
        if(ob.total_marks>50 && ob.total_marks<=60)
            ob.grade='D';
        if(ob.total_marks<50)
            ob.grade='F';
            return ob.grade;
        }
        // friend void fun1(total&);
};
bool compare(total&t1, total&t2)
{
        if(t1.grade!=t2.grade)
        return t1.grade>t2.grade;
        // if(t1.grade==t2.grade)
        return t1.student_name<t2.student_name;
}
bool compare1(total&t1,total&t2)
{
    return t1.student_name<t2.student_name;
}
void fun1(total t[], int n)
{   
    sort(t, t+n , compare);
    cout << "Name"
         << "\t\t";
    cout << "Grade\n";
    // Display details of Students
    for (int i = 0; i < n; i++) {
        cout << t[i].student_name<< "\t\t";
        cout << t[i].grade;
        cout << "\n";
    }
}
void fun2(total t[], int n)
{   
    sort(t, t+n , compare1);
    cout << "Name"
         << "\t\t";
    cout << "Grade\n";
    // Display details of Students
    for (int i = 0; i < n; i++) {
        cout << t[i].student_name<< "\t\t";
        cout << t[i].grade;
        cout << "\n";
    }
}
void fun3(total t[], int n, string a)
{
        cout << "Name"
         << "\t\t";
    cout << "Roll_number"
         <<"\t\t";
    cout <<"Grade\n";
    // Display details of Students
        int i,j,l;
        l=a.length();
        while(n--)
    {
        for(i=0; i<1 ; i++ )
        {
            for(j=0; a[j]!=NULL; j++)
            {
                if(t[n].student_name[i+j]!=a[j])
                {
                    break;
                }
            }
            if(j==l && (t[n].student_name[l]==' ' || t[n].student_name[l]==NULL))
            {
                cout << t[n].student_name<< "\t\t";
                cout << t[n].roll_number <<"\t\t";
                cout << t[n].grade<<"\n";
                // cout << "\n";
            }
        }
     }
}
int main()
{   
    cout<<"Enter the number of student : "<<endl;
    int n,size_of_array;
    cin>>n;
    total t[n];
    size_of_array=sizeof(t)/sizeof(t[0]);
    //cout<<"size of array is"<<size_of_array<<endl;
    for(int i=0; i<n ; i++)
    {
        administration::take(t[i]);
        faculty::assign(t[i]);
        counter++;
        administration::grade(t[i]);
    }
    for(int i=0; i< n ; i++)
    {
        t[i].print();
        t[i].print1();
        t[i].print2();
        t[i].print3();
        t[i].print4();
        t[i].print5();
        t[i].print6();
        t[i].print7();
    }
    cout<<"\n------ GRADES IN ASCENDING ORDER WITH NAMES ------ \n"<<endl;
    fun1(t,size_of_array); //printing grades in ascending order with names
    cout<<"\n------ NAME IN APLHABETICAL ORDER WITH GRADES ------ \n"<<endl;
    fun2(t,size_of_array); //printing name in aplhabetical order with grades
    cout<<"Enter the first name of the student to search grades : "<<endl;
    string name;
    cin.ignore();
    getline(cin,name);
    cout<<"\n------ GRADES WITH ROLL_NUMBER OF THE STUDENTS MATCHING THE GIVEN FIRST NAME ------ \n"<<endl;
    fun3(t,size_of_array,name);
	return 0;
}


