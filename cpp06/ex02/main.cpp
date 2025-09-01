/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:59:38 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/09/01 14:16:43 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void)
{
	int random = rand() % 3;
	std::cout << "Random number: " << random << std::endl;
    switch (random)
    {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
		default: return NULL;
    }
}

static void		identify(Base* p) {
	
	if (A *a = dynamic_cast<A *>(p)) {
		(void)a;
		std::cout << "Pointer type is A" << std::endl;
		return ;
	}
	if (B *b = dynamic_cast<B *>(p)) {
		(void)b;
		std::cout << "Pointer type is B" << std::endl;
		return ;
	}
	if (C *c = dynamic_cast<C *>(p)) {
		(void)c;
		std::cout << "Pointer type is C" << std::endl;
		return ;
	}
	std::cout << "Unknown pointer type" << std::endl;
}

static void	identify(Base& p) {
	try {
		A & a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Reference type is A" << std::endl;
		return ;
	}
	catch ( std::bad_cast &bc ) { }
	try {
		B & b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "Reference type is B" << std::endl;
		return ;
	}
	catch ( std::bad_cast &bc ) { }
	try {
		C & c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "Reference type is C" << std::endl;
		return ;
	}
	catch ( std::bad_cast &bc ) { }
	std::cout << "Unknown reference type" << std::endl;
}

int main(void)
{    
	srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        std::cout << "\n--- Run " << (i + 1) << " ---" << std::endl;
        Base *base = generate();
        identify(base);
        identify(*base);
        delete base;
    }

    return (0);
}