#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    stdPassLabel.setText("Minimum 5 characters & no spaces");
    significantDigitLabel.setText("Exactly 5 characters & the third character is either number / letter");
    noLeadingZeroLabel.setText("Between 4 & 6 digits, not starting with 0");
    stdPassCheck.setChecked(false);
    significantDigitCheck.setChecked(false);
    noLeadingZeroCheck.setChecked(false);
    userIn.clear();
    validateBtn.setText("VALIDATE");
    validateBtn.setDisabled(true);
    btnGroup.addButton(&stdPassCheck, 0);
    btnGroup.addButton(&significantDigitCheck, 1);
    btnGroup.addButton(&noLeadingZeroCheck, 2);
    stdPassLayout.addWidget(&stdPassCheck);
    stdPassLayout.addWidget(&stdPassLabel);
    significantDigitLayout.addWidget(&significantDigitCheck);
    significantDigitLayout.addWidget(&significantDigitLabel);
    noLeadingZeroLayout.addWidget(&noLeadingZeroCheck);
    noLeadingZeroLayout.addWidget(&noLeadingZeroLabel);
    userInputLayout.addWidget(&userIn);
    userInputLayout.addWidget(&validateBtn);
    mainLayout.addLayout(&stdPassLayout);
    mainLayout.addLayout(&significantDigitLayout);
    mainLayout.addLayout(&noLeadingZeroLayout);
    mainLayout.addLayout(&userInputLayout);
    central.setLayout(&mainLayout);
    setCentralWidget(&central);

    connect(&validateBtn, &QPushButton::clicked, this, &MainWindow::validate);
}

MainWindow::~MainWindow() {}

void MainWindow::validate() {
    /*
     * Which checkbox, id?
     * Invoke appropriate method to validate.
     * Display QMessage after
     */
}
