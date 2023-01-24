/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:30:51 by younjkim          #+#    #+#             */
/*   Updated: 2023/01/25 04:42:27 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>

#if 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	#include <set>
	namespace ft = std;
#else
	#include "includes/map.hpp"
	#include "includes/stack.hpp"
	#include "includes/vector.hpp"
	#include "includes/set.hpp"
	#include "includes/containers.hpp"
#endif

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int subject_test(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		ft::map<int, int> copy = map_int;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;

	return (0);
}

template <typename T>
void print_element(T container) {
	typename T::iterator it = container.begin();
	for (; it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// for (unsigned int i = 0; i < container.size(); i++)
	// 	std::cout << container[i] << " ";
}

template <typename T>
void print_map_element(T container) {
	typename T::iterator it = container.begin();
	while (it != container.end()) {
		std::cout << "first: " << it->first << ",  second: " << it->second << std::endl;
		it++;
	}
	std::cout << std::endl;
}

void vector_test() {
	ft::vector<int> myvector(1);
	std::cout << " ### myvector construct ### " << std::endl;
	print_element(myvector);

	ft::vector<int> myvector2(2, 4);
	std::cout << " ### myvector2 construct ### " << std::endl;
	print_element(myvector2);

	ft::vector<int> myvector3;
	for (int i = 0; i < 7; i++)
		myvector3.push_back(i);
	std::cout << " ### myvector3 construct ### " << std::endl;
	print_element(myvector3);

	ft::vector<int> myvector4(myvector3.begin(), myvector3.end());
	std::cout << " ### myvector4 construct ### " << std::endl;
	print_element(myvector4);

	myvector.insert(myvector.end() - 1, 42);
	myvector.insert(myvector.begin(), myvector2.begin(), myvector2.end());
	std::cout << " ### myvector insert ### " << std::endl;
	print_element(myvector);

	myvector2.insert(myvector2.begin(), 2, 21);
	std::cout << " ### myvector2 insert ### " << std::endl;
	print_element(myvector2);

	myvector3.erase(myvector3.begin());
	std::cout << " ### myvector3 insert ### " << std::endl;
	print_element(myvector3);

	myvector4.erase(myvector4.begin() + 1, myvector4.end() - 1);
	std::cout << " ### myvector4 insert ### " << std::endl;
	print_element(myvector4);

	myvector3.pop_back();
	std::cout << " ### myvector3 pop back ### " << std::endl;
	print_element(myvector3);
}

void map_test() {
	ft::map<std::string, int> mymap;
	mymap.insert(ft::make_pair<std::string, int>("hundred", 100));
	mymap["thousand"] = 1000;
	mymap.insert(ft::make_pair<std::string, int>("ten", 10));
	mymap["million"] = 1000000;

	std::cout << " ### mymap construct ### " << std::endl;
	print_map_element(mymap);

	std::cout << " ### mymap find & erase ### " << std::endl;
	std::cout << "before erase: " << mymap.find("thousand")->second << std::endl;
	mymap.erase("thousand");
	std::cout << "after erase: " << mymap.find("thousand")->second << std::endl << std::endl;

	std::cout << " ### mymap bound ### " << std::endl;
	std::cout << "lower bound: " << mymap.lower_bound("hundred")->second << std::endl;
	std::cout << "upper bound: " << mymap.upper_bound("hundred")->second << std::endl;
}

void stack_test() {
	ft::stack<std::string> mystack;
	mystack.push("karina");
	mystack.push("winter");
	mystack.push("giselle");
	mystack.push("ningning");

	std::cout << " ### before pop ### " << std::endl;
	std::cout << "size: " << mystack.size() << std::endl;
	std::cout << "top: " << mystack.top() << std::endl << std::endl;

	mystack.pop();
	mystack.pop();

	std::cout << " ### after pop ### " << std::endl;
	std::cout << "size: " << mystack.size() << std::endl;
	std::cout << "top: " << mystack.top() << std::endl;
}

void set_test() {
	ft::set<int> myset;
	myset.insert(32);
	myset.insert(11);
	
	ft::set<int>::iterator i = myset.begin();
	myset.insert(i, 42);

	std::cout << " ### myset insert ### " << std::endl;
	print_element(myset);
	std::cout << std::endl;
	
	std::cout << " ### myset find & erase ### " << std::endl;
	std::cout << "before erase: " << *(myset.find(11)) << std::endl;
	std::cout << "size: " << myset.size() << std::endl << std::endl;
	myset.erase(11);
	std::cout << "after erase: " << *(myset.find(11)) << std::endl;
	std::cout << "size: " << myset.size() << std::endl;
}

int main(int argc, char** argv) {

	if (subject_test(argc, argv) == 1)
		return (1);
	std::cout << std::endl;

	std::cout << "------------------------ vector test ------------------------" << std::endl;
	vector_test();
	std::cout << std::endl;

	std::cout << "------------------------ map test ------------------------" << std::endl;
	map_test();
	std::cout << std::endl;

	std::cout << "------------------------ stack test ------------------------" << std::endl;
	stack_test();
	std::cout << std::endl;

	std::cout << "------------------------ set test ------------------------" << std::endl;
	set_test();
	std::cout << std::endl;

	return (0);
}