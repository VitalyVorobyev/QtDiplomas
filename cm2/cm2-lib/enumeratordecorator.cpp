#include "enumeratordecorator.h"

namespace cm2 {
namespace data {

class EnumeratorDecorator::Implementation {
public:
    Implementation(EnumeratorDecorator* _stringDecorator, int _value,
                   const std::map<int, QString>& _descriptionMapper):
       stringDecorator(_stringDecorator), value(_value),
       descriptionMapper(_descriptionMapper) {}

    EnumeratorDecorator* stringDecorator{nullptr};
    int value;
    std::map<int, QString> descriptionMapper;
};

EnumeratorDecorator::EnumeratorDecorator(Entity* parentEntity, const QString& key,
                                         const QString& label, int value,
                                         const std::map<int, QString>& descriptionMapper):
    DataDecorator(parentEntity, key, label)
{
    implementation.reset(new Implementation(this, value, descriptionMapper));
}

EnumeratorDecorator::~EnumeratorDecorator() {}

int EnumeratorDecorator::value() const {
    return implementation->value;
}

EnumeratorDecorator& EnumeratorDecorator::setValue(int value) {
    if (value != implementation->value) {
        // TODO: validation
        implementation->value = value;
        emit valueChanged();
    }
    return *this;
}

QString EnumeratorDecorator::valueDescription() const {
    if (auto it = implementation->descriptionMapper.find(implementation->value);
        it != implementation->descriptionMapper.end())
        return it->second;
    return {};
}

QJsonValue EnumeratorDecorator::jsonValue() const {
    return QJsonValue::fromVariant(QVariant(implementation->value));
}

void EnumeratorDecorator::update(const QJsonObject& _jsonObject) {
    if (_jsonObject.contains(key())) {
        setValue(_jsonObject.value(key()).toInt());
    } else {
        setValue(0);
    }
}

}}
