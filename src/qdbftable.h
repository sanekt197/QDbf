#ifndef QDBFTABLE_H
#define QDBFTABLE_H

#include "qdbf_global.h"

QT_BEGIN_NAMESPACE
class QVariant;
QT_END_NAMESPACE

namespace QDbf {
namespace Internal {

class QDbfTablePrivate;

} // namespace Internal

class QDbfRecord;

class QDBF_EXPORT QDbfTable
{
public:
    enum Codepage {
        UnknownCodepage = -1,
        CodepageNotSet  = 0,
        IBM866,
        Windows1251
    };

    enum OpenMode {
        ReadOnly,
        ReadWrite
    };

    QDbfTable();
    explicit QDbfTable(const QString &dbfFileName);
    QDbfTable(const QDbfTable &other);
    bool operator==(const QDbfTable &other) const;
    inline bool operator!=(const QDbfTable &other) const { return !operator==(other); }
    QDbfTable &operator=(const QDbfTable &other);
    ~QDbfTable();

    bool open(const QString &fileName, OpenMode openMode = QDbfTable::ReadOnly);
    bool open(OpenMode openMode = QDbfTable::ReadOnly);
    void close();

    QString fileName() const;

    QDbfTable::OpenMode openMode() const;

    bool setCodepage(QDbfTable::Codepage codepage);
    QDbfTable::Codepage codepage() const;

    bool isOpen() const;
    int size() const;
    int at() const;
    bool previous() const;
    bool next() const;
    bool first() const;
    bool last() const;
    bool seek(int index) const;
    QDbfRecord record() const;
    QVariant value(int index) const;

    bool addRecord() const;
    bool addRecord(const QDbfRecord &record) const;
    bool updateRecordInTable(const QDbfRecord &record) const;
    bool removeRecord(int index) const;

private:
    Internal::QDbfTablePrivate *d;
};

} // namespace QDbf

QDebug operator<<(QDebug, const QDbf::QDbfTable&);

#endif // QDBFTABLE_H
