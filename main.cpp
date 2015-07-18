#include <iostream>

using namespace std;

template<typename ... T>
void dummy(T ... t)
{

}

template<typename T>
void some_function(T t)
{
	cout<< t << "\t";
}


template<typename... Args> 
void expand(Args&&... args) 
{
	dummy( (some_function(args), 1)... );
	cout<<endl;
}


int main()
{
	expand(42, "answer", true);
}
