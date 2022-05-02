#ifndef COMMAND_H
#define COMMAND_H

#include <functional>

#include <QObject>
#include <QScopedPointer>
#include <QString>

#include <cm2-lib_global.h>

namespace cm2 {
namespace framework {

class CM2LIB_EXPORT Command : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString ui_iconCharacter READ iconCharacter CONSTANT)
    Q_PROPERTY(QString ui_description READ description CONSTANT)
    Q_PROPERTY(bool ui_canExecute READ canExecute NOTIFY canExecuteChanged)

    class Implementation;
    QScopedPointer<Implementation> implementation;

 public:
    explicit Command(QObject* parent=nullptr,
                     const QString& iconCharacter="",
                     const QString& description="",
                     std::function<bool()> canExecute=[](){return true;});
    ~Command();

    const QString& iconCharacter() const;
    const QString& description() const;
    bool canExecute() const;

 signals:
    void canExecuteChanged();
    void executed();
};

}}

#endif // COMMAND_H
