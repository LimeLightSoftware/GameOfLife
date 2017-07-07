//
// Сцена для отрисовки клеток
//

#ifndef LIFESCENE_H
#define LIFESCENE_H

#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QDebug>

#include "lifecell.h"

class LifeScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit LifeScene(ushort width, ushort height, QObject *parent = nullptr);

    // Загрузка размеров поля и клеток
    void    setField(size_t row, size_t col, unsigned short cellWidth);
    void    setCellSize(ushort width);

    void    draw();

private:
    // максимальный размер клетки
    static const ushort MaxSizeOfCell = 100;

    // Количество ячеек (ряды/столбцы)
    size_t rowCount;    // Количество рядов из клеток
    size_t colCount;    // Количество столбцов из клеток
    short  cellSize;    // Длинна стороны клетки

    // Размер сцены
    int sceneWidth;
    int sceneHeight;

    // Рисовка клеток
    QGraphicsItemGroup *m_itemGroup;    // группа клеток (для удобства изменений)

signals:

public slots:
};

#endif // LIFESCENE_H
