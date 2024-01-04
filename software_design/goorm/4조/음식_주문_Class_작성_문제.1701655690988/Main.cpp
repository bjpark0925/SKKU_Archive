#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Food {
private:
	string name;
	double price;
	int quantity=0;
public:
	Food() : name("Unknown"), price(0.0), quantity(0) {}
	Food(string _name, double _price){
		name=_name;
		price=_price;
		quantity++;
	}
	string getName(){
		return name;
	}
	double getPrice(){
		return price;
	}
	int getQuantity(){
		return quantity;
	}
};

class Order {
public:
	int size=0;
	Food* f=new Food[100];
	
	void addFood(Food& food){
		f[size]=food;
		size++;
	}
	double calculateTotalPrice(){
		double sum=0;
		for (int i=0;i<size;i++){
			sum+=f[i].getPrice()*f[i].getQuantity();
		}
		return sum;
	}
	void displayOrderInfo(){
		for (int i=0;i<size;i++){
			cout<<f[i].getName()<<": $"<<f[i].getPrice()<<" ";
		}
		cout<<endl<<"Total: $"<<this->calculateTotalPrice()<<endl;
	}
};

class Customer {
public:
	string cname;
	Order o;
	
	Customer(){cname="Unknown";}
	Customer(string _name){cname=_name;}
	void placeOrder(Food &food){
		o.addFood(food);
	}
	void displayCustomerInfo(){
		cout<<"Customer Information:"<<endl;
		cout<<cname<<", ";
		o.displayOrderInfo();
	}
};

int main() {
	Food burger("Cheese Burger", 8.99);
	Food fries("French Fries", 3.99);
	
	Customer customer("John Doe");
	customer.placeOrder(burger);
	customer.placeOrder(fries);

	customer.displayCustomerInfo();
	
	return 0;
}