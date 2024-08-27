#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "password.h"
#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QButtonGroup>
#include <QMessageBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void validate();
private:
    void displayResult(bool b);
    void refreshUi();
    QPushButton validateBtn;
    QLineEdit userIn;
    QWidget central;
    QVBoxLayout mainLayout;
    QHBoxLayout stdPassLayout;
    QHBoxLayout significantDigitLayout;
    QHBoxLayout noLeadingZeroLayout;
    QHBoxLayout userInputLayout;
    QButtonGroup btnGroup;
    QCheckBox stdPassCheck;
    QCheckBox significantDigitCheck;
    QCheckBox noLeadingZeroCheck;
    QLabel stdPassLabel;
    QLabel significantDigitLabel;
    QLabel noLeadingZeroLabel;
    QMessageBox msgBox;
    Password pass;
    bool valid;
};
#endif // MAINWINDOW_H
