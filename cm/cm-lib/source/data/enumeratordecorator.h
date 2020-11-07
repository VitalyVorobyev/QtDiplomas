#ifndef ENUMERATORDECORATOR_H
#define ENUMERATORDECORATOR_H

#include "datadecorator.h"
#include <QObject>

class EnumeratorDecorator : public DataDecorator
{
    Q_OBJECT
public:
    EnumeratorDecorator();
};

#endif // ENUMERATORDECORATOR_H
