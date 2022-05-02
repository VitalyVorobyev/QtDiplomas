#ifndef COMMANDCONTROLLER_H
#define COMMANDCONTROLLER_H

#include <QObject>
#include <QtQml/QQmlListProperty>

#include <cm2-lib_global.h>
#include <command.h>

namespace cm2 {
namespace controllers {


class CM2LIB_EXPORT CommandController : public QObject {
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<cm2::framework::Command> ui_createClientViewContextCommands
               READ createClientViewContextCommands CONSTANT)
public:
    explicit CommandController(QObject* _parent=nullptr);
    ~CommandController();

    QQmlListProperty<framework::Command> createClientViewContextCommands();

public slots:
    void onCreateClientSaveExecuted();

private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};


}}

#endif // COMMANDCONTROLLER_H
