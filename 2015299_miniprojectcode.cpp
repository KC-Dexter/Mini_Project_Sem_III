


//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
//                           G E U                              <>
//                  3RD SEMESTER MINI PROJECT                   <>
//                  PAYROLL MANAGEMENT SYSTEM                   <>
//                                                              <>
//                                                              <>
//Submitted By:-                                                <>
//Name : Kartavya Chauhan                                       <>
//University Roll No. : 2015299                                 <>
//Course : B.Tech (CSE)                                         <>
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>



//CODE:-



//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
//                     USE OF HEADER FILE                       <>
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<iomanip>
using namespace std;


//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
//                        USE OF CLASS                          <>
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

class loginManager
{
public:
    string userNameAttempt;
    string passwordAttempt;
    loginManager()
    {
        accessGranted = 0;
    }
    void login()
    {
        cout<<"\n\n\n\t\tEnter your Credentials:- \n\n\n\t\tUsername : ";
        cin>>userNameAttempt;
        if(userNameAttempt==userName)
        {
            cout<<"\n\t\tPassword : ";
            cin>>passwordAttempt;
            if(passwordAttempt==passWord)
            {
                cout<<"\n\n\t\tAccess Granted!\n\n\n\n\n";
                system ("PAUSE");
                system("cls");
            }
            else
            {
                cout<<"Access Denied!\n\n\n\n\n";
                exit( 1 );

            }
        }
        else
        {
            cout<<"Access Denied!\n\n\n\n\n";
            exit(1);
        }
    }
private:
    string passWord="Key";
    string userName="Demo";
    bool accessGranted;

};



//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
//                 DECLARING ANOTHER CLASS                      <>
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

class employee
{
    string name,dept,desig;
    int id,age;
    long int basicPay,medicalReimbursement=1500,otherAllowance,npay;

public:
    void getdata()
    {
        cout<<"\t\tEnter Details:-";
        cout<<"\n\t\tName: ";
        cin>>name;
        cout<<"\t\tId: ";
        cin>>id;
        cout<<"\t\tAge: ";
        cin>>age;
        cout<<"\t\tDepartment: ";
        cin>>dept;
        cout<<"\t\tDesignation: ";
        cin>>desig;
        cout<<"\n\t\tEnter Pay Data:-";
        cout<<"\n\t\tBasic Pay: ";
        cin>>basicPay;
        cout<<"\n\t\tHouse Rent Allowance(50% of basic pay): ";
        cout<<(basicPay/2);
        cout<<"\n\t\tConveyance Allownance(10% of basic pay): ";
        cout<<(basicPay/10);
        cout<<"\n\t\tMedical Reimbursement: ";
        cout<<medicalReimbursement;
        cout<<"\n\t\tOther Allownances: ";
        cin>>otherAllowance;
        npay=basicPay+(basicPay/2)+(basicPay/10)+otherAllowance;
    }

    void showdata()
    {
        long int npay;
        npay=basicPay+(basicPay/2)+(basicPay/10)+otherAllowance;
        cout<<"\n\t\tId of the Employee : "<<id;
        cout<<"\n\t\tName of Employee : "<<name;
        cout<<"\n\t\tAge : "<<age;
        cout<<"\n\t\tDepartment : "<<dept;
        cout<<"\n\t\tDesignation : "<<desig;
        cout<<"\n\t\tBasic Pay : "<<basicPay;
        cout<<"\n\t\tConveyence Allowance :"<<(basicPay/2);
        cout<<"\n\t\tHouse Rent Allowance: "<<(basicPay/10);
        cout<<"\n\t\tMedical Reimbursement :"<<medicalReimbursement;
        cout<<"\n\t\tOther Allownances :"<<otherAllowance;
        cout<<"\n\t\tNet Pay: "<<npay;
    }

    void showpayData()
    {
        cout<<id<<setw(8)<<name<<setw(9)<<age<<setw(9)<<dept<<setw(10)<<desig<<setw(10)<<basicPay+(basicPay/2)+(basicPay/10)+otherAllowance<<endl;
    }

    int  returnId()
    {
        return id;
    }

};


//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
//             USE OF FSTREAM & DECLARING OBJECTS               <>
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

fstream fe;
employee ep;


//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
//            FUNCTION TO STORE DATA IN .DAT FILE               <>
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

void storeEmployee()
{
    fe.open("employee.dat",ios::out|ios::app);
    ep.getdata();
    fe.write((char*)&ep,sizeof(employee));
    fe.close();
    cout<<"\n\nEmployee record has been created!!! ";
    getch();
}


//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
//        FUNCTION TO DISPLAY ALL RECORDS FROM .DAT FILE        <>
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>


void displayEmp()
{
    system("cls");
    cout<<"\n\n\t\tDISPLAYING ALL RECORDS:- \n\n";
    fe.open("employee.dat",ios::in);
    while(fe.read((char*)&ep,sizeof(employee)))
    {
        ep.showdata();
        cout<<"\n\t\t<><><><><><><><><><><><><><><><><><><>\n";
    }
    fe.close();
    getch();
}


//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
//        FUNCTION FOR SEARCHING RECORD FROM .DAT FILE          <>
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

