#ifndef NAVIGATIONCONTROLLER_H
#define NAVIGATIONCONTROLLER_H

#include <QObject>

#include "cm2-lib_global.h"
#include "client.h"

namespace cm2 {
namespace controllers {

class CM2LIB_EXPORT NavigationController : public QObject {
    Q_OBJECT

 public:
    explicit NavigationController(QObject* _parent=nullptr):
        QObject(_parent) {}

 signals:
    void goAddDiplomaView();
    void goDashboardView();
    void goEditDiplomaView(cm2::models::Client* client);
    void goFindDiplomaView();

};

}}

#endif // NAVIGATIONCONTROLLER_H
