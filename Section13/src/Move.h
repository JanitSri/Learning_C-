#pragma once 


class Move{
	private:
		int *data; // raw data pointer 
		
	public:
		Move();
		Move(int d);
		Move(const Move &source);  // copy constructor 
		Move(Move &&source); // Move Constructor 
		~Move();
		
		void set_data_value(int d);
		int get_data_value();
};