void searchEmp(int n)
{
    int flag=0;
    fe.open("employee.dat",ios::in);
    while(fe.read((char*)&ep,sizeof(employee)))
    {
        if(ep.returnId()==n)
        {
            system("cls");
            ep.showdata();
            flag=1;
        }
    }
    fe.close();
    if(flag==0)
        cout<<"\n\nRecord doesn't exist!!!";
    getch();
}


//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
//              FUNCTION FOR MODIFYING RECORDS                  <>
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

void modifyEmployee()
{
    int num,found=0;
    system("cls");
    cout<<"\n\n\tModify Record:- ";
    cout<<"\n\n\tPlease Enter The Id of Employee : ";
    cin>>num;
    fe.open("employee.dat",ios::in|ios::out);
    while(fe.read((char*)&ep,sizeof(employee)) && found==0)
    {
        if(ep.returnId()==num)
        {
            ep.showdata();
            cout<<"\n\n\t\tPlease Enter The New Details of Employee:- "<<endl;
            ep.getdata();
            int pos=-1*sizeof(ep);
            fe.seekp(pos,ios::cur);
            fe.write((char*)&ep,sizeof(employee));
            cout<<"\n\n\t\t Record Updated!!!";
            found=1;
        }
    }
    fe.close();
    if(found==0)
        cout<<"\n\n Record Not Found!!!";
    getch();
}


//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
//                FUNCTION TO DELETE RECORD                     <>
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

void deleteEmployee()
{
    int num;
    system("cls");
    cout<<"\n\n\tDelete Record:- ";
    cout<<"\n\n\tPlease Enter The Id of Employee : ";
    cin>>num;
    fe.open("employee.dat",ios::in|ios::out);
    fstream fe2;
    fe2.open("Temp.dat",ios::out);
    fe.seekg(0,ios::beg);
    while(fe.read((char*)&ep,sizeof(employee)))
    {
        if(ep.returnId()!=num)
        {
            fe2.write((char*)&ep,sizeof(employee));
        }
    }
    fe2.close();
    fe.close();
    remove("employee.dat");
    rename("Temp.dat","employee.dat");
    cout<<"\n\n\tRecord Deleted!!!";
    getch();
}


//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
//         FUNCTION TO DISPLAY ALL EMPLOYEE PAYDATA             <>
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

void payData()
{
    system("cls");
    fe.open("employee.dat",ios::in);
    if(!fe)
    {
        cout<<"ERROR!!!\n\n\n Go To Entry Menu to create File";
        cout<<"\n\n\n Exiting...";
        getch();
        exit(0);
    }
    cout<<"\n\n\t\tDISPLAYING ALL EMPLOYEE PAY DATA:- \n\n";
    cout<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
    cout<<"<>ID     NAME       AGE    DEPT.    DESIG.    NETPAY  <> \n";
    cout<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";

    while(fe.read((char*)&ep,sizeof(employee)))
    {
        ep.showpayData();
    }
    fe.close();
    getch();
}


//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
//                    MAIN MENU FUNCTION                        <>
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

void mainMenu()
{
    system("cls");
    char ch2;
    cout<<"\n\n\n\tMAIN MENU:-";
    cout<<"\n\n\t1. Add Employee Data";
    cout<<"\n\n\t2. Display All Employee Records";
    cout<<"\n\n\t3. Search Employee Record ";
    cout<<"\n\n\t4. Modify Employee Data";
    cout<<"\n\n\t5. Delete Employee Data";
    cout<<"\n\n\t6. Display Pay Data";
    cout<<"\n\n\t7. <---Back to Previous Menu";
    cout<<"\n\n\tPlease Enter Your Choice (1-7) ";
    ch2=getche();
    switch(ch2)
    {
    case '1':
        system("cls");
        storeEmployee();
        break;
    case '2':
        displayEmp();
        break;
    case '3':
        int num;
       system("cls");
        cout<<"\n\n\tPlease Enter The Id ";
        cin>>num;
        searchEmp(num);
        break;
    case '4':
        modifyEmployee();
        break;
    case '5':
        deleteEmployee();
        break;
    case '6':
        payData();
        break;
    case '7':
        break;
    default:
        cout<<"\a";
        mainMenu();
    }
}


//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
//                THE MAIN FUNCTION OF PROGRAM                  <>
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

int main()
{
    loginManager lobj;
    lobj.login();

    char ch;
    do
    {
        system("cls");
        cout<<"\n\n\n\t<><><><><><><><><><><><><><><><><><><><><>";
        cout<<"\n\t<>             WELOCME                  <>";
        cout<<"\n\t<>                TO                    <>";
        cout<<"\n\t<>         PAYROLL MANAGER              <>";
        cout<<"\n\t<><><><><><><><><><><><><><><><><><><><><>";
        cout<<"\n\n\n\t1. ENTER MAIN MENU";
        cout<<"\n\n\t2. EXIT";
        cout<<"\n\n\tPlease Select Your Option (1-2) ";
        ch=getche();
        switch(ch)
        {
        case '1':
            mainMenu();
            break;
        case '2':
            exit(0);
        default :
            cout<<"\a";
        }
    }
    while(ch!='2');
}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
//                           THE END                            <>
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
