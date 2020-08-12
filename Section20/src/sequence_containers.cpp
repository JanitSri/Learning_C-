#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <cctype>
#include <limits>
#include <fstream>
#include <sstream>


#define LINEBREAK std::cout << std::endl

template <typename T, int N>
void display_array(const std::array<T, N>& arr){
	std::cout << "[ ";
	for(const auto& i: arr){
		std::cout << i << " ";
	}
	std::cout << "]" << std::endl;
}

template <typename T1>
void display_vector(const std::vector<T1>& vec){
	std::cout << "[ ";
	for(const auto& v: vec){
		std::cout << v << " ";
	}
std::cout << "]" << std::endl;
}

template <typename T2>
void display_deque(const std::deque<T2>& deq){
	std::cout << "[ ";
	std::for_each(deq.begin(), deq.end(), [](auto x){std::cout << x << " ";});
	std::cout << "]" << std::endl;
}

template <typename T3>
void display_list(const std::list<T3>& l){
	std::cout << "[ ";
	std::for_each(l.begin(), l.end(), [](auto x){std::cout << x << " ";});
	std::cout << "]" << std::endl;
}

template <typename T3>
void display_forward_list(const std::forward_list<T3>& l){
	std::cout << "[ ";
	std::for_each(l.begin(), l.end(), [](auto x){std::cout << x << " ";});
	std::cout << "]" << std::endl;
}

template <typename T4>
void display_set(const std::set<T4>& s){
	std::cout << "[ ";
	std::for_each(s.begin(), s.end(), [](auto x){std::cout << x << " ";});
	std::cout << "]" << std::endl;
}

template <typename T5, typename T6>
void display_map(const std::map<T5,T6>& m){
	std::cout << "[ ";
	std::for_each(m.begin(), m.end(), [](auto x){std::cout << x.first << ":" << x.second << " ";});
	std::cout << "]" << std::endl;
}


bool is_palindrome(const std::string& s){
	std::deque<char> temp;
	
	for(char c: s)
		if(std::isalpha(c))
			temp.push_back(std::toupper(c));

	char c1{};
	char c2{};
	while(temp.size() > 1){
		c1 = temp.front();
		c2 = temp.back();
		temp.pop_back();
		temp.pop_front();
		
		if(c1 != c2){
			return false;
		}
	}
	return true;
}


class Song{
	friend std::ostream& operator<<(std::ostream& os, const Song& s);
private:
	std::string name;
	std::string artist;
	int rating;
public:
	Song() = default;
	Song(std::string name, std::string artist, int rating)
		: name{name}, artist{artist}, rating{rating}{}
	
	std::string get_song_name() const {return name;}
	std::string get_song_artist() const {return artist;}
	int get_song_rating() const {return rating;}
	
	bool operator==(const Song& rhs){
		return this->name == rhs.name && this->artist == rhs.artist;
	}
	
	bool operator<(const Song& rhs){
		return this->name < rhs.name;
	}
};

std::ostream& operator<<(std::ostream& os, const Song& s){
	os << s.name << " - " << s.artist << " - " << s.rating;
	return os;
}

void play_current_song(const Song& song){
	std::cout << "Playing: " << song << std::endl;
}

void display_playlist(const std::list<Song> playlist, const Song& current_song){
	for(const Song& song: playlist){
		std::cout << song << std::endl;
	}
	play_current_song(current_song);
}

void display_menu(){
	std::cout << "\nF - Play First Song" << std::endl;
	std::cout << "N - Play Next Song" << std::endl;
	std::cout << "P - Play Previous Song" << std::endl;
	std::cout << "A - Add and play a new Song at current location" << std::endl;
	std::cout << "L - List the current playlist" << std::endl;
	std::cout << "================================================" << std::endl;
	std::cout << "Enter a selection (Q to quit):";
}

bool is_palindrome2(const std::string& in_str){
	std::stack<char> chs;
	
	for(auto c: in_str){
		if(std::isalpha(c))
			chs.push(std::toupper(c));
	}
	
	int counter{0};
	while(!chs.empty()){
		if(std::isalpha(in_str[counter])){
			if(chs.top() != std::toupper(in_str[counter])){
				return false;
			}
			chs.pop();
		}
		counter++;
	}
	return true;
}

template <typename T7>
struct CustomCompare
{
    bool operator()(const T7& lhs, const T7& rhs)
    {
        return lhs > rhs;
    }
};

