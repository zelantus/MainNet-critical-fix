// Copyright (c) 2011-2014 The Bitcoin Core developers
// Copyright (c) 2017-2019 The Zelantus Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef RAVEN_QT_RAVENADDRESSVALIDATOR_H
#define RAVEN_QT_RAVENADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class ZelantusAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit ZelantusAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Zelantus address widget validator, checks for a valid zelantus address.
 */
class ZelantusAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit ZelantusAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // RAVEN_QT_RAVENADDRESSVALIDATOR_H
