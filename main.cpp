#include <iostream>

using namespace std;

#define PRINT_FUNC  \
	cout<< __func__ <<endl

class CAT
{
	public:
		void print()
		{
			PRINT_FUNC;	
		}
};


template<typename ... T>
void dummy(T ... t)
{
	PRINT_FUNC;
}

template<typename T>
void some_function(T t)
{
	PRINT_FUNC;
	cout<< t << "\t";
}


template<typename... Args> 
void expand(Args&&... args) 
{
	PRINT_FUNC;
	dummy( (some_function(args), 1)... );
	cout<<endl;
}


int main()
{
#if __cplusplus < 201103L
#error "should use c++ implementaton"
#endif
	PRINT_FUNC;
	expand(42, "answer", true);
	CAT c;
	c.print();
}
