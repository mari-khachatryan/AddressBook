#include "adddialog.h"

#include <QtWidgets>

AddDialog::AddDialog(QWidget *parent)
    : QDialog(parent),
      nameText(new QLineEdit),
      addressText(new QTextEdit),
      emailText(new QLineEdit),
      phoneText(new QLineEdit)
{
    auto nameLabel = new QLabel(tr("Name"));
    auto addressLabel = new QLabel(tr("Address"));
    auto emailLabel = new QLabel(tr("Email"));
    auto phoneLabel = new QLabel(tr("Phone"));
    auto okButton = new QPushButton(tr("OK"));
    auto cancelButton = new QPushButton(tr("Cancel"));

    auto gLayout = new QGridLayout;
    gLayout->setColumnStretch(1, 2);
    gLayout->addWidget(nameLabel, 0, 0);
    gLayout->addWidget(nameText, 0, 1);


    gLayout->addWidget(emailLabel, 1, 0);
    gLayout->addWidget(emailText, 1, 1);

    gLayout->addWidget(phoneLabel, 2, 0);
    gLayout->addWidget(phoneText, 2, 1);

    gLayout->addWidget(addressLabel, 3, 0, Qt::AlignLeft|Qt::AlignTop);
    gLayout->addWidget(addressText, 3, 1, Qt::AlignLeft);

    auto buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    gLayout->addLayout(buttonLayout, 3, 1, Qt::AlignRight|Qt::AlignCenter);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gLayout);
    setLayout(mainLayout);

    connect(okButton, &QAbstractButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);

    setWindowTitle(tr("Add a Contact"));
}


QString AddDialog::name() const
{
    return nameText->text();
}

QString AddDialog::address() const
{
    return addressText->toPlainText();
}

QString AddDialog::email() const
{
    return emailText->text();
}

QString AddDialog::phone() const
{
    return phoneText->text();
}



void AddDialog::editAddress(const QString &name, const QString &address, const QString &email, const QString &phone)
{
    nameText->setReadOnly(true);
    nameText->setText(name);
    addressText->setPlainText(address);
    emailText->setText(email);
    phoneText->setText(phone);
}
