#ifndef ITEMS_H_INCLUDED
#define ITEMS_H_INCLUDED

#include <string>
#include <vector>

class namedData
{
public:
    std::string Name;
};

class Material : public namedData
{
    std::string color;
    int hardness;

};

class Item;

class EnchantmentOrQuality : public namedData
{
public:
    std::string ModifierText;
    int IsPrefix; //if zero the ModifierText is added to the end of the item description.
    Material mat; //the material the modifier is made from, this is a type of magic in the case of Enchantments, or "Raw story" for the items history
    Item* DoublesAs;
    /*
     if the Enchantment is simply that this item can be used as another item then "DoubleAs"
     variable is an instance of Item and the 'mat' variable will be the same as that Item's primaryMat.
     If this is a normal Enchantment then this variable is 0;
    */
};

class Item : public namedData
{
public:
    std::vector<EnchantmentOrQuality> modifiers;
    Material primaryMat;
    std::string constructionQuality; //this string is there to describe how well made the item is.
};

void initItemsList();
void initMaterialsList();

#endif // ITEMS_H_INCLUDED
