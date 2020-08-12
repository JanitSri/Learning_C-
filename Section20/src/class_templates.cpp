#include <iostream>
#include <string>

#define LINEBREAK std::cout << std::endl

template <typename T1, typename T2>
class Item{
	
	friend std::ostream& operator<<(std::ostream& os, const Item& i){
		os << "Name:" << i.get_name() << " Value:" << i.get_value();
		return os;
	}
	
	private:
		T1 name;
		T2 value;
	public:
		Item(T1 name, T2 value)
			: name{name}, value{value}{}
		T1 get_name() const {
			return name;
		}
		T2 get_value() const {
			return value;
	}
};

template <typename T1, typename T2>
struct MyPair{
	T1 first;
	T2 second;
};

void cls_templates(){
	
	std::cout << "*******Class Templates*******" << std::endl;
	Item<std::string, int> item1{"Janit", 69};
	std::cout << item1 << std::endl;
	
	Item<char, double> item2{'J', 56.65};
	std::cout << item2 << std::endl;
	
	Item<double, int> item3{2.656, 56};
	std::cout << item3 << std::endl;
	
	
	MyPair<std::string, std::string> jPair{"Janit", "Sriganeshaelankovan"};
	std::cout << jPair.first << " " << jPair.second << std::endl;
}









