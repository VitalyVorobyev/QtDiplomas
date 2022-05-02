#include "entity.h"

#include <QJsonArray>

namespace cm2 {
namespace data {

class Entity::Implementation {
public:
    Implementation(Entity* _entity, const QString& _key):
        entity(_entity), key(_key) {}
    Entity* entity{nullptr};
    QString key;
    std::map<QString, Entity*> childEntities;
    std::map<QString, DataDecorator*> dataDecorators;
    std::map<QString, EntityCollectionBase*> childCollections;
};

Entity::Entity(QObject* parent, const QString& key) : QObject(parent) {
    implementation.reset(new Implementation(this, key));
}

Entity::Entity(QObject* parent, const QString& key, const QJsonObject& jsonObject):
    Entity(parent,key) {
    update(jsonObject);
}

Entity::~Entity() {}

const QString& Entity::key() const {
    return implementation->key;
}

Entity* Entity::addChild(Entity *entity, const QString &key) {
    if (implementation->childEntities.find(key) ==
            implementation->childEntities.end()) {
        implementation->childEntities[key] = entity;
        emit childEntitiesChanged();
    }
    return entity;
}

DataDecorator* Entity::addDataItem(DataDecorator *dataDecorator) {
    if (implementation->dataDecorators.find(dataDecorator->key()) ==
            implementation->dataDecorators.end()) {
        implementation->dataDecorators[dataDecorator->key()] = dataDecorator;
        emit dataDecoratorsChanged();
    }
    return dataDecorator;
}

void Entity::update(const QJsonObject& jsonObject) {
    for (auto& [key, dataDec] : implementation->dataDecorators) {
        dataDec->update(jsonObject);
    }

    for (auto& [key, chldEntity] : implementation->childEntities) {
        chldEntity->update(jsonObject.value(key).toObject());
    }

    for (auto& [key, value] : implementation->childCollections) {
        value->update(jsonObject.value(key).toArray());
    }
}

QJsonObject Entity::toJson() const {
    QJsonObject returnValue;
    for (const auto& [key, value] : implementation->dataDecorators) {
        returnValue.insert(key, value->jsonValue());
    }
    for (const auto& [key, value] : implementation->childEntities) {
        returnValue.insert(key, value->toJson());
    }
    for (const auto& [key, chldColl] : implementation->childCollections) {
        QJsonArray entityArray;
        for (Entity* entity: chldColl->baseEntities()) {
            entityArray.append(entity->toJson());
        }
        returnValue.insert(key, entityArray);
    }
    return returnValue;
}

EntityCollectionBase* Entity::addChildCollection(
        EntityCollectionBase* entityCollection) {
    if (implementation->childCollections.find(entityCollection->getKey()) ==
            std::end(implementation->childCollections)) {
        implementation->childCollections[entityCollection->getKey()] = entityCollection;
        emit childCollectionsChanged(entityCollection->getKey());
    }
    return entityCollection;
}

}}
