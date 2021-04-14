

#include "Items.h"
#include <stdio.h>
#include <time.h>

using namespace std;

vector<Item> ItemsList;
vector<Material> MaterialsList;
vector<string> ItemShapesList;
vector<string> ColorList;

void initLists();

void printItem();

int main()
{
    initLists();
    srand(time(0));

    /*

    int numOfItems = ItemShapesList.size();
    int numOfMats = MaterialsList.size();
    int numOfCOlors = ColorList.size();
    string randItem = (ItemShapesList[rand()%numOfItems]);
    Material randMat = (MaterialsList[rand()%numOfMats]);
    string randColor = (ColorList[rand()%numOfCOlors]);

    printf("%s colored %s made of %s\n\n",randColor.c_str(),randItem.c_str(),randMat.Name.c_str());

    randItem = (ItemShapesList[rand()%numOfItems]);
    randMat = (MaterialsList[rand()%numOfMats]);
    randColor = (ColorList[rand()%numOfCOlors]);

    printf("%s colored %s made of %s\n\n",randColor.c_str(),randItem.c_str(),randMat.Name.c_str());
    */
    printItem();
    //system("pause");
    return 0;
}

void printItem()
{
    int numOfItems = ItemShapesList.size();
    int numOfMats = MaterialsList.size();
    int numOfCOlors = ColorList.size();
    string randItem = (ItemShapesList[rand()%numOfItems]);
    Material randMat = (MaterialsList[rand()%numOfMats]);
    string randColor = (ColorList[rand()%numOfCOlors]);
    if( (rand()%100)>50)
    {
        printf("%s colored ",randColor.c_str());
    }

    printf("%s made of %s",randItem.c_str(),randMat.Name.c_str());
    if( (rand()%100)>75)
    {
        printf(", it has seen some wear and tear");
    }
    if( (rand()%100)>75)
    {
        printf(", it is scuffed and scratched");
    }
    if( (rand()%100)>75)
    {
        printf(", it has a thin layer of dust");
    }
    if( (rand()%100)>75)
    {
        printf(", it has patches of mud");
    }
    if( (rand()%100)>75)
    {
        printf(", it has a makers mark of a notable craftsperson");
    }
    if( (rand()%100)>80)
    {
        randMat = (MaterialsList[rand()%numOfMats]);
        printf(", it has spikes of %s",randMat.Name.c_str());
    }
    if( (rand()%100)>80)
    {
        randMat = (MaterialsList[rand()%numOfMats]);
        printf(", it has hanging rings of %s",randMat.Name.c_str());
    }
    if( (rand()%100)>75)
    {
        randItem = (ItemShapesList[rand()%numOfItems]);
        printf(", it might be usable as a %s",randItem.c_str());
    }
    if( (rand()%100)>75)
    {
        randItem = (ItemShapesList[rand()%numOfItems]);
        randMat = (MaterialsList[rand()%numOfMats]);
        randColor = (ColorList[rand()%numOfCOlors]);
        printf(", it can transform into a ");
        if( (rand()%100)>50)
        {
            printf("%s colored ",randColor.c_str());
        }
        printf("%s made of %s ",randItem.c_str(),randMat.Name.c_str());
    }
    printf(".\n\n");

}


void initLists()
{
    FILE* itemFile = fopen("itemTypes.txt","r");
    char itemText[512];
    if(itemFile != NULL)
    {
        while(!feof(itemFile))
        {
            fgets(itemText,512,itemFile);
            string newItem;
            newItem = itemText;

            string::size_type pos = 0;
            while ( ( pos = newItem.find ("\n",pos) ) != string::npos )
            {
            newItem.erase ( pos, 1 );
            }
            pos = 0;
            while ( ( pos = newItem.find ("\r",pos) ) != string::npos )
            {
            newItem.erase ( pos, 1 );
            }

            ItemShapesList.push_back( newItem );
        }
    }
    fclose(itemFile);


    itemFile = fopen("materialTypes.txt","r");
    if(itemFile != NULL)
    {
        while(!feof(itemFile))
        {
            fgets(itemText,512,itemFile);
            Material newMat;
            //newMat.constructionQuality = "";
            newMat.Name = itemText;

            string::size_type pos = 0;
            while ( ( pos = newMat.Name.find ("\n",pos) ) != string::npos )
            {
            newMat.Name.erase ( pos, 1 );
            }
            pos = 0;
            while ( ( pos = newMat.Name.find ("\r",pos) ) != string::npos )
            {
            newMat.Name.erase ( pos, 1 );
            }


            MaterialsList.push_back( newMat );
        }
    }
    fclose(itemFile);


    itemFile = fopen("colors.txt","r");
    if(itemFile != NULL)
    {
        while(!feof(itemFile))
        {
            fgets(itemText,512,itemFile);
            string newColor;
            newColor = itemText;

            string::size_type pos = 0;
            while ( ( pos = newColor.find ("\n",pos) ) != string::npos )
            {
            newColor.erase ( pos, 1 );
            }
            pos = 0;
            while ( ( pos = newColor.find ("\r",pos) ) != string::npos )
            {
            newColor.erase ( pos, 1 );
            }

            ColorList.push_back( newColor );
        }
    }
    fclose(itemFile);
}
