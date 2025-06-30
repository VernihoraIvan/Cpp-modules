/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:16:14 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/06/30 21:41:43 by ivanverniho      ###   ########.fr       */
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
        void    info( void );
        void    warning( void );
        void    error( void );
        void    debug( void );
        std::string parameters_list[4];
};

#endif