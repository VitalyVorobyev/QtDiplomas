#ifndef STRINGDECORATOR_H
#define STRINGDECORATOR_H

#include <QJsonObject>
#include <QJsonValue>
#include <QObject>
#include <QScopedPointer>
#include <QString>

#include <cm2-lib_global.h>
#include <datadecorator.h>

namespace cm2 {
namespace data {

class CM2LIB_EXPORT StringDecorator: public DataDecorator {
    Q_OBJECT
    Q_PROPERTY(QString ui_value READ value WRITE setValue NOTIFY valueChanged)

public:
    StringDecorator(Entity* parentEntoty=nullptr, const QString& key="SomeItemKey",
                    const QString& label="", const QString& value="");
    ~StringDecorator();

    StringDecorator& setValue(const QString& value);
    const QString& value() const;

    QJsonValue jsonValue() const override;
    void update(const QJsonObject& jsonObject) override;

signals:
    void valueChanged();

private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};

}}

#endif // STRINGDECORATOR_H
