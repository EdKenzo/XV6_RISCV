#include "resultlayout.h"

#include "responsive_label.h"

#include <iostream>



//Result layout contains just the results

void ResultLayout::setGeometry(const QRect &r /* our layout should always fit inside r */ ) {



    QLayout::setGeometry(r);

    int resStartX;

    int resStartY;

    int resHeight;

    int resPerRow = 2;

    int resInRow = 0;

    int resImgY = 0;

    int resImgX = 0;

    int resTextY = 0;

    int resTextX = 0;

    int resImgWidth = 0;

    int resImgHeight = 0;

    int resTextWidth = 0;

    int resTextHeight = 0;

    int resWidth = (r.width()-(10+resPerRow*10))/resPerRow;

    if (r.width()>700){

        resStartY = 40;

        resStartX = 15 + (r.width()-60)/4;

    }

    else {

        resStartX = 10;

        resStartY = 85;

    }

    int resX = resStartX;

    int resY = resStartY;



    // for all the Widgets added in ResponsiveWindow.cpp

    for (int i = 0; i < list_.size(); i++) {

        QLayoutItem *o = list_.at(i);



        try {



            // cast the widget to one of our responsive labels

            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());



            if (label == NULL){ // null: cast failed on pointer

                std::cout << "warning, unknown widget class in layout" << std::endl;

            }



            //User can filter what they are looking for using the search options at the top

            //-Easily accessible to the user on smaller screens

            if (label-> text() == kSearchOptions && r.width() < 700){

                label -> setGeometry(0,5,r.width(), 40);

            }

            //Sort button stays in the top right corner

            //-Very intuitive design as many websites such as Ebay and Amazon have it in the same location

            else if (label-> text() == kSort && r.width() < 700){

                label -> setGeometry(r.width()-70,50,40, 30);

            }





            //Results for mobile phone format

            //- Image can be seen alongside text on the small screen

            //- 1 result per row, trade off for having the result large enough to be clearly displayed



            else if (r.width() < 380){

                if (label -> text() == kSearchResult || label -> text() == kAdvert){

                    resWidth = r.width()-40;

                    resHeight = r.width()/2;

                    label -> setGeometry(resX,resY, resWidth, resHeight);

                    resImgY = resY + 5;

                    resImgX = resX + 5;

                    resTextY = resY + 5;

                    resY += resHeight + 10;



                }

                else if (label -> text() == kResultImage){

                    resImgWidth = ((r.width()-40)*0.6);

                    resTextX = resX + resImgWidth + 10;

                    resImgHeight = (r.width()/2)-10;

                    label -> setGeometry(resImgX,resImgY, resImgWidth, resImgHeight);

                }

                else if (label -> text() == kResultText){

                    resTextWidth = ((r.width()-40)*0.4)-15;

                    resTextHeight = (r.width()/2)-10;

                    label -> setGeometry(resTextX,resTextY, resTextWidth, resTextHeight);

                }

            }







            //Results for Ipads/larger devices

            //- 2 results a row

            else if (r.width()>380 && r.width()<540){

                if (label -> text() == kSearchResult || label->text() == kAdvert ){

                    resWidth = (r.width()-50)/2;

                    resHeight = resWidth;

                    if (resInRow < 2){ //if no. of results in row still less than no. res allowed per row

                        label -> setGeometry(resX,resY, resWidth, resHeight);

                        resImgY = resY + 5;

                        resImgX = resX + 5;

                        resTextX = resX + 5;

                        resX += (resWidth + 10);

                        resInRow += 1;//add to count for number of results

                    }

                    else{

                        resY += resHeight + 10;

                        resX = resStartX;//reset resX

                        resImgY = resY + 5;

                        resImgX = resX + 5;

                        resTextX = resX + 5;

                        label -> setGeometry(resX,resY, resWidth, resHeight);//add result

                        resInRow = 1;

                        resX += (resWidth + 10);

                    }

                }

                else if (label -> text() == kResultImage){

                    resImgWidth = resWidth - 10;

                    resImgHeight = resWidth*0.7-10;

                    resTextY = resImgY + resImgHeight + 5;

                    label -> setGeometry(resImgX,resImgY, resImgWidth, resImgHeight);

                }

                else if (label -> text() == kResultText){

                    resTextWidth = resWidth - 10;

                    resTextHeight = resWidth*0.3-5;



                    label -> setGeometry(resTextX,resTextY, resTextWidth, resTextHeight);

                }



            }



            //Results for even larger devices

            //-3 Results per row

            //-Makes use of the extra space in the window, less scrolling needed to be done by the user

            else if (r.width()>540 && r.width()<700){

                if (label -> text() == kSearchResult || label->text() == kAdvert ){

                    resWidth = (r.width()-60)/3;

                    resHeight = resWidth;

                    if (resInRow < 3){

                        label -> setGeometry(resX,resY, resWidth, resHeight);

                        resImgY = resY + 5;

                        resImgX = resX + 5;

                        resTextX = resX + 5;

                        resX += (resWidth + 10);

                        resInRow += 1;

                    }

                    else{

                        resY += resHeight + 10;

                        resX = resStartX;

                        resImgY = resY + 5;

                        resImgX = resX + 5;

                        resTextX = resX + 5;

                        label -> setGeometry(resX,resY, resWidth, resHeight);//add result

                        resInRow = 1;

                        resX += (resWidth + 10);

                    }

                }

                else if (label -> text() == kResultImage){

                    resImgWidth = resWidth - 10;

                    resImgHeight = resWidth*0.7-10;

                    resTextY = resImgY + resImgHeight + 5;

                    label -> setGeometry(resImgX,resImgY, resImgWidth, resImgHeight);

                }

                else if (label -> text() == kResultText){

                    resTextWidth = resWidth - 10;

                    resTextHeight = resWidth*0.3-5;



                    label -> setGeometry(resTextX,resTextY, resTextWidth, resTextHeight);

                }

            }



            //Largest size for laptops and large screens

            //-3 results per row

            //-Search options moved to the left side, inspired by Amazon

            else if (r.width()>700){

                if (label-> text() == kSearchOptions){

                    label -> setGeometry(0,40,(r.width() - 50)/4, r.height()/3);

                }

                else if (label-> text() == kSort){

                    label -> setGeometry(r.width()-70,5,40, 30);

                }

                else if (label -> text() == kSearchResult || label->text() == kAdvert ){

                    resWidth = (r.width()-60)/4;

                    resHeight = resWidth;

                    if (resInRow < 3){

                        label -> setGeometry(resX,resY, resWidth, resHeight);

                        resImgY = resY + 5;

                        resImgX = resX + 5;

                        resTextX = resX + 5;

                        resX += (resWidth + 10);

                        resInRow += 1;

                    }

                    else{

                        resY += resHeight + 10;

                        resX = resStartX;

                        resImgY = resY + 5;

                        resImgX = resX + 5;

                        resTextX = resX + 5;

                        label -> setGeometry(resX,resY, resWidth, resHeight);

                        resInRow = 1;

                        resX += (resWidth + 10);

                    }

                }

                else if (label -> text() == kResultImage){

                    resImgWidth = resWidth - 10;

                    resImgHeight = resWidth*0.7-10;

                    resTextY = resImgY + resImgHeight + 5;

                    label -> setGeometry(resImgX,resImgY, resImgWidth, resImgHeight);

                }

                else if (label -> text() == kResultText){

                    resTextWidth = resWidth - 10;

                    resTextHeight = resWidth*0.3-5;

                    label -> setGeometry(resTextX,resTextY, resTextWidth, resTextHeight);

                }



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



}



// following methods provide a trivial list-based implementation of the QLayout class

int ResultLayout::count() const {

    return list_.size();

}



QLayoutItem *ResultLayout::itemAt(int idx) const {

    return list_.value(idx);

}



QLayoutItem *ResultLayout::takeAt(int idx) {

    return idx >= 0 && idx < list_.size() ? list_.takeAt(idx) : 0;

}



void ResultLayout::addItem(QLayoutItem *item) {

    list_.append(item);

}



QSize ResultLayout::sizeHint() const {

    return minimumSize();

}



QSize ResultLayout::minimumSize() const {

    return QSize(320,320);

}



ResultLayout::~ResultLayout() {

    QLayoutItem *item;

    while ((item = takeAt(0)))

        delete item;

}


