#include <iostream>
#include "StupidWolf.h"
#include "Hunterwolf.h"
#include "BFSWolf.h"
#include "map.h"

using namespace std;

void cls()
{

}

map* getmap()
{
    int w,h, lchance, rchance, tchance;
    long maxtick;
    cout << "First, we decide the wolf's line of sight." << endl << "A width of 80 or less and a height of 24 or less is recommended " << endl;
    cout << "The width of its world is :" << endl;
    cin >> w;
    w+=2;
    cout << "The height of it's world is:" << endl;
    cin >> h;
    h+=2;
    cout << "The percentage chance that a LION will appear in new squares:" << endl;
    cin >> lchance;
    cout << "The percentage chance that a RABBIT will appear in new squares:" << endl;
    cin >> rchance;
    cout << "The percentage chance that a TREE will appear in new squares:" << endl;
    cin >> tchance;
    cout << "The maximum number of steps a wolf may take before the simulation ends:" << endl;
    cin >> maxtick;
    return new map(w,h, lchance, rchance, tchance, maxtick);
}

wolf* getwolf()
{
    int wchoice, hthresh;
    wolf* newwolf=NULL;
    cout << "What kind of wolf shall we test?" << endl << "Currently available types are:" << endl;
    ///
    /// ADD NEW WOLF AI CHOICES HERE PLEASE
    ///
    cout << "1. Stupid Wolf" << endl;
    cout << "2. Hunter Wolf" << endl;
    cout << "3. BFS Wolf" << endl;

    while(newwolf==NULL)
    {
        cin >> wchoice;
        switch (wchoice)
        {
        case 1:
            newwolf = new StupidWolf();
            break;
        case 2:
            newwolf = new HunterWolf();
            break;
        case 3:
            newwolf = new BFSwolf();
            break;
        default:
            cout << "Invalid choice..." << endl;
        }
    }
    cout << "How many steps can this wolf take, without food, before dying of hunger?" << endl;
    cin >> hthresh;
    newwolf -> set_hunger_threshold(hthresh);
    return newwolf;
}

int main()
{
    cout << "Welcome to the Wolf AI tester!" << endl;
    char choice='0';
    map * simarea;
    wolf * protag;


    ///
    /// TEST ZONE
    ///
    simarea = new map(20,20, 2, 5, 10, 500);
    protag = new StupidWolf();
    protag -> set_hunger_threshold(20);
    simarea -> placewolf(protag);
    long counter;
    for(int i=0; i<200; i++)
    {
        counter=simarea->run(false);
        cout << "Completed run " << i+1 << " with running total of " << counter << endl;
        protag -> eat();
        map * temp = new map(*simarea);
        delete simarea;
        simarea = temp;
        simarea -> placewolf(protag);
    }
    return 0;
    ///
    /// TEST ZONE
    ///


    do
    {
        switch(choice)
        {
        case '0':
            simarea = getmap();
            protag = getwolf();
            simarea -> placewolf(protag);
            break;
        case '1':
        {
            simarea->run(true);
            protag -> eat();
            map * temp = new map(*simarea);
            delete simarea;
            simarea = temp;
            simarea -> placewolf(protag);
        }
        break;
        case '2':
        {

            cout << "How many times should this run?" << endl;
            int times;
            double avg;
            cin >> times;
            for(int i=0; i<times; i++)
            {
                avg+=simarea->run(false);
                cout << "Completed run " << i+1 << endl;
                protag -> eat();
                map * temp = new map(*simarea);
                delete simarea;
                simarea = temp;
                simarea -> placewolf(protag);
            }
            avg = avg/(double)times;
            cout << "Operation complete - Average Wolf lifespan is " << avg << " steps over " << times << "tests." << endl;
            protag -> eat();
        }
        break;
        case '3':
            delete protag;
            protag = getwolf();
            simarea -> placewolf(protag);
            break;
        default:
            cout << "Invalid choice! (Press any key to return to menu)";
            cin.ignore();
        }
        if (system("CLS")) system("clear");
        cout << "--Menu--" << endl;
        cout << "1. Run a step-by-step visual simulation with current parameters" << endl;
        cout << "2. Run a bulk simulation with current parameters" << endl;
        cout << "3. Change current wolf's AI mode" << endl;
        cout << "0. Change simulation parameters" << endl;
        cout << "e. Exit the program" << endl;
        cin >> choice;
        cin.ignore();
    }
    while(choice!='e');
    delete simarea;
//    delete protag; //Map deletes it on it's own
    return 0;
}
