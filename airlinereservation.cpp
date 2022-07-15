#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;
int main(){
	
	int choice,seats,eseats,bseats;
	string password,username,user,pass,airline,model,serial,serialn;
	
	cout<<"***************Welcome to Airline Reservation*****************"<<endl;
	cout<<"***************1. Admin*********************"<<endl;
	cout<<"***************2. User**********************"<<endl;
	cout<<"Please select option to continue: ";
	cin>>choice;
	
	if(choice==1){
		cout<<"Enter your Username: ";
		cin>>user;
		cout<<"Enter password: ";
		cin>>pass;
		//read user details and deternine if he is fine to proceed or wrong credentials
		ifstream fin;//to read data in the userDB file
		fin.open("admin.txt", ios::in);
		fin>>username;
		fin>>password;
		
		while(username != user)
		{
			cout<<"Wrong username try again: "<<endl;
			cout<<"Enter username: ";
			cin>>user;
			cout<<"Enter password: ";
			cin>>pass;	
		}
		while(password != pass)
		{
			cout<<"Wrong password try again!"<<endl;
			cout<<"Enter username: ";
			cin>>user;
			cout<<"Enter password: ";
			cin>>pass;	
		}
		fin.close();
		cout << "Successfull Login"<<endl;
		system("CLS");
		
		cout<<"Welcome Admin choose an option to proceed\n";
		cout<<"\t 1.Manage Flight\n";
		cout<<"\t 2.Manage Tickets\n";
		cout<<"\t 3.Flight Schedule\n";
		cout<<"\t 4.Flight Status\n";
		cout<<"\t 5.Change Password\n";
		cout<<"Please select option to continue: ";
		cin>>choice;
		
		if(choice==1){
			cout<<"What would you like to do\n";
			cout<<"\t 1.Add a Flight\n";
			cout<<"\t 2.Update Flight\n";
			cout<<"\t 3.Delete Flight\n";
			cout<<"Please select option to continue: ";
			cin>>choice;
			if(choice==1){
				cout<<"ADD NEW FLIGHT\n";
				//to insert data in the flight file
				ofstream fout;
				fout.open("flight.txt" ,ios::app);
				cout<<"Enter the Airline: ";
				cin>>airline;
				cout<<"Enter plane model: ";
				cin>>model;
				cout<<"Enter plane serial number: ";
				cin>>serial;
				cout<<"Enter the total seat number: ";
				cin>>seats;
				cout<<"Enter economy class seat number: ";
				cin>>eseats;
				cout<<"Enter business class seat number: ";
				cin>>bseats;
				fout<<airline<<endl <<model<<endl <<serial<<endl <<seats<<endl <<eseats<<endl <<bseats<<endl;
				cout<<"Added a new Flight.\n";
				fout.close();
				system("cls");
				cout<<"What would you like to do\n";
				cout<<"\t 1.Add a Flight\n";
				cout<<"\t 2.Update Flight\n";
				cout<<"\t 3.Delete Flight\n";
				cout<<"Please select option to continue: ";
				cin>>choice;
				if(choice==2){
				cout<<"Please enter the plane serial: ";
				cin>>serialn;
				ifstream fin;//to read data in the userDB file
				fin.open("flight.txt", ios::in);
				fin>>airline>>model>>serial>>seats>>eseats>>bseats;
				if(serialn==serial){
					cout<<"Here is Your plan\n";
					cout<<airline<<endl <<model<<endl <<serial<<endl <<seats<<endl <<eseats<<endl <<bseats<<endl;	
				}else{
					cout<<"Plane doesnot exist!"<<endl;
				}
				}
			}
			if(choice==2){
				cout<<"Please enter the plane serial: ";
				cin>>serialn;
				ifstream fin;//to read data in the userDB file
				fin.open("flight.txt", ios::in);
				fin>>airline>>model>>serial>>seats>>eseats>>bseats;
				if(serialn==serial){
					cout<<"Here is Your plan\n";
					cout<<airline<<endl <<model<<endl <<serial<<endl <<seats<<endl <<eseats<<endl <<bseats<<endl;
			}else{
					cout<<"Plane doesnot exist!"<<endl;
				}
		}
		
		
	}
}
}

