#include<iostream>
#include<iomanip>
#include<vector>
#include<stdlib.h>
using namespace std;

string acc_no[3] = {"12345678", "34235433", "54323446"};
string accno;
vector<string> tran;
vector<float> pay;
float pay1;
string tran1;
vector<string> date;
string date1;
float credlim1 = 100000;
int datemm;
int datedd;
int dateyyyy;
float prevbal;
float payment;
int d1;
int d2;



void ins() {
    float sum = 0;
    float sum1 = 0;
    int count = 3;
    int i;
        for (i=1; i<count; i++){
        cout << "Enter transaction " << i <<": ";
        cin >> tran1;
        cout << "Enter pay " << i <<": ";
        cin >> pay1;
        cout << "Enter date " << i <<": ";
        cin >> date1;
        pay.push_back(pay1);
        date.push_back(date1);
        tran.push_back(tran1);
    for (int n = 0; n < pay.size(); n++){
        sum1 += n;}
        if (sum1>credlim1) {
            cout << "max credit reached";
        }
        }
	string ans;
	cout<< "would you like to add more transactions? y/n?";
	cin>> ans;
	if (ans == "y"){
	int eto=2;
	cout<< "How many transactions will you enter?" << endl;
	cin >> eto;
	count=count+eto;
	
	for (i; i<count; i++){
        cout << "Enter transaction " << i <<": ";
        cin >> tran1;
        cout << "Enter pay " << i <<": ";
        cin >> pay1;
        pay.push_back(pay1);
        date.push_back(date1);
        tran.push_back(tran1);
        cout << "Enter date " << i <<": ";
        cin >> date1;
        for (int n = 0; n < pay.size(); n++)
        {
        sum1 += n;
        }
        if (sum1>credlim1) 
        {
            cout << "max credit reached";
        }
	}
	}
     for (int n : pay)
        sum = sum += n;
        cout << sum << endl;
    cout << endl;
    
        cout << "Previous Balance: ";
        cin >> prevbal;
        cout << "Paid payments: ";
        cin >> payment;

        
    
    float late_charge = 0;
    float fees_and_other_debit = 150;
    float Finance_charge = 0;
    float Out_bal = 0;
    float minimum_payments = 0;
    float Available_balance;
    float min_pay = 0;
    float interest_charge = 0.02;
    float interst1;
    float interst2;
    
    cout << "Date Today (mm/dd/yyyy) : "<< endl;
    cout << "Enter Month (mm): ";
     cin >> datemm;
     cout << "Enter Day (dd): ";
     cin >> datedd;
     cout << "Enter Year (yyyy): ";
     cin >> dateyyyy;
     cout << datemm<< "/" <<datedd<< "/" <<dateyyyy<<endl;
     
     int datemmn;
     int dateddn;
     int dateyyyyn;
     
     int monthdays[] = {31,28,31,30,31,30,31,31,30,31,30,31};   
                                        
        int addyears;    
        int leftoverdays; 
        int dd = 30;
        
datemmn = datemm;
dateddn = datedd;
dateyyyyn = dateyyyy;

        addyears = dd/365;
        leftoverdays = dd%365;

        dateyyyy += addyears;

        for (int i = 0; i <= leftoverdays; i++)
                if (datedd< monthdays [datemm -1])
                        datedd ++;
                else if ((datedd == monthdays [datemm-1]) && (datemm < 12))
                {
                        datedd = 1;
                        datemm++;
                }
                else if ((datedd == monthdays [datemm-1]) && (datemm == 12))
                {
                        datedd = 1;
                        datemm = 1;
                        dateyyyy ++;
                }
                else
                        cout << "Error setting date!";

    if (prevbal == payment){
        late_charge = 0;
        Finance_charge = 0;
        Out_bal = (sum+Finance_charge+fees_and_other_debit+late_charge+prevbal)- payment;
        min_pay = Out_bal*0.0357;
        if (min_pay<=850){
            min_pay=850;
        }
        else{
        min_pay = Out_bal*0.0357;
        Available_balance = credlim1-Out_bal;
        }
    }
    else {
        cout << "Number of days of payment from statement date to payment date: ";
        cin >> d1;
        cout << "Number of days of payment from payment date to billing date: ";
        cin >> d2;
        interst1 = ((prevbal*interest_charge)/30)*d1;
        interst2 = (((prevbal-payment)*(interest_charge))/30)*d2;
        Finance_charge = interst1+interst2;
        late_charge = prevbal*0.05;
        Out_bal = (prevbal+sum+Finance_charge+late_charge+fees_and_other_debit)-payment;
        min_pay = Out_bal*0.0357;
        if (min_pay<=850){
            min_pay=850;
        }
        else{
        min_pay = Out_bal*0.0357;
        Available_balance = credlim1-Out_bal;
        }
    }
    
        cout <<endl;
cout << setw (55) << "Credit Card Statement" << setw (55) << endl;
  cout << setw (80) << "BDO San Nicolas Manila" << endl;
  cout << "\nAccount name: " << "Mary Grace Gonzales" << setw (55) << "Date Issue: " <<
    datemmn<< "/" <<dateddn<< "/" <<dateyyyyn << endl;
  cout << "Account Address: " << "168 Tutuban Street Binondo, Malate" << endl;
  cout << "\nCard Information: " <<
    "Mastercard" << endl;
  cout << "Account Number: " << "12345678" << endl;
  cout << "Credit Limit: " << "100,000" << endl;
  cout << "Available Credit:" << Available_balance << endl;
  cout << "Statement Opening: " << datemmn<< "/" <<dateddn<< "/" <<dateyyyyn << " Closing Date: " << datemm<< "/" <<datedd<< "/" <<dateyyyy << endl;
  cout <<
    "______________________________________________________________________\n"
    << endl;
  cout << "Transactions" << endl;
  cout << setw (10) << "Date" << setw (30) << "Description" << setw (29) <<
    "Amount" << endl;
  cout << setw (70) << " _____________________________________________________________________" << endl;
  int f=1;
    for (int t = 0; t<pay.size(); t++){
  cout << "\n"<< f << "." << setw (10) << date[t] << setw (24) << tran[t] <<
    setw (31) << pay[t] << endl;
    f++;
    }
  cout <<
    "______________________________________________________________________\n"
    << endl;
  cout << setw (27) << "Summary of Transactions" << setw (38) <<
    "Payment Information" << endl;
  cout << "\n-Previous Balance ----- " << prevbal << setw (34) <<
    " Outstanding Balance ---- " << Out_bal << endl;
  cout << "-Payment -------------- " << setw (6) << payment << setw (34) <<
    " Minimum Payment -------- " << setw (5) << min_pay << endl;
  cout << "+Total Purchases ------ " << setw (6) << sum << setw (30) <<
    " Payment Due Date ------- " << setw (5) << datemm<< "/" <<datedd<< "/" <<dateyyyy << endl;
  cout << "+Finance Charges ------ " << setw (6) << Finance_charge << endl;
  cout << "+Interest Charges ----- " << setw (6) << "2%" << endl;
  cout << "+Late Charges ---------" << setw (6) << late_charge << endl;
  cout << "+Fees & Other Debit ----- " << setw (6) << fees_and_other_debit << endl;
  cout <<
    "\n______________________________________________________________________"
    << endl;
  cout << "\n " << endl;
  cout <<
    "\n  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  "
    << endl;
}

