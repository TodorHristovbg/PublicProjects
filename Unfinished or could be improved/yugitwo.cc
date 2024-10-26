#include <iostream>
#include <time.h>  
#include "card.h"
#include "Monster.h"
#include "Spell.h"
#include "EquipSpell.h"
#include "Board.h"
#include "Player.h"
#include "gameplay.h"
#include "Effects.h"


int main(){

    Player player("Bobr");
    Board a;
    player.setownboard(&a);

    std::cout<<player.getownboard()<<std::endl;

    EquipSpell sword("Testneweffect",500,1);
    ChangeAttackEffect neweffect(1);       //IS CHAR AND OVERFLOWS
    sword.TESTADDEFFECT(&neweffect);
    sword.setowner(&player);
    
    Monster monstertest("Bober",0,0,1,&player);
    player.Draw(&monstertest);
     player.Draw(&sword);
     player.displayhand();
    player.Play(0);
    sword.TESTEFFECT();
    player.displayboard();
    //player.Play(1);






    /*
   std::string name;

    std::cout<<"Name of first player"<<std::endl;
    std::cin>>name; 
    Player player1(name);

                                                      //ERROR SOMEWHERE IN DISPLAYBOARD V BOARD.CC NZ

    std::cout<<"Name of second player"<<std::endl;
    std::cin>>name; 
    Player player2(name);

    whogoesfirst(&player1,&player2);
*/
    return 0;
}
