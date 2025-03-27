//

// Created by twak on 14/10/2019.

//



#include "responsive_window.h"

#include "responsive_layout.h"

#include "screenshot.h"

#include <iostream>

#include <QApplication>

#include <QWidget>

#include <QScrollArea>







ResponsiveWindow::ResponsiveWindow() {



    setWindowTitle("2811: Coursework 1");

    setMinimumSize(320, 320);

    setMaximumSize(1280, 720);

    createWidgets();



}



void ResponsiveWindow::createWidgets(){



    ResponsiveLayout * rl = new ResponsiveLayout();





    // add all the widgets we need to demonstrate all layouts

    //Widgets here are not within the scroll area, this is because I want these widgets to be accessible to the user at any point

    rl->addWidget(new ResponsiveLabel(kNavTabs));

    rl->addWidget(new ResponsiveLabel(kMenu));

    rl->addWidget(new ResponsiveLabel(kHomeLink));

    rl->addWidget(new ResponsiveLabel(kShoppingBasket));

    rl->addWidget(new ResponsiveLabel(kSignIn));

    rl->addWidget(new ResponsiveLabel(kWishList));

    rl->addWidget(new ResponsiveLabel(kSearchText));

    rl->addWidget(new ResponsiveLabel(kSearchButton));

    rl->addWidget(new ResponsiveLabel(kSearchOptions));





    QScrollArea * scroll = new QScrollArea();



    rl->addWidget(scroll);

    scroll->show();

    setLayout(rl);

}




