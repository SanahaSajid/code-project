#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;
struct Expense{
	string date;
	string category;
	double amount;
	string description;
	Expense * next;
	
};
struct MasterNode{
	Expense * headAddress;
	MasterNode *next;
	
};
MasterNode *masterHead=NULL;
class ExpenseTracker{
	public:
		Expense *head;
	ExpenseTracker ():head(NULL){
			MasterNode *newMasterNode =new MasterNode();
			newMasterNode->headAddress =head;
			newMasterNode ->next=masterHead;
			masterHead=newMasterNode;
		}
		
	void addExpense(){
		Expense *newExpense =new Expense();
		cout<<"Enter date(YYYY-MM-DD):"<<endl;
		cin>>newExpense->date;
		cout<<"Enetr category:"<<endl;
		cin>>newExpense->category;
		cout<<"Enter Amount:"<<endl;
		cin>>newExpense->amount;
		cout<<"enter description"<<endl;
		cin>>newExpense->description;
		cin.ignore();
		getline(cin,newExpense->description);
		newExpense->next = NULL;
		
		if(!head){
			head = newExpense;
			masterHead ->headAddress = head;
		} else{
			Expense *current = head;
			while (current->next){
				current = current-> next;
			}
			current ->next =newExpense;
		}
			}	
			
			void deleteExpense(){
				string date;
				cout<<"enter date of expense to delete :"<<endl;
				cin>>date;
				
				if (head->date== date)
				{
					Expense *temp = head;
					head = head->next;
					masterHead->headAddress= head;
					delete temp;
					cout<<"expense deleted successfully:"<<endl;
					return;
				}
		Expense *current = head;
		while(current ->next){
			if (current ->next->date ==date){
				Expense *temp = current ->next;
				current->next = current ->next->next;
				delete temp;
				cout<<"Expense delete successfuly"<<endl;
				return;
			}
			current = current->next;
		}		
		cout<<"Expense not found"<<endl;
			}
			
			void viewExpense(){
				Expense *current = head;
				while(current){
					cout<<"Date:"<<current ->date <<" category:"<<current->category<<"Amount"<<current->amount<<" description:"<<current->description<<endl;
					current =current->next;
				}
			}
	void monthlyReport(){
		string month;
		cout<<"enetr month (YYYY-MM):"<<endl;
		cin>>month;
		double total=0.0;
		Expense* current = head;
		while(current){
			if (current->date.substr(0, 7) == month){
				cout<<"date"<< current->date <<" category "<< current->category <<" Amount "<< current->amount <<" description "<< current->description <<endl;
				total += current->amount;
			}
			current = current->next;
		}
			cout<<"Total Expenses for month "<< total <<endl;
		}
		
	void weeklyReport(){
		int year,week;
		cout<<"enter year:"<<endl;
		cin>>year;
		cout<<"enetr week (1-52)"<<endl;
		cin>>week;
		double total =0.0;
		Expense *current =head;
		while (current){
			int currentYear = atoi(current->date.substr(0,4).c_str());
			int currentWeek = getWeekNumber(current->date);
			if (currentYear == year && currentWeek == week){
				cout<<"date"<<current->date<<"category"<<current->category<<" Amount"<<current->amount<<"cdescription"<<current->description<<endl;
				total += current->amount;
			}
			current = current->next;
		}
		cout<<"Total expense for the week"<<week<<"to year"<<year<<":"<< total <<endl;
	}	
	int getWeekNumber(string date){
		int year = atoi(date.substr(0, 4).c_str());
		int month =atoi(date.substr(5, 2).c_str());
		int day =atoi(date.substr(8, 2).c_str());
		int dayInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,2};
		int totalDays = 0;
		for(int i=1;i<month;i++){
			totalDays += dayInMonth[i];
		}
	}
	bool isEmpty(){
		return head ==NULL;
	}
};
 
 int main (){
 	ExpenseTracker tracker;
 	int choice;
 	do{
 		cout<<"Expense Tracker Menu"<<endl;
 		cout<<"1. Add Expense"<<endl;
 		cout<<"2. Delete Expense"<<endl;
 		cout<<"3. View Expense"<<endl;
 		cout<<"4. Monthly Report"<<endl;
 		cout<<"5. Weekly Report"<<endl;
 		cout<<"6. Exit"<<endl;
 		cout<<"Enter your choice:";
 		cin>>choice;
 		
 		switch(choice){
 			case 1:
 				tracker.addExpense();
 				break;
 				case 2:
 					if(!tracker.isEmpty()){
 						tracker.deleteExpense();
					 } else{
					 	cout<<"No Expense to delete."<<endl;
					 }
					 break;
					 case 3:
					 	if(!tracker.isEmpty()){
 						tracker.viewExpense();
					 } else{
					 	cout<<"No Expense to view."<<endl;
					 }
					 break;
					 case 4:
					 	if(!tracker.isEmpty()){
 						tracker.monthlyReport();
					 } else{
					 	cout<<"No Expense for weekly report."<<endl;
					 }
					 break;
					 case 5:
					 	if(!tracker.isEmpty()){
 						tracker.weeklyReport();
					 } else{
					 	cout<<"No Expense for weekly report."<<endl;
					 }
					 break;
					 case 6:
					 	
					 	cout<<"Exiting..."<<endl;
					 break;
					 default:
					 	cout<<"Invalid choice.please try again"<<endl;
		 }
	 }
	 while (choice !=6);
	 return 0;
 }
