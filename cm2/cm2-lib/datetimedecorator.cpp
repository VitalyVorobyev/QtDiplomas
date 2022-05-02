#include "datetimedecorator.h"

namespace cm2 {
namespace data {

class DateTimeDecorator::Implementation {
public:
    Implementation(DateTimeDecorator* _stringDecorator, const QDateTime& _value):
       stringDecorator(_stringDecorator), value(_value) {}

    DateTimeDecorator* stringDecorator{nullptr};
    QDateTime value;
};

DateTimeDecorator::DateTimeDecorator(Entity* parentEntity, const QString& key,
                                 const QString& label, const QDateTime& value):
    DataDecorator(parentEntity, key, label)
{
    implementation.reset(new Implementation(this, value));
}

DateTimeDecorator::~DateTimeDecorator() {}

const QDateTime& DateTimeDecorator::value() const {
    return implementation->value;
}

DateTimeDecorator& DateTimeDecorator::setValue(const QDateTime& value) {
    if (value != implementation->value) {
        // TODO: validation
        implementation->value = value;
        emit valueChanged();
    }
    return *this;
}

QJsonValue DateTimeDecorator::jsonValue() const {
    return QJsonValue::fromVariant(QVariant(implementation->value));
}

void DateTimeDecorator::update(const QJsonObject& _jsonObject) {
    if (_jsonObject.contains(key())) {
        setValue(QDateTime::fromString(_jsonObject.value(key()).toString()));
    } else {
        setValue(QDateTime());
    }
}

QString DateTimeDecorator::toIso8601String() const {
    if (implementation->value.isNull()) return "";
    return implementation->value.toString(Qt::ISODate);
}

QString DateTimeDecorator::toPrettyDateString() const {
    if (implementation->value.isNull()) return "Not set";
    return implementation->value.toString("d MMM yyyy");
}

QString DateTimeDecorator::toPrettyTimeString() const {
    if (implementation->value.isNull()) return "Not set";
    return implementation->value.toString("hh:mm ap");
}

QString DateTimeDecorator::toPrettyString() const {
    if (implementation->value.isNull()) return "Not set";
    return implementation->value.toString("ddd d MMM yyyy @ HH:mm:ss");
}

}}
