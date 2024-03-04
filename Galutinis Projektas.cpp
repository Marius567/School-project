#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <random>
#include <time.h>
#include <windows.h>
using namespace std;

int NOP;
vector<int> Balance;


int Start(){
    system("cmd /c \"color F0\"");
    string input;
    cout<<"Do you want to start?"<<endl;
    cout<<"[Y]      [N]"<<endl;
    cin>>input;
    if(input=="y" || input=="Y"){
        system("cls");
        cout<<"How many players? (1-3)"<<endl;
        cin>>NOP;
        system("cls");
        for(int i=0; i<NOP; i++){
            Balance.push_back(100);
        }
    }
    else if(input=="n" || input=="N"){
        system("cls");
        exit(0);
    }
    else{
        cout<<"???"<<endl;
        Start();
    }
    return 1;
}

void Countdown(){
    system("cls");
 cout<<"        "<<"$$$$$$\ "<<endl;
cout<<"        "<<"$$ ___$$\ "<<endl;
cout<<"        "<<"\_/   $$ |"<<endl;
cout<<"        "<<"  $$$$$ / "<<endl;
 cout<<"        "<<" \___$$\ "<<endl;
cout<<"        "<<"$$\   $$ |"<<endl;
cout<<"        "<<"\$$$$$$  |"<<endl;
cout<<"        "<<" \______/ "<<endl;
Sleep(1000);
system("cls");

cout<<"        "<<" $$$$$$\  "<<endl;
cout<<"        "<<"$$  __$$\ "<<endl;
cout<<"        "<<"\__/  $$ |"<<endl;
 cout<<"        "<<"$$$$$$  |"<<endl;
cout<<"        "<<"$$  ____/ "<<endl;
cout<<"        "<<"$$ |      "<<endl;
cout<<"        "<<"$$$$$$$$\ "<<endl;
cout<<"        "<<"\________|"<<endl;
Sleep(1000);
system("cls");


cout<<"        "<<"  $$\   "<<endl;
cout<<"        "<<"$$$$ |  "<<endl;
cout<<"        "<<"\_$$ |  "<<endl;
cout<<"        "<<"  $$ |  "<<endl;
cout<<"        "<<"  $$ |  "<<endl;
cout<<"        "<<"  $$ |  "<<endl;
cout<<"        "<<"$$$$$$\ "<<endl;
cout<<"        "<<"\______|"<<endl;
Sleep(1000);
}

void Spin(){
    string input;
    int RandomNumber, temp=0;
    vector<int> BetAm;
    vector<string> BetPlc;
    int p=0, n=0;
    int trash=0;
    trash=NOP;

    system("cmd /c \"color F0\"");

    cout<<"Insert bet amount $$$"<<endl;
    cout<<"[Y] to continue"<<endl;
    cin>>input;

    if(input=="y" || input=="Y"){
    while(p<NOP){
    cout<<"Player "<<NOP-(trash-1-p+n)<<": ";
    cin>>temp;
    if (temp>Balance[p]){
        cout<<"Please bet a valid amount (can't be more than Balance total)"<<endl;
        temp=0;
        cout<<"Player "<<NOP-(trash-1-p+n)<<": ";
        cin>>temp;
    }
    BetAm.push_back(temp);
    Balance[p]=Balance[p]-temp;
    p++;
    }

    system("cls");
    cout<<"Bet placement"<<endl;
    cout<<"[G] for green"<<endl;
    cout<<"[R] for red"<<endl;
    cout<<"[B] for black"<<endl;
    p=0;

    while(p<NOP){
    cout<<"Player "<<NOP-(trash-1-p+n)<<": ";
    cin>>input;
    BetPlc.push_back(input);
    p++;
    }

    p=0;
    Countdown();
    system("cls");

    srand(time(0));
    RandomNumber=0 + (rand() % ( 37 - 0 ) );
    if(RandomNumber>0&&RandomNumber<11 || RandomNumber>18&&RandomNumber<29){
        if(RandomNumber%2==0){
            system("cmd /c \"color 4F\"");
            cout<<"Red wins"<<endl;
            while(p<NOP){
            if(BetPlc[p]=="R" || BetPlc[p]=="r"){
            Balance[p]=Balance[p]+(BetAm[p]*2);
                }
            cout<<"Player "<<NOP-(trash-1-p+n)<<" Balance: "<<Balance[p]<<endl;
            p++;
            }
        }
        else{
            system("cmd /c \"color 0F\"");
            cout<<"Black wins"<<endl;
            while(p<NOP){
            if(BetPlc[p]=="B" || BetPlc[p]=="b"){
            Balance[p]=Balance[p]+(BetAm[p]*2);
                }
            cout<<"Player "<<NOP-(trash-1-p+n)<<" Balance: "<<Balance[p]<<endl;
            p++;
            }
        }
    }
    else if(RandomNumber>10&&RandomNumber<19 || RandomNumber>28&&RandomNumber<37){
        if (RandomNumber%2==0){
            system("cmd /c \"color 0F\"");
            cout<<"Black wins"<<endl;
            while(p<NOP){
            if(BetPlc[p]=="B" || BetPlc[p]=="b"){
            Balance[p]=Balance[p]+(BetAm[p]*2);
                }
            cout<<"Player "<<NOP-(trash-1-p+n)<<" Balance: "<<Balance[p]<<endl;
            p++;

            }
        }
        else{
            system("cmd /c \"color 4F\"");
            cout<<"Red wins"<<endl;
            while(p<NOP){
            if(BetPlc[p]=="R" || BetPlc[p]=="r"){
            Balance[p]=Balance[p]+(BetAm[p]*2);
                }
            cout<<"Player "<<NOP-(trash-1-p+n)<<" Balance: "<<Balance[p]<<endl;
            p++;
            }
        }
    }
    else if(RandomNumber==0){
        system("cmd /c \"color 2F\"");
        cout<<"Green wins"<<endl;
        while(p<NOP){
        if(BetPlc[p]=="G" || BetPlc[p]=="g"){
        Balance[p]=Balance[p]+(BetAm[p]*35);
            }
        cout<<"Player "<<NOP-(trash-1-p+n)<<" Balance: "<<Balance[p]<<endl;
        p++;
            }
        }
    }

    for(int o=0; o<trash; o++){
        if(Balance[o]<1){
            cout<<"Player "<<o+1<<" has lost all their money!"<<endl;
            NOP--;
            n++;
        }
    }
    if(NOP==0){
        cout<<"All players have gambled away all of their money!!!"<<endl;
        cout<<"The fun ends :("<<endl;
        return;
    }

    if(NOP!=0){
    cout<<"Do you want to continue?"<<endl;
    cout<<"[Y]      [N]"<<endl;
    cin>>input;
        if(input=="y" || input=="Y"){
        system("cls");
        BetAm.clear();
        BetPlc.clear();
        Spin();
    }
        else if(input=="n" || input=="N"){
        system("cls");
        cout<<"Thank you for playing!";
    }
}
}

void Output(){
    ofstream outfile ("Winnings.txt");
    outfile<<"Player 1 balance: "<<Balance[0]<<" (Winnings: "<<Balance[0]-100<<")"<<endl;
    if(Balance[1]<1&&NOP>1) outfile<<"Player 2 balance: "<<Balance[1]<<" (Winnings: "<<Balance[1]-100<<")"<<endl;
    if(Balance[2]<1&&NOP>2) outfile<<"Player 3 balance: "<<Balance[2]<<" (Winnings: "<<Balance[2]-100<<")"<<endl;
}


int main()
{

    Start();
    Spin();

    Output();

    return 0;
}