void seq_cont(){
	
	// for 'std::array' must indicate the type and the size of the array
	std::cout << "******SEQUENCE CONTAINER: ARRAYS******" << std::endl;
	std::array<int, 5> num_arr{3,2,4,1,5};
	std::array<std::string, 3> stooges{
		std::string("Larry"),
		"Moe",
		std::string("Curly")
	};
	
	// 'stooges.at(4)' does bounds checking but 'stooges[4]' does not 
	std::cout << "Array Size:" << stooges.size() << " At position 0:" << stooges.at(0) << " At position 1:" << stooges[1] << " Front:" << stooges.front() << " Back:" << stooges.back() << std::endl;
	std::cout << "The raw data pointer (the first element) " << stooges.data()  << " Deferenced Pointer:"<<  *stooges.data() << std::endl;
	display_array<std::string, 3>(stooges);
	
	std::sort(num_arr.begin(),num_arr.end()); 
	display_array<int, 5>(num_arr);
	std::cout << "The max element:" << *std::max_element(num_arr.begin(),num_arr.end()) << std::endl;
	std::cout << "The min element:" << *std::min_element(num_arr.begin(),num_arr.end()) << std::endl;
	std::cout << "The sum if all elements:" << std::accumulate(num_arr.begin(),num_arr.end(),0) << std::endl;
	
	
	LINEBREAK;
	std::cout << "******SEQUENCE CONTAINER: VECTORS******" << std::endl;
	std::vector<int> vec1{1,2,3,4,5}; 
	std::vector<int> vec2(10,100); // vector of ten 100s
	
	display_vector<int>(vec1);
	display_vector<int>(vec2);
	
	vec1 = {6,4,7,2,1,8,10};
	display_vector<int>(vec1);
	
	std::sort(vec1.begin(),vec1.end());
	std::cout << "After sorting ";
	display_vector<int>(vec1);
	
	std::cout << std::boolalpha;
	std::cout << "Vector Empty:" << vec1.empty() << std::endl;
	std::cout << std::resetiosflags(std::ios::boolalpha);
	
	// can use push_back or emplace_back to add items to end of the list 
	// push_back uses move constructor because it uses a temporary object 
	// emplace_back creates the object inplace, does not use the move constructor, more efficient 
	
	// add a vector to the back of another array
	std::copy(vec1.begin(),vec1.end(), std::back_inserter(vec2));
	display_vector<int>(vec2);
	
	vec1 = {1,2,3,4,5,6,7,8,9};
	vec2 = {10,11,12};
	std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2), [](int x){return x % 2 == 0;});
	display_vector<int>(vec2);
	
	
	LINEBREAK;
	std::cout << "******SEQUENCE CONTAINER: DEQUE******" << std::endl;
	// dynamic size, not stored in contigous memory (like vector)
	// rapind insertion and deletion at the front and back 
	std::deque<int> d1{1,2,3,4,5};
	std::deque<int> d2(10,100);  // ten 100s
	
	display_deque<int>(d1);
	display_deque<int>(d2);
	
	// use push_back (or emplace_back) to add to back and push_front (or emplace_front) to front 
	// use pop_back to remove from the back and pop_front to remove from the front 
	
	LINEBREAK;
	std::cout << "******SECTION CHALLENGE 1: PALINDROME CHECK USING DEQUE******" << std::endl;
	
	std::cout << std::boolalpha;
	std::cout << "a: " << is_palindrome(std::string("a")) << std::endl;
	std::cout << "aa: " << is_palindrome(std::string("aa")) << std::endl;
	std::cout << "aba: " << is_palindrome(std::string("aba")) << std::endl;
	std::cout << "abbcbba: " << is_palindrome(std::string("abbcbba")) << std::endl;
	std::cout << "C++: " << is_palindrome(std::string("C++")) << std::endl;
	std::cout << "A Santa at NASA: " << is_palindrome(std::string("A Santa at NASA")) << std::endl;
	std::cout << "palindrome: " << is_palindrome(std::string("palindrome")) << std::endl;
	std::cout << std::resetiosflags(std::ios::boolalpha);
	
	
	LINEBREAK;
	std::cout << "******SEQUENCE CONTAINER: LIST******" << std::endl;
	// non-contigous in memory, no direct access to elements, is a doubly linked list
	std::list<int> l1{2,3,4,5,6,7,8};
	
	display_list<int>(l1);
	std::cout << "List Size: " << l1.size() << std::endl;
	std::cout << "List Front Element: " << l1.front() << std::endl;
	std::cout << "List Back Element: " << l1.back() << std::endl;
	
	l1.push_front(1);
	l1.push_back(9);
	std::cout << "List Size: " << l1.size() << std::endl;
	display_list<int>(l1);
	
	auto it = std::find(l1.begin(), l1.end(), l1.back());
	l1.insert(++it, 10);
	display_list<int>(l1);
	
	LINEBREAK;
	std::cout << "******SEQUENCE CONTAINER: FORWARD LIST******" << std::endl;
	// less overhead than 'std::list', no direct access to elements, is a singly linked list 
	std::forward_list<int> fl{2,3,4,5};
	display_forward_list(fl);
	std::cout << "Forward List Front: " << fl.front() << std::endl; 
	// no 'back()' because it traverses in one direction
	// has no 'size()'
	// only has 'push_front','pop_front','emplace_front' 
	
	fl.push_front(1);
	auto fl_it = std::find(fl.begin(),fl.end(),5);
	fl.insert_after(fl_it, 6);
	display_forward_list(fl);
	
	LINEBREAK;
	std::cout << "******SECTION CHALLENGE 2: SIMULATE A PLAYLIST******" << std::endl;
	
	std::list<Song> playlist{
		{"God's Plan","Drake",5},
		{"Never Be The Same","Camila Cabello",5},
		{"Pray For Me","The Weekend and K. Lamar",4},
		{"The Middle","Zedd, Maren Morris & Grey",5},
		{"Wait","Maroon 5",4},
		{"Whatever It Takes","Imagine Dragons",3}
	};
	
	auto current_song = playlist.begin();
	
	char choice{'Q'}; // change to 'X' to activate 
	
	while(choice != 'Q'){
		display_menu();
		std::cin >> choice;
		
		choice = std::toupper(choice);
		if(choice == 'F'){
			current_song = playlist.begin();
			play_current_song(*current_song);
		}
		else if(choice == 'N'){
			current_song++;
			if(current_song == playlist.end()){
				current_song = playlist.begin();
			}
			
			play_current_song(*current_song);
			
		}
		else if(choice == 'P'){
			if(current_song == playlist.begin()){
				current_song = playlist.end();
			}
				
			play_current_song(*(--current_song));				
		}
		else if(choice == 'A'){
			std::string song{}, artist{};
			int rating{};
			
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			
			std::cout << "Enter name of the song: ";
			std::getline(std::cin, song);
			
			std::cout << "Enter name of the artist: ";
			std::getline(std::cin, artist);
			
			std::cout << "Enter rating for the song: ";
			std::cin >> rating;
			
			playlist.insert(current_song, Song{song,artist,rating});
			play_current_song(*(--current_song));
		}
		else if(choice == 'L'){
			display_playlist(playlist, *current_song);
		}
		else if(choice == 'Q'){
			std::cout << "Thanks for listening." << std::endl;
		}
		else{
			std::cout << "<<<INVALID CHOICE>>> Try Again." << std::endl;
		}
	}
	
	
	LINEBREAK;
	std::cout << "******ASSOCIATIVE CONTAINER: SETS******" << std::endl;
	// std::set' ordered by key, no duplicate elements
	// 'std::multi_set' defined in set header file, ordered by key, allows duplicate elements
	// 'std::unordered_set' defined in unordered_set header file, elements are unordered, no duplicate elements, elements cannot be modified (erased and reinserted)
	// 'std::unordered_multiset' defined in unordered_set header file, elements are unordered, allows duplicate elements
	
	std::set<int> s1{1,2,3,4,5};
	auto result = s1.insert(6); // returns a 'std::pair<iterator, bool>'
	std::cout << "Inserted" << *(result.first) << " Successful:" << result.second << std::endl;
	s1.insert(7);
	
	display_set<int>(s1);
	
	auto it_set = s1.find(6);
	if(it_set != s1.end()){
		std::cout << "Found: " << *it_set << " at " << std::distance(s1.begin(), it_set) << std::endl; 
	}
	std::cout << "Size of Set:" << s1.size() << std::endl;
	
	
	LINEBREAK;
	std::cout << "******ASSOCIATIVE CONTAINER: MAPS******" << std::endl;
	// 'std::map' allow for fast retrieval of value using a key, simialar to dictionary, ordered by key, no duplicate elements
	// 'std::multimap' in the map header file, ordered by key, allows duplcate elements 
	// 'std::unordered_map' elements are unordered, no duplicate elements, in the unordered_map header file 
	// 'std::unordered_multimap' elements are unordered, allows duplicate elements, in the unordered_map header file 
	
	
	std::map<std::string, int> m1{
		{"Larry", 18},
		{"Moe", 25}
	};
	
	std::cout << "Size of Map:" << m1.size() << std::endl; 
	
	std::pair<std::string, int> pr1{"Curly",30};
	m1.insert(pr1);
	m1.insert(std::make_pair("Janit",28));
	m1["Jane"] = 29; // insert or update if exists, can also use 'm1.at("Jane") = 29'
	display_map<std::string, int>(m1);
	
	
	LINEBREAK;
	std::cout << "******SECTION CHALLENGE 3: FIND UNIQUE WORDS******" << std::endl;
	
	bool run_challenge = false;
	
	if(run_challenge){
		std::ifstream in_file;
		std::string file_name{};
		
		std::cout << "Enter File Name:";
		std::cin >> file_name;
		
		in_file.open("../"+file_name);
		std::string current_line;
		
		std::map<std::string, int> word_count{};
		std::map<std::string, std::set<int>> word_location{};
		
		std::string current_word{};
		int line_number{1};
		
		if(in_file){
			while(std::getline(in_file, current_line)){
				if(!current_line.empty()){
					std::istringstream ss{current_line};
					while(ss >> current_word){
						if(std::ispunct(current_word[current_word.length()-1])){
							current_word.pop_back();
						}
						word_count[current_word]++;
						word_location[current_word].insert(line_number);
					}			
				}
				line_number++;
			}		
		}
		else{
			std::cout << "<<<" << file_name << " DOES NOT EXIST>>>" << std::endl;
			std::exit(1);
		}
		
		LINEBREAK;
		std::cout << std::setw(15) << std::left << "WORDS" << std::setw(10) << std::left << "COUNT" << std::endl;
		for(const auto& [word,count]: word_count){
			std::cout << std::setw(15) << std::left << word << std::setw(10) << std::left << count << std::endl;
		}
		
		LINEBREAK;
		for(const auto& [word,locations]: word_location){
			std::cout << std::setw(15) << std::left << word << " ";
			display_set<int>(locations);
		}
		
		in_file.close();
	}
	
	LINEBREAK;
	std::cout << "******CONTAINER ADAPTORS: STACK******" << std::endl;
	// LIFO, can be implemented as vector, list, deque(default)
	// push, pop, top(can be used to change the top element), empty, size
	
	std::stack<int> stack1; // uses deque
	std::stack<int, std::vector<int>> stack2;
	
	stack1.push(10);
	stack1.push(20);
	stack1.push(30);
	
	while(!stack1.empty()){
		std::cout << "The top of the stack popped off is " << stack1.top() << std::endl;
		stack1.pop();
	}
	
	LINEBREAK;
	std::cout << "******CONTAINER ADAPTORS: QUEUE******" << std::endl;
	// FIFO, implemented as a list or deque(default)
	// push, pop, front, back, empty, size
	
	std::queue<int> q1; // uses deque
	std::queue<int, std::list<int>> q2;
	
	q1.push(10);
	q1.push(20);
	q1.push(30);
	q1.push(40);
	q1.push(50);
	
	while(!q1.empty()){
		std::cout << "Front of the queue: " << q1.front() << " Back of the queue: " << q1.back() << std::endl;
		q1.pop();
	}
	
	
	LINEBREAK;
	std::cout << "******SECTION CHALLENGE 4: FIND UNIQUE WORDS******" << std::endl;
	std::vector<std::string> test_cases{"a","aa","c++","ab","avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "This is a palindrome"};
	
	std::cout << std::boolalpha;
	std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
	for(const std::string& word: test_cases){
		std::cout << std::setw(8) << std::left << is_palindrome2(word) << word << std::endl;
	}
	std::cout << std::resetiosflags(std::ios::boolalpha);
	
	
	LINEBREAK;
	std::cout << "******CONTAINER ADAPTORS: PRIORITY QUEUE******" << std::endl;
	// insertion and removal of elements in order from the front of the list 
	// elements are stored internally as vector 
	// elements are inserted in priority order (largest value will be in the front)
	// part of the queue header file 
	// push, pop, top, empty, size 
	
	std::priority_queue<int, std::vector<int>, CustomCompare<int>> pq;
	pq.push(10);
	pq.push(20);
	pq.push(3);
	pq.push(4);
	
	std::cout << "Top of the Priority Queue: " << pq.top() << std::endl;
	pq.pop();
	std::cout << "Top of the Priority Queue after pop: " << pq.top() << std::endl;
	
	// can use 'std::priority_queue<int, std::vector<int>, std::greater<int>>'
	// std::greater<int>, std::less<int>, or custom comparator 
}
































