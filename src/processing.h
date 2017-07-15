//
// Класс механики игры
//

#ifndef PROCESSING_H
#define PROCESSING_H

#include <QObject>
#include "lifescene.h"
#include "lifematrix.h"

class Processing : public QObject
{
    Q_OBJECT
public:
    explicit Processing(ushort width, ushort height, short cellWidth, QObject *parent = nullptr);
    ~Processing();

    // Получение сцены (для GraphicsView)
    //! используется только для задания сцены QGraphicsView и нигде больше!
    LifeScene* getScene() const { return m_scene; }

    // Слот для вычисления одного шага
    void solveOneStep();

    // Очистка поля (но не удаление элементов)
    void clearField();

private:
    // Матрицы текущего и следующего поколения
    LifeMatrix m_currentGeneration;
    LifeMatrix m_nextGeneration;

    // Сцена
    LifeScene *m_scene;

    // Вычисление след.поколения
    void solveNextGen();

    void allocMatrix();

    // Специальный флаг, означающий, нужно ли перед просчетом поколения
    // считывать сцену (если одиночный просчет)
    bool needFromSceneMode;

signals:
    // Сигнал при окончании игры. Если вычисленное поколение равно текущему
    void sigGameOver();
    // Сигнал при каждой итерации. [количество живых клеток]
    void sigGenIteration(uint aliveCellsCount);

public slots:
};

#endif // PROCESSING_H
