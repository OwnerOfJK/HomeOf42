/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:53:05 by jkaller           #+#    #+#             */
/*   Updated: 2024/12/11 20:52:24 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    public:
    Cat();
    Cat(const Cat &src);
    Cat &operator=(const Cat &rhs);
    ~Cat();
    void makeSound() const;
    // void setIdea(const std::string &idea);
    // const std::string &getIdea(int index) const;

    private:
    Brain *cat_brain;
};

#endif