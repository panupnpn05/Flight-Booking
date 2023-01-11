#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
class Flight{
	public:
		int date,day;
		string month,mon;
		void setDate(){
			cout<<"*******Date to reserve*******\n ";
			cout<<"Please input date of flight: "; cin>>date;
			day = date;
			cout<<"Please input month: "; cin>>month;
			mon = month;
		};
};

class Dayflight : public Flight{
	public:
		int year;
		void showDate(){
			Flight::setDate();
			year = 2021;
			cout<<"Date of your flight is : "<<day  <<mon  <<year <<endl;
		};
};

class Destination{
	public:
		string destinate;
		void setFlight(){
			cout<<"Please input your destination depart from : \n Krabi\n Chiang Mai\n Hat Yai\n Phuket\n DonMuang\n"; cin>>destinate;
		};
};
class Destinate : public Destination{
	public:
		string airport;
		void showDest(){
			Destination::setFlight();
			
				if(destinate == "Donmuang"){
					cout<<"Don Muang\n";
					cout<<"Where do you go to : \n Krabi\n Chiang Mai\n Hat Yai\n Phuket\n";
					cin>>airport;
				}
				else if(destinate == "Krabi"){
					cout<<"Krabi\n";
					cout<<"Where do you go to : \n Don Muang\n Chiang Mai\n Hat Yai\n Phuket\n";
					cin>>airport;
				}
				else if(destinate == "ChiangMai"){
					cout<<"Chiang Mai\n";
					cout<<"Where do you go to : \n Don Muang\n Krabi\n Hat Yai\n Phuket\n";
					cin>>airport;
				}
				else if(destinate == "Hatyai"){
					cout<<"Hat Yai\n";
					cout<<"Where do you go to : \n Don Muang\n Krabi\n Chiang Mai\n Phuket\n";
					cin>>airport;
				}
				else if(destinate == "Phuket"){
					cout<<"Phuket\n";
					cout<<"Where do you go to : \n Don Muang\n Krabi\n Chiang Mai\n Hat Yai\n";
					cin>>airport;
				}
				else{
					cout<<"Invalid airport";
				};
			};
		};
class Ticket_price{
	public:
		float ticket_ecoprice,ticket_busprice,ticket_firprice;
		int Eco_passengers,Bus_passengers,Fir_passengers;
		void setTicket(){
			cout<<"*******Tickets*******\n ";
			cout<<"How many Economy passengers: "; cin>>Eco_passengers;
			cout<<"How many Bussiness passengers: "; cin>>Bus_passengers;
			cout<<"How many First Class passengers: "; cin>>Fir_passengers;
		};
		
};
class Totalprice : public Ticket_price{
	public:
		float eoprice,busprice,firprice,totalprice;
		void showPrice(){
			Ticket_price::setTicket();
			ticket_ecoprice = Eco_passengers * 1500.00;
			ticket_busprice = Bus_passengers * 2700.00;
			ticket_firprice = Fir_passengers * 4000.00;
			totalprice = ticket_ecoprice + ticket_busprice + ticket_firprice;
			cout<<"Economy ticket = "<<ticket_ecoprice<<endl;
			cout<<"Business ticket = "<<ticket_busprice<<endl;
			cout<<"First Class ticket = "<<ticket_firprice<<endl;
			cout<<"*******Total cost*******\n ";
			cout<<"Total Price = "<<totalprice<<endl;
		};
};
class Meal {
	public:
		float Total,sFood,sWater,sDessert;
			Meal(float Food, float Water, float Dessert){
			sFood = Food ;
			sWater = Water ;
			sDessert = Dessert ; }
			void showMeal() {
 			float tTotal = sFood+sWater+sDessert;
 			cout <<"Total of meal = "<<tTotal<<endl; };
 		};
class Service {
	public:
		float Total,sMassage,sSpacial;
			Service(float Massage,float Spacial){
            sMassage = Massage;
            sSpacial = Spacial; }
			void showService() {
 			float tTotal = sMassage+sSpacial;
 			cout <<"Total of Spacial massage service = "<<tTotal<<endl; };
 		};
int main(){
	Meal mea(150,60,90);
	Service ser(200,50);
    cout <<fixed<<setprecision(3);
	
	string name;
	cout<<"*******Welcome to Codeman Airlines*******\n";
	cout<<"Please input your name: "; 
	cin>>name;
	
	Dayflight dfl;
	Destinate des;
	Totalprice tot;
	
	
	dfl.showDate();
	des.showDest();
	tot.showPrice();
	
	ifstream myfile;
    string line;
 	mea.showMeal();
 	ser.showService();

    myfile.open ("ThanksTXT.txt");
    while (getline(myfile,line))
    {
        cout << line << endl;
    }
    myfile.close();
    return 0;
}

