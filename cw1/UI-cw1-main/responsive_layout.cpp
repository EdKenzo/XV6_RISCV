//

// Created by twak on 07/10/2019.

//


#include "responsive_layout.h"

#include "qscrollarea.h"

#include "responsive_label.h"

#include "resultlayout.h"

#include <iostream>


//using namespace std;


void ResponsiveLayout::setGeometry(const QRect &r /* our layout should always fit inside r */ ) {


    QLayout::setGeometry(r);

    ResultLayout * resLayout = new ResultLayout();


    //Result layout

    // Add results to result layout

    resLayout->addWidget(new ResponsiveLabel(kSearchOptions));

    resLayout->addWidget(new ResponsiveLabel(kSort));


    for (int i=0; i < 17; i++){

        resLayout->addWidget(new ResponsiveLabel(kSearchResult));

        resLayout->addWidget(new ResponsiveLabel(kResultImage));

        resLayout->addWidget(new ResponsiveLabel(kResultText));

    }


    //Add ads to result layout

    //From the context given, I assume ads are similar products to the search the user might be interested in, like in Amazon

    for (int i=0; i < 4; i++){

        resLayout->addWidget(new ResponsiveLabel(kAdvert));

    }


    QWidget * container = new QWidget;

    container->setLayout(resLayout); //container with the layout containing results


    for (int i = 0; i < list_.size()-1; i++) {

        QLayoutItem *o = list_.at(i);

        try {

            // cast the widget to one of our responsive labels


            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());


            if (label == NULL){ // null: cast failed on pointer

                std::cout << "warning, unknown widget class in layout" << std::endl;

            }

            else if (label -> text() == kNavTabs ){ // headers go at the top

                label -> setGeometry(0+r.x(),40+r.y(),r.width(), 40);

            }

            else if (label -> text() == kHomeLink){

                label -> setGeometry(5+r.x(),5 + r.y(), 50, 30);

            }

            else if (label -> text() == kMenu){

                label -> setGeometry(5+r.x(), 45+r.y(),50,30);

            }


            else if (label -> text() == kSignIn){

                label -> setGeometry(r.width() - 90+r.x(), 5+r.y(),40,30);

            }

            //Wish list added at the top, easily accessible at any point

            else if (label -> text() == kWishList){

                label -> setGeometry(r.width() - 135+r.x(), 5+r.y(),40,30);

            }

            else if (label -> text() == kShoppingBasket){

                label -> setGeometry(r.width() - 45+r.x(), 5+r.y(),40,30);

            }

            else if (label -> text() == kSearchText && r.width() > 500){

                label -> setGeometry(115+r.x(),5 + r.y(), r.width()-295,30);

            }

            // only show a search button on small resolution, at the right of the window

            else if (label -> text() == kSearchButton){

                label -> setGeometry(r.width() - 180+r.x(),5+r.y(),40, 30);

            }


            else {// otherwise: disappear label by moving out of bounds

                label -> setGeometry (-1,-1,0,0);

            }


        }

        catch (std::bad_cast) {

            // bad_case: cast failed on reference...

            std::cout << "warning, unknown widget class in layout" << std::endl;

        }

    }



    //Setting the height of container

    if (r.width() < 380){

        container->setGeometry(0,80,r.width(),22*(r.width()/2)+220);//Set minimum height to number of results*height of results

    }

    else if (r.width() > 380 && r.width() < 540){

        container->setGeometry(0,80,r.width(),11*(r.width()-50)/2 +275);//Set minimum height to number of results*height of results

    }

    else if (r.width() > 540 && r.width() < 700){

        container->setGeometry(0,80,r.width(),7*(r.width()-60)/3 + 240);//Set minimum height to number of results*height of results

    }

    else if (r.width() > 700){

        container->setGeometry(0,80,r.width(),7*(r.width()-50)/4 + 170);//Set minimum height to number of results*height of results

    }


    //Initialise last item in list (scroll)

    QLayoutItem* last = list_.last();

    QScrollArea* scroll = dynamic_cast<QScrollArea*>(last->widget());

    //Implementing scroll area

    scroll->setWidget(container);

    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scroll->setGeometry(0,80,r.width(),r.height());

}



// following methods provide a trivial list-based implementation of the QLayout class

int ResponsiveLayout::count() const {

    return list_.size();

}


QLayoutItem *ResponsiveLayout::itemAt(int idx) const {

    return list_.value(idx);

}


QLayoutItem *ResponsiveLayout::takeAt(int idx) {

    return idx >= 0 && idx < list_.size() ? list_.takeAt(idx) : 0;

}


void ResponsiveLayout::addItem(QLayoutItem *item) {

    list_.append(item);

}


QSize ResponsiveLayout::sizeHint() const {

    return minimumSize();

}


QSize ResponsiveLayout::minimumSize() const {

    return QSize(320,320);

}


ResponsiveLayout::~ResponsiveLayout() {

    QLayoutItem *item;

    while ((item = takeAt(0)))

        delete item;

}

