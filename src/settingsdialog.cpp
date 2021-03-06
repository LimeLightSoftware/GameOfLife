#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    connect(ui->sbCols, SIGNAL(valueChanged(int)), SLOT(slotAnyValuesChanged()));
    connect(ui->sbRows, SIGNAL(valueChanged(int)), SLOT(slotAnyValuesChanged()));
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::setRowsCols(int _row, int _col)
{
    // Задать количество строк/столбцов в форме
    Q_ASSERT(_row <= ui->sbRows->maximum()
             && _row >= ui->sbRows->minimum());
    Q_ASSERT(_col <= ui->sbCols->maximum()
             && _col >= ui->sbCols->minimum());

    ui->sbRows->setValue(_row);
    ui->sbCols->setValue(_col);
}

void SettingsDialog::setCellSize(short _px)
{
    // Задать размер клетки
    Q_ASSERT(_px <= ui->sbCellSize->maximum()
             && _px >= ui->sbCellSize->minimum());

    ui->sbCellSize->setValue(_px);
}

void SettingsDialog::setDelay(short _ms)
{
    // Задать интервал
    Q_ASSERT(_ms <= ui->sbTimerDelay->maximum()
             && _ms >= ui->sbTimerDelay->minimum());

    ui->sbTimerDelay->setValue(_ms);
}

int SettingsDialog::getRows() const
{
    return ui->sbRows->value();
}

int SettingsDialog::getCols() const
{
    return ui->sbCols->value();
}

short SettingsDialog::getCellSize() const
{
    return ui->sbCellSize->value();
}

short SettingsDialog::getDelay() const
{
    return ui->sbTimerDelay->value();
}

void SettingsDialog::showingWrn()
{
    if (ui->sbCols->value() >= WrnCount
            || ui->sbRows->value() >= WrnCount)
        ui->labelWarn->setText(QString(tr("<font color=red>При больших значениях могут<br> "
                                          "возникать подвисания и вылеты приложения.<br> Будьте осторожны</font>")));
    else
        ui->labelWarn->setText("");
}

void SettingsDialog::slotAnyValuesChanged()
{
    // Если любое из двух spinbox изменено
    showingWrn();
}
