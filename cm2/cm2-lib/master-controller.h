#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include <QObject>
#include <QScopedPointer>

#include <cm2-lib_global.h>
#include "navigation-controller.h"
#include "commandcontroller.h"

namespace cm2 {
namespace controllers {

class CM2LIB_EXPORT MasterController : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString ui_welcomeMessage READ welcomeMessage CONSTANT)
    Q_PROPERTY(cm2::controllers::NavigationController*
        ui_navigationController READ navigationController CONSTANT)
    Q_PROPERTY(cm2::controllers::CommandController* ui_commandController READ commandController CONSTANT)

 public:
    explicit MasterController(QObject* parent=nullptr);
    ~MasterController();

    NavigationController* navigationController();
    CommandController* commandController();
    const QString& welcomeMessage() const;

 private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};

}}

#endif // MASTERCONTROLLER_H
