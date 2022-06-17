#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>
#include <windows.h>

#define UP    72
#define LEFT  75
#define RIGTH 77
#define DOWN  80
#define ESC   27
#define ENTER 13


namespace fg {
	template < class CharT, class Traits >
	constexpr
		std::basic_ostream< CharT, Traits >& BWhite(std::basic_ostream< CharT, Traits >& os)
	{
		return os << "\033[97m";
	}

	template < class CharT, class Traits >
	constexpr
		std::basic_ostream< CharT, Traits >& Gray(std::basic_ostream< CharT, Traits >& os)
	{
		return os << "\033[90m";
	}

	template < class CharT, class Traits >
	constexpr
		std::basic_ostream< CharT, Traits >& BGray(std::basic_ostream< CharT, Traits >& os)
	{
		return os << "\033[37m";
	}

	template < class CharT, class Traits >
	constexpr
		std::basic_ostream< CharT, Traits >& Green(std::basic_ostream< CharT, Traits >& os)		
	{
			return os << "\033[32m";
	}

	template < class CharT, class Traits >
	constexpr
		std::basic_ostream< CharT, Traits >& BGreen(std::basic_ostream< CharT, Traits >& os)
	{
		return os << "\033[92m";
	}

	template < class CharT, class Traits >
	constexpr
		std::basic_ostream< CharT, Traits >& Red(std::basic_ostream< CharT, Traits >& os)
	{
		return os << "\033[31m";
	}


	template < class CharT, class Traits >
	constexpr
		std::basic_ostream< CharT, Traits >& BRed(std::basic_ostream< CharT, Traits >& os)
	{
		return os << "\033[91m";
	}

	template < class CharT, class Traits >
	constexpr
		std::basic_ostream< CharT, Traits >& Yellow(std::basic_ostream< CharT, Traits >& os)
	{
		return os << "\033[33m";
	}

	template < class CharT, class Traits >
	constexpr
		std::basic_ostream< CharT, Traits >& BYellow(std::basic_ostream< CharT, Traits >& os)
	{
		return os << "\033[93m";
	}
	    
}



namespace bg {
	template < class CharT, class Traits >
	constexpr
		std::basic_ostream< CharT, Traits >& BWhite(std::basic_ostream< CharT, Traits >& os)
	{
		return os << "\033[47m";
	}

	template < class CharT, class Traits >
	constexpr
		std::basic_ostream< CharT, Traits >& Black(std::basic_ostream< CharT, Traits >& os)
	{
		return os << "\033[40m";
	}

}


class Console
{

public:
	void hideCursor(bool);
	void changeSize(int,int);
	void gotoXY(int,int);

};


#endif
