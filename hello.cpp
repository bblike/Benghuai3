#include "whowillcome.h"

bool ifGameComplete = 0;




void directDamage(compatitors &Attacker, compatitors &Receiver)
{
    if(rand()%100 <= Attacker.accuracy )
    {
    Receiver.HP = Receiver.HP - (Attacker.attack - Receiver.defense);
    }
    Attacker.ifAttacked = 1;
}

void elementDamage(compatitors &Attacker, compatitors &Receiver, int elementAttack, bool ifInitial)
{
    if(Receiver.ifElementDecreased == 1)
    {
        Receiver.HP = Receiver.HP - elementAttack * 0.5;
    }
    else if(Receiver.ifElementImmune == 1)
    {
        Receiver.HP = Receiver.HP;
    }
    else
    {
        Receiver.HP = Receiver.HP - elementAttack;
    }
    if(ifInitial == 1){Attacker.ifAttacked = 1;}
}

void deadJudge(compatitors firstMove, compatitors nextMove)
{
    if(firstMove.HP <= 0)
    {
        ifGameComplete = 1;
        return;
    }
    if(nextMove.HP <= 0)
    {
        ifGameComplete = 1;
        return;
    }
    
}

void KianaPassive(int roundNumber, compatitors &firstMove, compatitors &nextMove)
    {
        if(roundNumber == 1 && firstMove.name == "Kiana Kaslana")
        firstMove.HP += 20;
        if(roundNumber == 1 && nextMove.name == "Kiana Kaslana")
        nextMove.HP += 20;
    }

void KianaMustKill(int roundNumber, compatitors &Attacker, compatitors &Receiver)
    {
        if(Attacker.name == "Kiana Kaslana")
        if(roundNumber == 3 || roundNumber == 6 || roundNumber == 9)
        {
            int tempAttack = Attacker.attack;
            Attacker.attack = 12;
            for(int a = 1;a <= 8;a++)
            directDamage(Attacker, Receiver);
            Attacker.attack = tempAttack;
            Attacker.ifAttacked = 1;
        }

    }

void FuhuaPassive(compatitors &Attacker, compatitors &Receiver)
    {
        if(Attacker.name == "Fuhua"){
        if(Attacker.ifCannotDie == 1 && Attacker.HP <= 0)
        {
            Attacker.ifCannotDie = 0;
            Attacker.ifElementImmune = 1;
            Attacker.HP = 1;
        }
        }
        if(Receiver.name == "Fuhua"){}
        if(Receiver.ifCannotDie == 1 && Receiver.HP <= 0)
        {
            Receiver.ifCannotDie = 0;
            Receiver.ifElementImmune = 1;
            Receiver.HP = 1;
        }
        }   
    
void FuhuaMustKill(int roundNumber, compatitors &Attacker, compatitors &Receiver)
{
    if(roundNumber == 3 && Attacker.name == "Fuhua"){
        int a =rand()%30 + 10;//随机10到30
    elementDamage(Attacker, Receiver, a, 1);
    }
    
} 

void MeiAttack(compatitors &Attacker, compatitors &Receiver)
{
    if(Attacker.name == "Raiden Mei")
    directDamage(Attacker, Receiver);
    elementDamage(Attacker, Receiver, 5, 1);
    int a = rand()%100;
    if(a < 30)
    {
        elementDamage(Attacker, Receiver, 15, 1);
        Receiver.ifMustKillDisabled = 1;
    }
    else
    {
        directDamage(Attacker, Receiver);
    }

}
void BronyaPassive(compatitors &Attacker, compatitors &Receiver)
{
    if(Attacker.name == "Bronya Zaychik")
    {
        Receiver.accuracy = 85;
    }
    if(Receiver.name == "Bronya Zaychik")
    {
        Attacker.accuracy = 85;
    }
}


void BronyaMustKill(int roundNumber, compatitors &Attacker, compatitors &Receiver)
{
    if(Attacker.name == "Bronya Zaychik"){
    if(roundNumber == 3 || roundNumber == 6 || roundNumber == 9){
    int tempattack = rand()%100 +1;
    int previousattack = Attacker.attack;
    Attacker.attack = tempattack;
    directDamage(Attacker, Receiver);
    Attacker.attack = previousattack;
    }
    
    }
}

void SeelePassive(compatitors &Attacker, compatitors &Receiver)
{
    if(Attacker.name == "Seele Vollerei")
    {
        Attacker.HP = Attacker.HP + 7;
        if(Attacker.HP >= 100)
        Attacker.HP = 100;
    }
    if(Receiver.name == "Seele Vollerei")
    {
        Receiver.HP = Receiver.HP + 7;
        if(Receiver.HP >= 100)
        Receiver.HP = 100;
    }
}
void SeeleMustKill(int &roundNumber, compatitors &Attacker, compatitors &Receiver)
{
    if(Attacker.name == "Seele Vollerei" && roundNumber == 4)
    {
        Attacker.accuracy = Attacker.accuracy * 0.85;
        Attacker.attack = Attacker.attack + 77;
        directDamage(Attacker, Receiver);
        Attacker.accuracy = Attacker.accuracy / 0.85;
        Attacker.attack = Attacker.attack - 77;
    }
        if(Attacker.name == "Seele Vollerei" && roundNumber == 8)
    {
        Attacker.accuracy = Attacker.accuracy * 0.85;
        Attacker.attack = Attacker.attack + 77;
        directDamage(Attacker, Receiver);
        Attacker.accuracy = Attacker.accuracy / 0.85;
        Attacker.attack = Attacker.attack - 77;
    }
}

