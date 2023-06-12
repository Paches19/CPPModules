/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:59:14 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/12 12:16:57 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << dog->getType() << " sound: ";
    dog->makeSound();
    std::cout << cat->getType() << " sound: ";
    cat->makeSound();

    std::cout << "Generic animal" << " sound: ";
    animal->makeSound();

    delete animal;
    delete dog;
    delete cat;

    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " sound: ";
    wrongCat->makeSound();
    
    std::cout << "Generic Wronganimal" << " sound: ";
    wrongAnimal->makeSound();

    delete wrongAnimal;
    delete wrongCat;

    return 0;
}
