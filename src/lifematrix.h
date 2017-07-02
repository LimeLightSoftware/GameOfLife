//
// Класс для описания матрицы, вычисления соседей и т.д.
//

#ifndef LIFEMATRIX_H
#define LIFEMATRIX_H

#include <QObject>
#include <QDebug>

class LifeMatrix : public QObject
{
    Q_OBJECT
public:
    explicit LifeMatrix(QObject *parent = nullptr);
    ~LifeMatrix();

    // Выделение памяти под массив
    void allocate(size_t rowCount, size_t columnCount);
    // Заново создаем массив (изменяем размер, только всё с нуля)
    void reallocate(size_t horizontalCount, size_t verticalCount);

    // Перегрузки операторов
    bool operator ==(const LifeMatrix &mtrx);

private:
    // Матрица, собственно
    bool    **m_matrix;

    // Текущее количество клеток
    size_t  countCol;
    size_t  countRow;

    // Заполнение массива нулями / очистка
    void fillZero();
    // Удаление массива
    void deleteMatrix();


signals:

public slots:
};

#endif // LIFEMATRIX_H