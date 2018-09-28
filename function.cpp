#include <iostream>

#include "function.h"

#include <fstream>

#include <token1.h>
#include <string.h>
#include <hero.h>

#include <string>
#include <vector>

using namespace std;

ifstream eingabe;
ofstream ausgabe;
vector<heroes>heroesVector;

void function::menu()
{
    cout<<"Welcome to the Hero Association Dataspace!\nTo proceed and load your files please press ENTER."<<endl;
    cin.get();
    cout<<"\nInput path to XML file: ";
    cin>>this->inputFile;
    this->loadxml();
    cout<<"Your file has been loaded."<<endl;
    cout<<"\nInput path to txt file: ";
    cin>>this->inputFile;
    this->loadtxt();
    cout<<"Your file has been loaded."<<endl;

    for(;exit==0;)
    {
        cout<<"--------------"<<endl;
        cout<<"---(C)onvert--"<<endl;
        cout<<"---(E)xit-----"<<endl;
        cout<<"---(S)earch---"<<endl;
        cout<<"--------------"<<endl;
        cout<<"-------C/E/S: "<<endl;
        cin>>menuinput;

        switch(menuinput)
        {
        case 'C': {
        convert();
        break;}
        case 'c': {
        convert();
        break;}

        case 'S': {
        search();
        break;}
        case 's': {
        search();
        break;}

        case 'E':{
        exit=1;
        break;}
        case 'e':{
        exit=1;
        break;}

        default:
        cout<<"You used an unknown command. Please try again."<<endl;;
        break;
        }
      }
}
void function::loadxml()
{
    eingabe.open(this->inputFile);
    ClToken token;

    string name;
    string classification;
    string height;
    string id;
    string heroID;

    zaehler=0;

    for (;;)
    {
        if (token.getToken(eingabe)==0) break;
        for (int i=0;i<token.att.zahlAtt();i++)
        {
           if(strcmp(token.att.zeigeAttName(i),"id")==0)
               {
                id=token.att.zeigeAttWert(i);
               }
        }

        if(strcmp(token.end(),"name")==0)
        {
           name=token.inhalt();
        }
        else if(strcmp(token.end(),"heroID")==0)
        {
           heroID=token.inhalt();
        }
        else if(strcmp(token.end(),"height")==0)
        {
           height=token.inhalt();
        }
        else if(strcmp(token.end(),"classification")==0)
        {
           classification=token.inhalt();
        }
        else if(strcmp(token.end(),"hero")==0)
        {   heroes productObject;

            productObject.id=id;
            productObject.name=name;
            productObject.height=height;
            productObject.classification=classification;
            productObject.heroID=heroID;

            heroesVector.push_back(productObject);
        }
    }
    eingabe.close();
}
void function::loadtxt()
{
    eingabe.open(this->inputFile);

    string id;
    string city;
    string rank;

    zaehler=0;
    zustand=Start;

    for (zaehler=0;;)
            {
            eingabe.get(zeichen);
            if (eingabe.eof())
            {
                puffer[zaehler]='\0';
                rank=puffer;

                for (vector<heroes>::iterator it=heroesVector.begin();it!=heroesVector.end();it++)
                {
                    string storage=it->id;
                   if(strcmp(storage.c_str(),id.c_str())==0)
                   {
                   it->heroinfo.push_back(city);
                   it->heroinfo.push_back(rank);
                   }
                }
                break;
            }

            switch(zeichen)
               {
                case ' ':
                   if (zaehler)
                      {
                       puffer[zaehler]='\0';
                       zaehler=0;
                  if(zustand==Start)
                       {
                        id=puffer;}
                       else
                       {
                       city=puffer;
                       }
                      zustand=inDaten;
                    }
                   break;
                case '\n':
                    if (zaehler)
                       {
                       puffer[zaehler]='\0';
                       rank=puffer;
                       zaehler=0;

                       for (vector<heroes>::iterator it=heroesVector.begin();it!=heroesVector.end();it++)
                       {
                          string storage=it->id;
                          if(strcmp(storage.c_str(),id.c_str())==0)
                          {
                            it->heroinfo.push_back(city);
                            it->heroinfo.push_back(rank);
                          }
                       }
                       zustand=Start;
                    }
                   break;
                default:
                   puffer[zaehler]=zeichen;
                   zaehler++;
                   break;
                   }
                }
        eingabe.close();
    }
void function::convert()
{
    cout<<"Please specify the destination and name of your XML-file: "<<endl;
    cin>>inputFile;

    ausgabe.open(inputFile);
    ausgabe<< "<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n"<<endl;
    ausgabe << "<listHero>\n";
    for (vector<heroes>::iterator it=heroesVector.begin();it!=heroesVector.end();it++)
    {
        ausgabe<<"<hero>\n<data>\n<name id=\""<<it->id<<"\">"<<it->name<<"</name>\n<heroID>"<<it->heroID<<"</heroID>\n";
        ausgabe<<"<height>"<<it->height<<"</height>\n<classification>"<<it->classification<<"</classification>\n</data>\n<details>\n";
        for(int unsigned index=0;index<it->heroinfo.size();index++){
        ausgabe<<"<city>"<<it->heroinfo[index]<<"</city>\n<rank>"<<it->heroinfo[index+1]<<"</rank>\n";index++;
}

        ausgabe << "</details>\n</hero>\n";
    }
    ausgabe << "</listHero>\n";

    cout << "The file has been successfully created.\n" <<endl;
    ausgabe.close();
}
void function::search()
{
    cout<<"Search for name, heroID or classification (S, A, B or C): "<<endl;
    cin>>usersearch;
    cout<<"\nSearch in "<<usersearch<<" for: "<<endl;
    cin.ignore();
    cin.getline(searchinput,100);

    for(int unsigned index=(0);index<heroesVector.size();index++)
    {
        if((strcmp(heroesVector[index].name.c_str(),searchinput)==0&&strcmp(usersearch.c_str(),"name")==0)||
           (strcmp(heroesVector[index].heroID.c_str(),searchinput)==0&&strcmp(usersearch.c_str(),"heroID")==0)||
           (strcmp(heroesVector[index].classification.c_str(),searchinput)==0&&strcmp(usersearch.c_str(),"classification")==0))
        {
            searchresult++;
            cout<<"\n\nname: "<<heroesVector[index].name<<endl;
            cout<<"heroID: "<<heroesVector[index].heroID<<endl;
            cout<<"height: "<<heroesVector[index].height<<endl;
            cout<<"classification: "<<heroesVector[index].classification<<endl;
            cout<<"id: "<<heroesVector[index].id<<"\n\n"<<endl;
         }
    }

    if(searchresult==0)
    {
           cout<<"No results. Please try again."<<endl;
   }
}