void ins2() {
    float sum = 0;
    float sum1 = 0;
    int count = 3;
    int i;
        for (i=1; i<count; i++){
        cout << "Enter transaction " << i <<": ";
        cin >> tran1;
        cout << "Enter pay " << i <<": ";
        cin >> pay1;
        cout << "Enter date " << i <<": ";
        cin >> date1;
        pay.push_back(pay1);
        date.push_back(date1);
        tran.push_back(tran1);
    for (int n = 0; n < pay.size(); n++){
        sum1 += n;}
        if (sum1>credlim1) {
            cout << "max credit reached";
        }
        }
	string ans;
	cout<< "would you like to add more transactions? y/n?";
	cin>> ans;
	if (ans == "y"){
	int eto=2;
	cout<< "How many transactions will you enter?" << endl;
	cin >> eto;
	count=count+eto;
	
	for (i; i<count; i++){
        cout << "Enter transaction " << i <<": ";
        cin >> tran1;
        cout << "Enter pay " << i <<": ";
        cin >> pay1;
        pay.push_back(pay1);
        date.push_back(date1);
        tran.push_back(tran1);
        cout << "Enter date " << i <<": ";
        cin >> date1;
        for (int n = 0; n < pay.size(); n++){
        sum1 += n;}
        if (sum1>credlim1) {
            cout << "max credit reached";
        }
	}
	}
     for (int n : pay)
        sum = sum += n;
        cout << sum << endl;
    cout << endl;
    
        cout << "Previous Balance: ";
        cin >> prevbal;
    cout << "Paid payments: ";
        cin >> payment;

        
    
    float late_charge = 0;
    float fees_and_other_debit = 150;
    float Finance_charge = 0;
    float Out_bal = 0;
    float minimum_payments = 0;
    float Available_balance;
    float min_pay = 0;
    float interest_charge = 0.02;
    float interst1;
    float interst2;
    
    cout << "Date Today (mm/dd/yyyy) : "<< endl;
    cout << "Enter Month (mm): ";
     cin >> datemm;
     cout << "Enter Day (dd): ";
     cin >> datedd;
     cout << "Enter Year (yyyy): ";
     cin >> dateyyyy;
     cout << datemm<< "/" <<datedd<< "/" <<dateyyyy<<endl;
     
     int datemmn;
     int dateddn;
     int dateyyyyn;
     
     int monthdays[] = {31,28,31,30,31,30,31,31,30,31,30,31};   
                                        
        int addyears;    
        int leftoverdays; 
        int dd = 30;
        
datemmn = datemm;
dateddn = datedd;
dateyyyyn = dateyyyy;

        addyears = dd/365;
        leftoverdays = dd%365;

        dateyyyy += addyears;

        for (int i = 0; i <= leftoverdays; i++)
                if (datedd< monthdays [datemm -1])
                        datedd ++;
                else if ((datedd == monthdays [datemm-1]) && (datemm < 12))
                {
                        datedd = 1;
                        datemm++;
                }
                else if ((datedd == monthdays [datemm-1]) && (datemm == 12))
                {
                        datedd = 1;
                        datemm = 1;
                        dateyyyy ++;
                }
                else
                        cout << "Error setting date!";

    if (prevbal == payment){
        late_charge = 0;
        Finance_charge = 0;
        Out_bal = (sum+Finance_charge+fees_and_other_debit+late_charge+prevbal)-payment;
        min_pay = Out_bal*0.0357;
        if (min_pay<=850){
            min_pay=850;
        }
        else {
        min_pay = Out_bal*0.0357;
        Available_balance = credlim1-Out_bal;
        }
    }
    else {
        cout << "Number of days of payment from statement date to payment date: ";
        cin >> d1;
        cout << "Number of days of payment from payment date to billing date: ";
        cin >> d2;
        interst1 = ((prevbal*interest_charge)/30)*d1;
        interst2 = (((prevbal-payment)*(interest_charge))/30)*d2;
        Finance_charge = interst1+interst2;
        late_charge = prevbal*0.05;
        Out_bal = (prevbal+sum+Finance_charge+late_charge+fees_and_other_debit)-payment;
        min_pay = Out_bal*0.0357;
        if (min_pay<=850){
            min_pay=850;
        }
        else {
        min_pay = Out_bal*0.0357;
        Available_balance = credlim1-Out_bal;
        }
    }
    
       cout <<endl; 
cout << setw (55) << "Credit Card Statement" << setw (55) << endl;
  cout << setw (80) << "BDO San Nicolas Manila" << endl;
  cout << "\nAccount name: " << "Faith Dela Cruz Smith" << setw (55) << "Date Issue: " <<
    datemmn<< "/" <<dateddn<< "/" <<dateyyyyn << endl;
  cout << "Account Address: " << "788 Tondo Street Binondo, Bulacan" << endl;
  cout << "\nCard Information: " <<
    "VISA" << endl;
  cout << "Account Number: " << "34235433" << endl;
  cout << "Credit Limit: " << "100,000" << endl;
  cout << "Available Credit:" << Available_balance << endl;
  cout << "Statement Opening: " << datemmn<< "/" <<dateddn<< "/" <<dateyyyyn << " Closing Date: " << datemm<< "/" <<datedd<< "/" <<dateyyyy << endl;
  cout <<
    "______________________________________________________________________\n"
    << endl;
  cout << "Transactions" << endl;
  cout << setw (10) << "Date" << setw (30) << "Description" << setw (29) <<
    "Amount" << endl;
  cout << setw (70) << " _____________________________________________________________________" << endl;
  int f=1;
    for (int t = 0; t<pay.size(); t++){
  cout << "\n"<< f << "." << setw (10) << date[t] << setw (24) << tran[t] <<
    setw (31) << pay[t] << endl;
    f++;
    }
  cout <<
    "______________________________________________________________________\n"
    << endl;
  cout << setw (27) << "Summary of Transactions" << setw (38) <<
    "Payment Information" << endl;
  cout << "\n-Previous Balance ----- " << prevbal << setw (34) <<
    " Outstanding Balance ---- " << Out_bal << endl;
  cout << "-Payment -------------- " << setw (6) << payment << setw (34) <<
    " Minimum Payment -------- " << setw (5) << min_pay << endl;
  cout << "+Total Purchases ------ " << setw (6) << sum << setw (30) <<
    " Payment Due Date ------- " << setw (5) << datemm<< "/" <<datedd<< "/" <<dateyyyy << endl;
  cout << "+Finance Charges ------ " << setw (6) << Finance_charge << endl;
  cout << "+Interest Charges ----- " << setw (6) << "2%" << endl;
  cout << "+Late Charges --------- " << setw (6) << late_charge << endl;
  cout << "+Fees & Other Debit ----- " << setw (6) << fees_and_other_debit << endl;
  cout <<
    "\n______________________________________________________________________"
    << endl;
  cout << "\n " << endl;
  cout <<
    "\n  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  "
    << endl;
}

    
void ins3() {
    float sum = 0;
    float sum1 = 0;
    int count = 3;
    int i;
        for (i=1; i<count; i++){
        cout << "Enter transaction " << i <<": ";
        cin >> tran1;
        cout << "Enter pay " << i <<": ";
        cin >> pay1;
        cout << "Enter date " << i <<": ";
        cin >> date1;
        pay.push_back(pay1);
        date.push_back(date1);
        tran.push_back(tran1);
    for (int n = 0; n < pay.size(); n++){
        sum1 += n;}
        if (sum1>credlim1) {
            cout << "max credit reached";
        }
        }
	string ans;
	cout<< "would you like to add more transactions? y/n?";
	cin>> ans;
	if (ans == "y"){
	int eto=2;
	cout<< "How many transactions will you enter?" << endl;
	cin >> eto;
	count=count+eto;
	
	for (i; i<count; i++){
        cout << "Enter transaction " << i <<": ";
        cin >> tran1;
        cout << "Enter pay " << i <<": ";
        cin >> pay1;
        pay.push_back(pay1);
        date.push_back(date1);
        tran.push_back(tran1);
        cout << "Enter date " << i <<": ";
        cin >> date1;
        for (int n = 0; n < pay.size(); n++){
        sum1 += n;}
        if (sum1>credlim1) {
            cout << "max credit reached";
        }
	}
	}
     for (int n : pay)
       sum = sum += n;
        cout << sum << endl;
    cout << endl;
    
        cout << "Previous Balance: ";
        cin >> prevbal;
    cout << "Paid payments: ";
        cin >> payment;

        
    
    float late_charge = 0;
    float fees_and_other_debit = 150;
    float Finance_charge = 0;
    float Out_bal = 0;
    float minimum_payments = 0;
    float Available_balance;
    float min_pay = 0;
    float interest_charge = 0.02;
    float interst1;
    float interst2;
    
     cout << "Date Today (mm/dd/yyyy) : "<< endl;
     cout << "Enter Month (mm): ";
     cin >> datemm;
     cout << "Enter Day (dd): ";
     cin >> datedd;
     cout << "Enter Year (yyyy): ";
     cin >> dateyyyy;
     cout << datemm<< "/" <<datedd<< "/" <<dateyyyy<<endl;
    int datemmn;
     int dateddn;
     int dateyyyyn;
     
     int monthdays[] = {31,28,31,30,31,30,31,31,30,31,30,31};   
                                        
        int addyears;    
        int leftoverdays; 
        int dd = 30;
        
datemmn = datemm;
dateddn = datedd;
dateyyyyn = dateyyyy;

        addyears = dd/365;
        leftoverdays = dd%365;

        dateyyyy += addyears;

        for (int i = 0; i <= leftoverdays; i++)
                if (datedd< monthdays [datemm -1])
                        datedd ++;
                else if ((datedd == monthdays [datemm-1]) && (datemm < 12))
                {
                        datedd = 1;
                        datemm++;
                }
                else if ((datedd == monthdays [datemm-1]) && (datemm == 12))
                {
                        datedd = 1;
                        datemm = 1;
                        dateyyyy ++;
                }
                else
                        cout << "Error setting date!";

    if (prevbal == payment){
        late_charge = 0;
        Finance_charge = 0;
        Out_bal = (sum+Finance_charge+fees_and_other_debit+late_charge+prevbal)-payment;
        min_pay = Out_bal*0.0357;
        if (min_pay<=850){
            min_pay=850;
        }
        else {
        min_pay = Out_bal*0.0357;
        Available_balance = credlim1-Out_bal;
        }
    }
    else {
        cout << "Number of days of payment from statement date to payment date: ";
        cin >> d1;
        cout << "Number of days of payment from payment date to billing date: ";
        cin >> d2;
        interst1 = ((prevbal*interest_charge)/30)*d1;
        interst2 = (((prevbal-payment)*(interest_charge))/30)*d2;
        Finance_charge = interst1+interst2;
        late_charge = prevbal*0.05;
        Out_bal = (prevbal+sum+Finance_charge+late_charge+fees_and_other_debit)-payment;
        min_pay = Out_bal*0.0357;
        if (min_pay<=850){
            min_pay=850;
        }
        else {
        min_pay = Out_bal*0.0357;
        Available_balance = credlim1-Out_bal;
        }
    }
    
    cout <<endl;
cout << setw (55) << "Credit Card Statement" << setw (55) << endl;
  cout << setw (80) << "BDO San Nicolas Manila" << endl;
  cout << "\nAccount name: " << "Juan Dela Rosa" << setw (55) << "Date Issue: " <<
    datemmn<< "/" <<dateddn<< "/" <<dateyyyyn << endl;
  cout << "Account Address: " << "999 Panday Street Coco, Martin" << endl;
  cout << "\nCard Information: " <<
    "Mastercard" << endl;
  cout << "Account Number: " << "54323446" << endl;
  cout << "Credit Limit: " << "100,000" << endl;
  cout << "Available Credit:" << Available_balance << endl;
  cout << "Statement Opening: " << datemmn<< "/" <<dateddn<< "/" <<dateyyyyn << " Closing Date: " << datemm<< "/" <<datedd<< "/" <<dateyyyy << endl;
  cout <<
    "______________________________________________________________________\n"
    << endl;
  cout << "Transactions" << endl;
  cout << setw (10) << "Date" << setw (30) << "Description" << setw (29) <<
    "Amount" << endl;
  cout << setw (70) << " _____________________________________________________________________" << endl;
  int f=1;
    for (int t = 0; t<pay.size(); t++){
  cout << "\n"<< f << "." << setw (10) << date[t] << setw (24) << tran[t] <<
    setw (31) << pay[t] << endl;
    f++;
    }
  cout <<
    "______________________________________________________________________\n"
    << endl;
  cout << setw (27) << "Summary of Transactions" << setw (38) <<
    "Payment Information" << endl;
  cout << "\n-Previous Balance ----- " << prevbal << setw (34) <<
    " Outstanding Balance ---- " << Out_bal << endl;
  cout << "-Payment -------------- " << setw (6) << payment << setw (34) <<
    " Minimum Payment -------- " << setw (5) << min_pay << endl;
  cout << "+Total Purchases ------ " << setw (6) << sum << setw (30) <<
    " Payment Due Date ------- " << setw (5) << datemm<< "/" <<datedd<< "/" <<dateyyyy << endl;
  cout << "+Finance Charges ------ " << setw (6) << Finance_charge << endl;
  cout << "+Interest Charges ----- " << setw (6) << "2%" << endl;
  cout << "+Late Charges --------- " << setw (6) << late_charge << endl;
  cout << "+Fees & Other Debit ----- " << setw (6) << fees_and_other_debit <<endl;
  cout <<
    "\n______________________________________________________________________"
    << endl;
  cout << "\n " << endl;
  cout <<
    "\n  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  "
    << endl;
}

    
void compute() {
        if (accno == acc_no[0]){
        ins();
        }else if (accno == acc_no[1]) {
        ins2();
        }else if (accno == acc_no[2]) {
        ins3();        
    }
    }

void first () {
    cout << "Enter account number:";
        cin >> accno;
    for (int i=0; i < 3; i++) {
        if (accno == acc_no[i]) {
            compute();
        }}
        if (accno != acc_no[0] && accno != acc_no[1] && accno != acc_no[2]) {
            cout << "Invalid Account Number\n"; 
            first();
        }
}

int main () {
    first();
    int hehe;
    string ans;
    cout<< "Would you like to conduct another transaction?";
    cin>> ans;
    if (ans == "y") {
        first();
    } else {
    }
             return 0;
        }