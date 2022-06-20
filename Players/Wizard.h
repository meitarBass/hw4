//
// Created by Meitar Basson on 07/06/2022.
//

#ifndef HW4_WIZARD_H
#define HW4_WIZARD_H

#include "Player.h"

class Wizard: public Player {
public:
    /*
    * C'tor of Wizard class
    *
    */
    Wizard(const std::string &name);

    /*
    * D'tor of Wizard class
    *
    * @return
    *      Safely delete wizard object.
    */
    ~Wizard() = default;

    /*
    * Copy constructor of Wizard class
    *
    * @param Wizard - The wizard to copy
    *      A new copy of wizard.
    */
    Wizard(const Wizard&) = default;

    void heal(int amount) override;
    void print(std::ostream &os) const override;
};


#endif //HW4_WIZARD_H
