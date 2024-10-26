#include <iostream>
#include <string>
#include "EquipSpell.h"
#include "Effects.h"

EquipSpell::EquipSpell(std::string Name,int change, bool enemy){
    setname(Name);
    setchange(change);
    settarget(enemy);
}
 EquipSpell:: EquipSpell(){
        setname("DEFAULT");
    }
    void EquipSpell::setboard(Board* own){
        ownboard=own;
    }
    void EquipSpell::setchange(int change){
        Change=change;
    }
    int EquipSpell::getchange(){
        return Change;
    }

    void EquipSpell::settarget(bool enemy){
        Effectsenemy=enemy;
    }

    bool EquipSpell::gettarget(){
        return Effectsenemy;
    }


    void EquipSpell::effect(Monster* target){
        Target=target;
        target->changeattack(Change);

    }

    void EquipSpell::Display(){
        std::cout<<getname()<<" - adds "<<getchange()<<std::endl;
    }

    EquipSpell::~EquipSpell(){
        std::cout<<"SELF DESTRUCT WOWWA"<<std::endl;
       Target->changeattack(-Change);
    }
    

 void EquipSpell::TESTADDEFFECT(Effect* addnew){
    eList.push_back(addnew);
    std::cout<<"EFFECT ADDED"<<std::endl;
 }
 void EquipSpell::TESTEFFECT(){

    for(int i=0;i<eList.size();i++){

        if(eList[i]->requirestargetboard()){
            char a;
            std::cout<<"Target own board - 1        Target enemy board - 2"<<std::endl;
            std::cin>>a;
            if(a=1){
            std::cout<<"trying to set targetboard"<<std::endl;
            std::cout<<Owner->getownboard()<<std::endl;
            eList[i]->settargetboard(Owner->getownboard());
            std::cout<<"targetboard set and calling activate"<<std::endl;
              eList[i]->activate();
                
            } else {
                 eList[i]->settargetboard(Owner->getenemyboard());
            }
        }

    }
 }