void oneRoundGame(int &roundNumber, compatitors &firstMove, compatitors &nextMove)
{
    //开始阶段（芽衣点燃，是否禁止行动）
    firstMove.ifAttacked = 0;
    nextMove.ifAttacked = 0;
    if(firstMove.burningRecord >= 1){elementDamage(nextMove, firstMove, 5, 0);}
    if(nextMove.burningRecord >= 1){elementDamage(firstMove, nextMove, 5, 0);}
    if(firstMove.burningRecord >=1){firstMove.burningRecord--;}
    if(nextMove.burningRecord >=1){nextMove.burningRecord--;}

    //高速效果（）
        KianaPassive(roundNumber, firstMove, nextMove);
        FuhuaPassive(firstMove, nextMove);
        BronyaPassive(firstMove, nextMove);
        SeelePassive(firstMove, nextMove);
    //高速先攻（）
        KianaMustKill(roundNumber, firstMove, nextMove);
        FuhuaMustKill(roundNumber, firstMove, nextMove);
        BronyaMustKill(roundNumber, firstMove, nextMove);
        SeeleMustKill(roundNumber, firstMove, nextMove);
        if(firstMove.name == "Ralden Mei"){MeiAttack(firstMove, nextMove);}
        else
        if(firstMove.ifAttacked == 0)
        {
        directDamage(firstMove, nextMove);
        }
    //高速结算（禁技，沉默）
    firstMove.ifMustKillDisabled = 0;
        FuhuaPassive(nextMove,firstMove);

    //是否死亡（）
        deadJudge(firstMove, nextMove);

    //低速效果1（）
        KianaPassive(roundNumber, nextMove, firstMove);
        FuhuaPassive(nextMove, firstMove);
        BronyaPassive(nextMove, firstMove);
        SeelePassive(nextMove, firstMove);

    //低速后攻（）
        KianaMustKill(roundNumber, nextMove, firstMove);
        FuhuaMustKill(roundNumber, nextMove, firstMove);
        BronyaMustKill(roundNumber, nextMove, firstMove);
        SeeleMustKill(roundNumber, nextMove, firstMove);
        if(nextMove.name == "Ralden Mei"){MeiAttack(nextMove, firstMove);}
        else
        if(nextMove.ifAttacked == 0)
        {
        directDamage(nextMove, firstMove);
        }


    //低速结算（）
    nextMove.ifMustKillDisabled = 0;
        FuhuaPassive(nextMove,firstMove);
    //是否死亡（）    

        deadJudge(firstMove, nextMove);
    

    //结束回合（解除禁止状态，全局计数器）
    if(firstMove.ifCannotAttack == 1)
    {
        firstMove.ifCannotAttack = 0;
        firstMove.ifStopMoving = 1;
    }
    if(nextMove.ifCannotAttack == 1)
    {
        nextMove.ifCannotAttack = 0;
        nextMove.ifStopMoving = 1;
    }
    roundNumber++;
    cout<<firstMove.name << " HP: "<< firstMove.HP<<endl;
    cout<<nextMove.name << " HP: "<< nextMove.HP<<endl;
}



 string gameSystem(string PlayerA, string PlayerB)
{
    whoWillCome(PlayerA, PlayerB);
    string winner;
    cout<<"PlayerA:"<<Playera.name<<'\n';
    cout<<"PlayerB:"<<Playerb.name<<'\n';
    int roundNumber = 1;
    
    compatitors firstMove = {};
    compatitors nextMove = {};
    //比较阶段（速度）
        if(Playera.speed >= Playerb.speed)
        {
            memcpy(&firstMove, &Playera, sizeof(Playera));
            memcpy(&nextMove, &Playerb, sizeof(Playerb));
        }
        else
        {
            memcpy(&firstMove, &Playerb, sizeof(Playerb));
            memcpy(&nextMove, &Playera, sizeof(Playera));
        }
    
    while(firstMove.HP > 0 && nextMove.HP > 0)
    {
        oneRoundGame(roundNumber, firstMove, nextMove);
        cout<<"Round " << roundNumber << " completed.\n";
        deadJudge(firstMove, nextMove);
        
    };
    if(firstMove.HP > 0)
    winner = firstMove.name;
    else 
    winner = nextMove.name;


    return winner;
}

int main()
{
    string a,b;

    a = "Mei";
    b = "Fuhua";
    string winner;
    winner = gameSystem(a,b);
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"***************************\n";
    cout<<"        " << winner<<'\n';
    cout<<"***************************\n";
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    while(1){};
    



    return 0;
}