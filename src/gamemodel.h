#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QAbstractListModel>
#include "game.h"

class GameModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(int score READ currentScore NOTIFY scoreChanged)
public:
    GameModel(QObject* parent = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    Q_INVOKABLE void moveUp();
    Q_INVOKABLE void moveDown();
    Q_INVOKABLE void moveLeft();
    Q_INVOKABLE void moveRight();

    int currentScore() const { return m_game.currentScore(); }
signals:
    void scoreChanged();

public slots:
    void ondataChanged();
private:
    Game m_game;
};

#endif //GAMEMODEL_H
