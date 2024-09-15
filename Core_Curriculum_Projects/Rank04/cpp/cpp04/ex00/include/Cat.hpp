/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:53:05 by jkaller           #+#    #+#             */
/*   Updated: 2024/09/15 18:53:06 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
    public:
    Cat();
    Cat(const Cat &src);
    Cat &operator=(const Cat &rhs);
    ~Cat();
    void makeSound() const;
};

#endif