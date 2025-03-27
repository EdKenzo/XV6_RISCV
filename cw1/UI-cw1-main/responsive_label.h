//
// Created by twak on 14/10/2019.
//

#ifndef RESPONSIVELABEL_H
#define RESPONSIVELABEL_H


#include <QLabel>
#include <QString>
#include <map>

//using namespace std;

// Please add to, but DO NOT modify the existing constants in this file.
// label names that are displayed
const QString
        kHomeLink       = "home",
        kShoppingBasket = "basket",
        kSignIn         = "sign-in",
        kMenu           = "menu",
        kNavTabs        = "navigation tabs",
        kAdvert         = "advert",
        kSearchButton   = "search",
        kSearchResult   = "result",
        kResultImage    = "result image",
        kResultText     = "result text",
        kSearchText     = "search query",
        kSearchForward  = ">",
        kSearchBackward = "<",
        kSearchOptions  = "search options",
        //2 extra labels
        kWishList      = "wish-list",
        //kSale           = "on sale";
        kSort          = "sort by";

// every label name has a colour
const std::map<QString, QString> kColours = {
        std::make_pair(kMenu,           "#A9FFAA"),
        std::make_pair(kHomeLink,       "#ffaaff"),
        std::make_pair(kShoppingBasket, "#FECFF2"),
        std::make_pair(kSignIn,         "#FEDCCF"),
        std::make_pair(kNavTabs,        "#ffa9d3"),
        std::make_pair(kAdvert,         "#ffaa66"),
        std::make_pair(kSearchButton,   "#aaffff"),
        std::make_pair(kSearchResult,   "#99ddff"),
        std::make_pair(kResultImage,    "#bdd3d0"),
        std::make_pair(kResultText,     "#fff763"),
        std::make_pair(kSearchText,     "#aaaaff"),
        std::make_pair(kSearchForward,  "#5caeff"),
        std::make_pair(kSearchBackward, "#5caeff"),
        std::make_pair(kSearchOptions,  "#9dceff"),
        std::make_pair(kWishList,      "#FECFDB"),
        //std::make_pair(kSale,           "#A9FFD5"),
        std::make_pair(kSort,           "#A9FFD5"),



};

class ResponsiveLabel : public QLabel {
public:
    ResponsiveLabel(QString name) ;
    ResponsiveLabel(QString name, QString colour) ;
};


#endif // RESPONSIVELABEL_H
