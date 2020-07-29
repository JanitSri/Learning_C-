#pragma once 

class Mystring{
	
	friend std::ostream& operator<<(std::ostream& out, const Mystring& rhs); // non-member stream operator overload
	friend std::istream& operator>>(std::istream& in, Mystring& rhs); // non-member stream operator overload
	
	private:
		char* str;
	public:
		Mystring();
		Mystring(const char* s);
		Mystring(const Mystring& source);
		Mystring(Mystring&& source);
		~Mystring();
		
		void display() const;
		int get_length() const;
		const char* get_str() const;
		
		Mystring& operator=(const Mystring& rhs); // assignment operator (copy)
		Mystring& operator=(Mystring&& rhs); // assignment operator (move) 
		Mystring operator-() const; // unary operator overload (pre-decrement)
		bool operator==(const Mystring& rhs) const;
		bool operator>(const Mystring& rhs) const;
		Mystring operator*(int times) const;
};
