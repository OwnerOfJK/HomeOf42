/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:04:00 by jkaller           #+#    #+#             */
/*   Updated: 2024/09/15 19:06:42 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
    public:
    Brain();
    Brain(const Brain &src);
    Brain &operator=(const Brain &rhs);
    ~Brain();
    // void setIdea(const std::string &idea);
    // const std::string &getIdea() const;

    private:
    std::string ideas[100];
};

#endif