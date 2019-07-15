#include "include/includes.h"

#include "include/backgrounds.h"

bool ifGameComplete = 0;


void whoWillCome(string PlayerA, string PlayerB)
{ 

    if(PlayerA == "Kiana")
    memcpy(&Playera, &Kiana, sizeof(Kiana));
    if(PlayerA == "Mei")
    memcpy(&Playera, &Mei, sizeof(Mei));
    if(PlayerA == "Fuhua")
    memcpy(&Playera, &Fuhua, sizeof(Fuhua));
    if(PlayerA == "Theresa")
    memcpy(&Playera, &Theresa, sizeof(Theresa));
    if(PlayerA == "Bronya")
    memcpy(&Playera, &Bronya, sizeof(Bronya));
    if(PlayerA == "Himeko")
    memcpy(&Playera, &Himeko, sizeof(Himeko));
    if(PlayerA == "Sakura")
    memcpy(&Playera, &Sakura, sizeof(Sakura));
    if(PlayerA == "Liliya")
    memcpy(&Playera, &Liliya, sizeof(Liliya));
    if(PlayerA == "Rosaliya")
    memcpy(&Playera, &Rozaliya, sizeof(Rozaliya));
    if(PlayerA == "Rita")
    memcpy(&Playera, &Rita, sizeof(Rita));
    if(PlayerA == "Kallen")
    memcpy(&Playera, &Kallen, sizeof(Kallen));
    if(PlayerA == "Seele")
    memcpy(&Playera, &Seele, sizeof(Seele));
     
    if(PlayerB == "Kiana")
    memcpy(&Playera, &Kiana, sizeof(Kiana));
    if(PlayerB == "Mei")
    memcpy(&Playera, &Mei, sizeof(Mei));
    if(PlayerB == "Fuhua")
    memcpy(&Playera, &Fuhua, sizeof(Fuhua));
    if(PlayerB == "Theresa")
    memcpy(&Playera, &Theresa, sizeof(Theresa));
    if(PlayerB == "Bronya")
    memcpy(&Playera, &Bronya, sizeof(Bronya));
    if(PlayerB == "Himeko")
    memcpy(&Playera, &Himeko, sizeof(Himeko));
    if(PlayerB == "Sakura")
    memcpy(&Playera, &Sakura, sizeof(Sakura));
    if(PlayerB == "Liliya")
    memcpy(&Playera, &Liliya, sizeof(Liliya));
    if(PlayerB == "Rosaliya")
    memcpy(&Playera, &Rozaliya, sizeof(Rozaliya));
    if(PlayerB == "Rita")
    memcpy(&Playera, &Rita, sizeof(Rita));
    if(PlayerB == "Kallen")
    memcpy(&Playera, &Kallen, sizeof(Kallen));
    if(PlayerB == "Seele")
    memcpy(&Playera, &Seele, sizeof(Seele));
        
    if(PlayerA == PlayerB)
    {
        cout<<"Competitors Failure. Enter '1' to continue. Enter '2' to exit.\n";
        string a;
        cin>>a;
        if(a == "李锗均最帅，我要一起来！")
            {}
            else 
            return;

    }




}

void derectDamage(compatitors &Attacker, compatitors &Receiver)
{
    Receiver.HP = Receiver.HP - (Attacker.attack - Receiver.defense);
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

void deadJudge()
{
    if(Playera.HP <= 0)
    {
        ifGameComplete = 1;
        return;
    }
    if(Playerb.HP <= 0)
    {
        ifGameComplete = 1;
        return;
    }
    
}

void KianaPassive(int roundNumber)
    {
        if(roundNumber == 1 && Playera.name == "Kiana Kaslana")
        Playera.HP += 20;
        if(roundNumber == 1 && Playerb.name == "Kiana Kaslana")
        Playerb.HP += 20;
    }

void KianaMustKill(int roundNumber, compatitors &Attacker, compatitors &Receiver)
    {
        if(roundNumber == 3 && Attacker.name == "Kiana Kaslana")
        Receiver.HP = Receiver.HP - 8 *(Attacker.attack - Receiver.defense);

    }

void FuhuaPassive()
    {
        if(Playera.ifCannotDie == 1 && Playera.HP <= 0)
        {
            Playera.ifCannotDie = 0;
            Playera.ifElementImmune = 1;
            Playera.HP = 1;
        }
        if(Playerb.ifCannotDie == 1 && Playerb.HP <= 0)
        {
            Playerb.ifCannotDie = 0;
            Playerb.ifElementImmune = 1;
            Playerb.HP = 1;
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
    derectDamage(Attacker, Receiver);
    elementDamage(Attacker, Receiver, 5, 1);
    int a = rand()%100;
    if(a < 30)
    {
        elementDamage(Attacker, Receiver, 15, 1);
        Receiver.ifMustKillDisabled = 1;
    }

}

void oneRoundGame(int &roundNumber, compatitors &firstMove, compatitors &nextMove)
{
    //开始阶段（芽衣点燃，是否禁止行动）
    if(firstMove.burningRecord >= 1){elementDamage(nextMove, firstMove, 5, 0);}
    if(nextMove.burningRecord >= 1){elementDamage(firstMove, nextMove, 5, 0);}
    if(firstMove.burningRecord >=1){firstMove.burningRecord--;}
    if(nextMove.burningRecord >=1){nextMove.burningRecord--;}

    //高速效果（）
        
    //高速先攻（）
        if(roundNumber == 2 || roundNumber == 4 || roundNumber == 6 || roundNumber == 8)
        {
            
        }
        else if(roundNumber == 3 || roundNumber == 6)    //3回合触发必杀技
        {

        }
        if(firstMove.ifAttacked == 0)
        derectDamage(firstMove, nextMove);

    //高速结算（禁技，沉默）
    firstMove.ifMustKillDisabled = 0;
    

    //是否死亡（）
        deadJudge();

    //低速效果1（）


    //低速后攻（）
        derectDamage(nextMove, firstMove);


    //低速结算（）
    nextMove.ifMustKillDisabled = 0;

    //是否死亡（）    
        deadJudge();
    

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

    while(Playera.HP > 0 && Playerb.HP > 0)
    {
        oneRoundGame(roundNumber, firstMove, nextMove);
        
        deadJudge();
    };
    if(Playera.HP > 0)
    winner = Playera.name;
    else 
    winner = Playerb.name;


    return winner;
}

int main()
{
    string a,b;

    a = "Kiana";
    b = "Mei";
    string winner;
    winner = gameSystem(a,b);
    cout<<winner<<'\n';
    while(1){};
    



    return 0;
}