
#include "includes.h"
struct compatitors
{
    string name;                                      //name
    int HP;                                             
    int attack;
    int defense;
    int accuracy;                                       //4 figure
    int speed;                                          //really fast = 10
                                                        //fast = 8
                                                        //middle = 6
                                                        //slow = 4
                                                        //really slow = 2
    string passive;
    string mustKill;
    bool ifElementDecreased;                            //For Theresa
    bool ifAttackDecreased;                             //By Kallen
    bool ifDamageIncreased;                             //By Sakura
    bool ifDamageIncreaasedNextTurn;                    //For Himeko
    bool ifCannotAttack;                                //By Mei & Himeko & Rosalita
    bool ifCannotDie;                                   //For Fu hua
    bool ifElementImmune;                               //For Fu hua
    bool ifDamageReversed;                              //For Liliya
    int burningRecord;   
    bool ifStopMoving;   
    bool ifAttacked;                               //By Sakura
    bool ifMustKillDisabled;
};


compatitors Kiana =
    {
        "Kiana Kaslana",
        100,
        23,
        11,
        100,
        4,
        "increasd 20 HP",
        "12 damage with 8 times every 3 rounds",
        0,
        0,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
        0,
        0,
        0
//ensure
    };


    compatitors Fuhua =
    {
        "Fuhua",
        100,
        27,
        8,
        100,
        10,
        "don't die for the first time and then immune element",
        "random 10-30 element damage every 3 turns",
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
        //ensure
    };
    compatitors Mei =
    {
        "Ralden Mei",
        100,
        26,
        6,
        100,
        6,
        "5 element damage when attack",
        "15 element damage and ban with 30% posibility",
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
        //ensure
    };
    compatitors Bronya=
    {
        "Bronya Zaychik",
        100,
        26,
        8,
        100,
        2,
        "miss for 15%",
        "ramdon damage form 1-100 every 3 rounds",
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
        //ensure
    };
    compatitors Seele  =
    {
        "Seele Vollerei",
        100,
        23,
        10,
        100,
        10,
        "restore 7 HP every round",
        "100 damage every 4 rounds with 85% accuracy",
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
    };
    compatitors Theresa =
    {
        "Theresa Apocalypse",
        100,
        24,
        8,
        100,
        2,
        "decrease 50% element damage received",
        "ramdon 1-16 element damage every 2 rounds",
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
        //ensure
    };
    compatitors Kallen =
    {
        "Kallen Kaslana",
        100,
        26,
        6,
        100,
        10,
        "5% to win",
        "decrease 15 enemy attack for 2 rounds with 30% posibility",
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
        //ensure
    };
    compatitors Himeko =
    {
        "Murata Himeko",
        100,
        24,
        10,
        100,
        2,
        "increase 50% attack and defense when HP below 40%",
        "30% to stop attack and deal 200% element attack next turn",
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
        //ensure
    };
    compatitors Rita =
    {
        "Rita Rossweisse",
        100,
        26,
        8,
        100,
        6,
        "restore health equal to damage for 30% posibility",
        "20% ban",
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
        //ensure
    };
    compatitors Rozaliya=
    {
        "Rosaliya Olenyeva",
        100,
        30,
        4,
        100,
        8,
        "30% damage rise 50% and 30% damage fall 50%",
        "15 damage for 10 times and stop next turn",
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
        //ensure
    };
    compatitors Liliya=
    {
        "Liliya Olenyeva",
        100,
        20,
        11,
        100,
        8,
        "win after 7 round",
        "15% immune and reverse damage",
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
        //ensure
    };
    compatitors Sakura=
    {
        "Yae Sakura",
        100,
        28,
        7,
        100,
        8,
        "20% burn and deal 5 element damage for 3 turns",
        "damage double(after consider the defense) for 25%",
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
        //ensure
    };

    compatitors Playera = {};
    compatitors Playerb = {};
