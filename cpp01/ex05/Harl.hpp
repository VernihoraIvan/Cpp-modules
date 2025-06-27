/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:17:58 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/06/27 12:29:18 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H 
# define HARL_H

#include <string>
#include <iostream>

class Harl
{
    public:
        Harl(void);
        ~Harl(void);

        void complain(std::string level);

    private:
        void    debug( void );
        void    info( void );
        void    warning( void );
        void    error( void );
};

#endif