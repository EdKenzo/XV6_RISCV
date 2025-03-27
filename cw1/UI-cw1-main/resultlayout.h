#ifndef RESULTLAYOUT_H

#define RESULTLAYOUT_H



#include <QtGui>

#include <QList>

#include <QLayout>



class ResultLayout : public QLayout

{

public:

    ResultLayout(): QLayout(){};

    ~ResultLayout();



    void setGeometry(const QRect &rect);



    void addItem(QLayoutItem *item);

    QSize sizeHint() const;

    QSize minimumSize() const;

    int count() const;

    QLayoutItem *itemAt(int) const;

    QLayoutItem *takeAt(int);



//private:

    QList<QLayoutItem*> list_;

};





#endif // RESULTLAYOUT_H




