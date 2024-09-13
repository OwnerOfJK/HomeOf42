/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:27:38 by jkaller           #+#    #+#             */
/*   Updated: 2024/09/13 19:27:39 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {
    private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

    public:
    void complain(std::string level);
};

#endif