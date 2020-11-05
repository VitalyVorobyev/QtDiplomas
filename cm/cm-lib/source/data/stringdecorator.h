#ifndef STRINGDECORATOR_H
#define STRINGDECORATOR_H

#include <QObject>
#include <QJsonObject>
#include <QJsonValue>
#include <QScopedPointer>
#include <QString>

#include "cm-lib_global.h"
#include "data/datadecorator.h"

namespace cm {
namespace data {

class StringDecorator : public DataDecorator {
    Q_OBJECT
public:
    StringDecorator();
};

}
}

#endif // STRINGDECORATOR_H
