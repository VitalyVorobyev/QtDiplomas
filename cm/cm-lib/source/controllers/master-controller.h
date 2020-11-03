#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include <QObject>
#include <QString>
#include <cm-lib_global.h>

namespace cm {
namespace controllers {

class CMLIBSHAPED_LIBRARY MasterController : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString ui_welcomeMessage MEMBER welcomeMessage CONSTANT)
 public:
    QString welcomeMessage = "This is MasterController to Major Tom";
    explicit MasterController(QObject* parent = nullptr);
};

}}

#endif  // MASTERCONTROLLER_H
